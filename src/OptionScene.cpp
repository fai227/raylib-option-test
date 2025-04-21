#include "OptionScene.h"
#include "raygui.h"

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
        // Handle Resolution Dropdown
        if (GuiDropdownBox(resolutionDropdownRect, resolutionOptions.c_str(), &resolutionIndex, resolutionDropdownActive))
        {
            resolutionDropdownActive = !resolutionDropdownActive; // Toggle active state
        }
        if (!resolutionDropdownActive)
        {
            SetWindowSize(resolutions[resolutionIndex].first, resolutions[resolutionIndex].second);
            RecalculateUILayout(); // Recalculate UI layout after resolution change
        }

        // Handle Max Framerate Spinner
        GuiSpinner(framerateSpinnerRect, "Max FPS", &maxFramerate, 10, 240, framerateSpinnerActive);
        if (!framerateSpinnerActive)
        {
            SetTargetFPS(maxFramerate);
        }
    }
}

// Recalculate UI element sizes and positions based on the current resolution
void OptionScene::RecalculateUILayout()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Example: Adjust tab rectangles
    generalTabRect = {10, 10, screenWidth / 4.0f, 50};
    controlTabRect = {screenWidth / 4.0f + 20, 10, screenWidth / 4.0f, 50};

    // Example: Adjust dropdown and spinner positions
    resolutionDropdownRect = {100, 150, screenWidth / 3.0f, 30};
    framerateSpinnerRect = {100, 200, screenWidth / 3.0f, 30};
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
        GuiDropdownBox(resolutionDropdownRect, resolutionOptions.c_str(), &resolutionIndex, resolutionDropdownActive);

        DrawText("Max Framerate", 100, 200, 20, DARKGRAY);
        GuiSpinner(framerateSpinnerRect, "Max FPS", &maxFramerate, 10, 240, framerateSpinnerActive);
    }
    else if (selectedTab == Tab::Control)
    {
        DrawText("Sensitivity", 100, 150, 20, DARKGRAY);
        DrawText("Presets", 100, 200, 20, DARKGRAY);
    }
}
