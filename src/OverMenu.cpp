#include "OverMenu.h"
#include "ResourceManager.h"

OverMenuScene::OverMenuScene(){
    restartClicked = false;
    quit = false;
    // Over = LoadSound("Resources/Sound/over.mp3");
  }

std::shared_ptr<BB::Scene> OverMenuScene::update(){
    if(restartClicked){
      restartClicked =false;
      BB::ResourceManager::GetScene("Game")->freeResources();
      BB::ResourceManager::GetScene("Game")->loadResources();      
      return BB::ResourceManager::GetScene("Main");
    }else {
      return nullptr;
    }
  }

void OverMenuScene::Draw(){
    BB::Scene::Draw();
    // PlaySound(Over);
    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Game Over";
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
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Restart")){
      restartClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Quit")){
      quit = true;
    }
  }
