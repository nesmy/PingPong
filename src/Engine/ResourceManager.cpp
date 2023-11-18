#include "enpch.h"
#include "ResourceManager.h"

#include "stb_image.h"
#include <iostream>

namespace Engine {

    // Instantiate static variables
    std::map<std::string, Texture2D>    ResourceManager::Textures;
    std::map<std::string, Shader>       ResourceManager::Shaders;

    ShaderProgramSource ResourceManager::ParseShader(const std::string& filepath)
    {
        std::ifstream stream(filepath);

        enum class ShaderType
        {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };

        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        while (getline(stream, line))
        {
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
            {
                ss[(int)type] << line << '\n';
            }
        }
        return { ss[0].str(), ss[1].str() };
    }

    Shader ResourceManager::LoadShader(const std::string& filepath, const char* gShaderFile, std::string name)
    {

        Shaders[name] = loadShaderFromFile(filepath, gShaderFile);
        return Shaders[name];
    }

    Shader ResourceManager::GetShader(std::string name)
    {
        return Shaders[name];
    }

    Texture2D ResourceManager::LoadTexture(const char* file, bool alpha, std::string name)
    {
        Textures[name] = loadTextureFromFile(file, alpha);
        return Textures[name];
    }

    Texture2D ResourceManager::GetTexture(std::string name)
    {
        return Textures[name];
    }

    void ResourceManager::Clear()
    {
        // (properly) delete all shaders	
        for (auto iter : Shaders)
            glDeleteProgram(iter.second.ID);
        // (properly) delete all textures
        for (auto iter : Textures)
            glDeleteTextures(1, &iter.second.ID);
    }

    Shader ResourceManager::loadShaderFromFile(const std::string& filepath, const char* gShaderFile)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        /*
        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        try
        {
            // open files
            std::ifstream vertexShaderFile(vShaderFile);
            std::ifstream fragmentShaderFile(fShaderFile);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();
            // close file handlers
            vertexShaderFile.close();
            fragmentShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
            // if geometry shader path is present, also load a geometry shader
            if (gShaderFile != nullptr)
            {
                std::ifstream geometryShaderFile(gShaderFile);
                std::stringstream gShaderStream;
                gShaderStream << geometryShaderFile.rdbuf();
                geometryShaderFile.close();
                geometryCode = gShaderStream.str();
            }
        }
        catch (std::exception e)
        {
            std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
        }
      
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        const char* gShaderCode = geometryCode.c_str();
        */

        ShaderProgramSource source = ParseShader(filepath);

        const char* vsource = source.VertexSource.c_str();
        const char* fsource = source.FragmentSource.c_str();
        const char* gsource = nullptr;
        // 2. now create shader object from source code
        Shader shader;
        shader.Compile(vsource, fsource, gShaderFile != nullptr ? gsource : nullptr);
        return shader;
    }

    Texture2D ResourceManager::loadTextureFromFile(const char* file, bool alpha)
    {
        // create texture object
        Texture2D texture;
        if (alpha)
        {
            texture.Internal_Format = GL_RGBA;
            texture.Image_Format = GL_RGBA;
        }
        // load image
        int width, height, nrChannels;
        unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
        // now generate texture
        texture.Generate(width, height, data);
        // and finally free image data
        stbi_image_free(data);
        return texture;
    }
}