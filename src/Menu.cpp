#include "Menu.h"
#include "ResourceManager.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

std::shared_ptr<BB::Scene> MenuScene::update(){
    if(startClicked){
      startClicked =false;
      return BB::ResourceManager::GetScene(2);
    }else if(settingClicked){
      settingClicked = false;
      return BB::ResourceManager::GetScene(3);
    }
    else {
      return nullptr;
    }
  }

void MenuScene::Draw(){
    BB::Scene::Draw();

    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Pong";
    Font titleFont = GetFontDefault();
    Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING);

    int titleLeft = (sceneWidth - titleDim.x) / 2;
    int titleTop = sceneHeight / 4 - titleDim.y / 2;
    Vector2 titlePos = Vector2{(float)titleLeft, (float)titleTop};
    ::DrawTextEx(titleFont, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);

    int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
    int menuTop = sceneHeight / 2;
    float currX = (float)menuLeft;
    float currY = (float)menuTop;

    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
    GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Start Game")){
      startClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Setting")){
      settingClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Quit")){
      quit = true;
    }
  }