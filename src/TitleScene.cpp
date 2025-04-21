#include "TitleScene.h"
#include "OptionScene.h"

TitleScene::TitleScene(std::unique_ptr<Scene> &sceneRef) : currentScene(sceneRef)
{
    button = {GetScreenWidth() / 2.0f - 100, GetScreenHeight() / 2.0f - 25, 200, 50};
    buttonText = "Start";
    buttonHovered = false;
}

void TitleScene::Update()
{
    Vector2 mousePoint = GetMousePosition();
    buttonHovered = CheckCollisionPointRec(mousePoint, button);

    if (buttonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        // Transition to OptionScene
        currentScene = std::make_unique<OptionScene>();
    }
}

void TitleScene::Draw()
{
    ClearBackground(RAYWHITE);

    // Draw button
    DrawRectangleRec(button, buttonHovered ? LIGHTGRAY : GRAY);
    DrawText(buttonText.c_str(), button.x + button.width / 2 - MeasureText(buttonText.c_str(), 20) / 2, button.y + button.height / 2 - 10, 20, buttonHovered ? DARKGRAY : WHITE);

    // Draw title
    DrawText("Title Scene", GetScreenWidth() / 2 - MeasureText("Title Scene", 40) / 2, 100, 40, BLACK);
}
