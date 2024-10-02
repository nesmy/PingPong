#include "Application.h"
#include "Menu.h"
#include "Pong.h"
#include "ResourceManager.h"
#include "Setting.h"

using namespace BB;

int main(void){
  int retVal = EXIT_SUCCESS;
  Application<MenuScene> App;
  
  ResourceManager::LoadScene<Pong>(2);
  ResourceManager::GetScene(2)->loadResources();
  ResourceManager::LoadScene<MenuScene>(1);
  ResourceManager::LoadScene<SettingScene>(3);

  try{
    App.RunLoop();
  }
  catch(std::runtime_error &e){
    showErrorAndExit(e.what());
    retVal = EXIT_FAILURE;
  }
  
  return retVal;
}
