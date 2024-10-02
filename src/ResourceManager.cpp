#include "Engine/ResourceManager.h"
#include "raylib.h"

namespace BB {
  // Instantiate static variables
  std::map<std::string, Texture2D> ResourceManager::Textures;
  std::vector<Object*> ResourceManager::Objects;
  std::map<int, std::shared_ptr<Scene>> ResourceManager::Scenes;

  Texture2D ResourceManager::LoadTexture(const char *file, std::string name){
    if(Textures[name].id <= 0){
      Textures[name] = ::LoadTexture(file);
    }
    return Textures[name];
  }


  Texture2D ResourceManager::GetTexture(std::string name){
    return Textures[name];
  }

  void ResourceManager::AddObject(Object* object){
    Objects.emplace_back(object);
  }

  std::vector<Object*> ResourceManager::GetObjects(){
    return Objects;
  }

  void ResourceManager::Clear(){
  }
  
  
}
