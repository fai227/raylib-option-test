#include "OptionScene.h"

void OptionScene::Update()
{
    // Handle updates for the Option scene
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, generalTabRect))
        {
            selectedTab = Tab::General;
        }
        else if (CheckCollisionPointRec(mousePos, controlTabRect))
        {
            selectedTab = Tab::Control;
        }
    }

    if (selectedTab == Tab::General)
    {
        Vector2 mousePos = GetMousePosition();

        // Adjust Resolution
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePos, resolutionLeftButton))
            {
                if (resolutionIndex > 0)
                {
                    resolutionIndex--;
                    SetWindowSize(resolutions[resolutionIndex].first, resolutions[resolutionIndex].second);
                }
            }
            else if (CheckCollisionPointRec(mousePos, resolutionRightButton))
            {
                if (resolutionIndex < resolutions.size() - 1)
                {
                    resolutionIndex++;
                    SetWindowSize(resolutions[resolutionIndex].first, resolutions[resolutionIndex].second);
                }
            }

            // Adjust Max Framerate
            if (CheckCollisionPointRec(mousePos, framerateUpButton))
            {
                if (maxFramerate < 240)
                {
                    maxFramerate += 10;
                    SetTargetFPS(maxFramerate);
                }
            }
            else if (CheckCollisionPointRec(mousePos, framerateDownButton))
            {
                if (maxFramerate > 10)
                {
                    maxFramerate -= 10;
                    SetTargetFPS(maxFramerate);
                }
            }
        }
    }
}

void OptionScene::Draw()
{
    ClearBackground(LIGHTGRAY);

    // Draw tabs
    DrawRectangleRec(generalTabRect, selectedTab == Tab::General ? DARKGRAY : GRAY);
    DrawRectangleRec(controlTabRect, selectedTab == Tab::Control ? DARKGRAY : GRAY);
    DrawText("General", generalTabRect.x + 10, generalTabRect.y + 10, 20, WHITE);
    DrawText("Control", controlTabRect.x + 10, controlTabRect.y + 10, 20, WHITE);

    // Draw content based on selected tab
    if (selectedTab == Tab::General)
    {
        DrawText("Resolution", 100, 150, 20, DARKGRAY);
        DrawText(TextFormat("%dx%d", resolutions[resolutionIndex].first, resolutions[resolutionIndex].second), 300, 150, 20, DARKGRAY);

        // Draw Resolution Buttons
        DrawRectangleRec(resolutionLeftButton, GRAY);
        DrawText("<", resolutionLeftButton.x + 10, resolutionLeftButton.y + 5, 20, WHITE);
        DrawRectangleRec(resolutionRightButton, GRAY);
        DrawText(">", resolutionRightButton.x + 10, resolutionRightButton.y + 5, 20, WHITE);

        DrawText("Max Framerate", 100, 200, 20, DARKGRAY);
        DrawText(TextFormat("%d FPS", maxFramerate), 300, 200, 20, DARKGRAY);

        // Draw Framerate Buttons
        DrawRectangleRec(framerateUpButton, GRAY);
        DrawText("+", framerateUpButton.x + 10, framerateUpButton.y + 5, 20, WHITE);
        DrawRectangleRec(framerateDownButton, GRAY);
        DrawText("-", framerateDownButton.x + 10, framerateDownButton.y + 5, 20, WHITE);
    }
    else if (selectedTab == Tab::Control)
    {
        DrawText("Sensitivity", 100, 150, 20, DARKGRAY);
        DrawText("Presets", 100, 200, 20, DARKGRAY);
    }
}
