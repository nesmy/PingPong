#include "Application.h"
#include "Menu.h"
#include "Pong.h"
#include "ResourceManager.h"
#include "Setting.h"
#include "OverMenu.h"
#include "MainSetting.h"

using namespace BB;

int main(void){
  int retVal = EXIT_SUCCESS;
  Application<MenuScene> App;
  
  ResourceManager::LoadScene<Pong>("Game");
  ResourceManager::GetScene("Game")->loadResources();
  ResourceManager::LoadScene<MenuScene>("Main");
  ResourceManager::LoadScene<SettingScene>("Setting");
  ResourceManager::LoadScene<MainSettingScene>("MainSetting");
  ResourceManager::LoadScene<OverMenuScene>("Over");  

  try{
    App.RunLoop();
  }
  catch(std::runtime_error &e){
    showErrorAndExit(e.what());
    retVal = EXIT_FAILURE;
  }
  
  return retVal;
}
