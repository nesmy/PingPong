#include "Setting.h"

//#define RAYGUI_IMPLEMENTATION
#include "ResourceManager.h"
#include "raygui.h"

std::shared_ptr<BB::Scene> SettingScene::update(){
    if(startClicked){
      startClicked = false;
      return BB::ResourceManager::GetScene(2);
    }else if (restartClicked){
      restartClicked = false;
      BB::ResourceManager::GetScene(2)->freeResources();
      BB::ResourceManager::GetScene(2)->loadResources();
      return BB::ResourceManager::GetScene(1);
    }
    else {
      return nullptr;
    }
}

void SettingScene::Draw(){
    BB::Scene::Draw();

    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Settings";
    Font titleFont = GetFontDefault();
    Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING);

    int titleLeft = (sceneWidth - titleDim.x) / 2;
    int titleTop = sceneHeight / 4 - titleDim.y / 2;
    Vector2 titlePos = Vector2{0, (float)titleTop};
    ::DrawTextEx(titleFont, title, titlePos, SUB_TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);

    int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
    int menuTop = sceneHeight / 2;
    float currX = (float)menuLeft;
    float currY = (float)menuTop;

    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
    GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Resume")){
       startClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Restart")){
      // quit = true;
       restartClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Quit")){
      quit = true;
      //exit = true;
    }
  }
