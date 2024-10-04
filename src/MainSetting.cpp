#include "MainSetting.h"

#include "ResourceManager.h"

std::shared_ptr<BB::Scene> MainSettingScene::update(){
    if(returnClicked){
      returnClicked = false;
      return BB::ResourceManager::GetScene("Main");
    }
    else {
      return nullptr;
    }
}

void MainSettingScene::Draw(){
    BB::Scene::Draw();

    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Main Settings";
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
    if(GuiButton((Rectangle){0, titleDim.y - 10, BUTTON_WIDTH, BUTTON_HEIGHT}, "Return")){
       returnClicked = true;
    }
    
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Easy")){
      // quit = true;
       // restartClicked = true;
      // TO CHANGE
      BB::ResourceManager::GetScene("Game")->easy = true;
      BB::ResourceManager::GetScene("Game")->medium = false;
      BB::ResourceManager::GetScene("Game")->hard = false;
      returnClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Medium")){
      // quit = true;
       // restartClicked = true;
      BB::ResourceManager::GetScene("Game")->easy = false;
      BB::ResourceManager::GetScene("Game")->medium = true;
      BB::ResourceManager::GetScene("Game")->hard = false;
      returnClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){0, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Hard")){
      // quit = true;
       // restartClicked = true;
      BB::ResourceManager::GetScene("Game")->easy = false;
      BB::ResourceManager::GetScene("Game")->medium = false;
      BB::ResourceManager::GetScene("Game")->hard = true;
      returnClicked = true;
    }
    
  }
