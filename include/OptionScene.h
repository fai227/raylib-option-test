#ifndef OPTION_SCENE_H
#define OPTION_SCENE_H

#include "scene.h"
#include "raylib.h"
#include "raygui.h"
#include <vector>
#include <utility>
#include <string>

class OptionScene : public Scene
{
public:
    void Update() override;
    void Draw() override;

private:
    enum class Tab
    {
        General,
        Control
    };
    Tab selectedTab = Tab::General;

    Rectangle generalTabRect = {50, 50, 100, 40};
    Rectangle controlTabRect = {160, 50, 100, 40};

    // Resolution Dropdown
    std::vector<std::pair<int, int>> resolutions = {{800, 600}, {1024, 768}, {1280, 720}, {1920, 1080}};
    std::string resolutionOptions = "800x600;1024x768;1280x720;1920x1080";
    int resolutionIndex = 0;
    Rectangle resolutionDropdownRect = {300, 145, 200, 30};
    bool resolutionDropdownActive = false;

    // Max Framerate Spinner
    int maxFramerate = 60;
    Rectangle framerateSpinnerRect = {300, 195, 125, 30};
    bool framerateSpinnerActive = false;

    // Method to recalculate UI layout
    void RecalculateUILayout();
};

#endif // OPTION_SCENE_H
