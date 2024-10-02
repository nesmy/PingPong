#pragma once
#include "Config.h"

namespace BB {
  class Object;
  class Scene;
  class ResourceManager {
  public:
    //resouce storage
    static std::map<std::string, Texture2D> Textures;
    static std::vector<Object*> Objects;
    static std::map<int, std::shared_ptr<Scene>> Scenes; 
    // loads texture from file
    static Texture2D LoadTexture(const char* file, std::string name);
    // retrieves a stored texture
    static Texture2D GetTexture(std::string name);

    static void AddObject(Object* object);
    static std::vector<Object*> GetObjects();

    //Load Scene
    template<class T>
    static std::shared_ptr<Scene> LoadScene(int order){
      Scenes[order] = std::make_unique<T>();
      return Scenes[order];
    }
    // Retrieves a stored scene
    static std::shared_ptr<Scene> GetScene(int order){
      return Scenes[order];
    }
    
    // properly de-allocates all loaded resources
    static void Clear();
  private:
    ResourceManager() {}
  };
  
    }
