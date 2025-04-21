#ifndef OPTION_SCENE_H
#define OPTION_SCENE_H

#include "scene.h"
#include "raylib.h"
#include <vector>
#include <utility>

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

    std::vector<std::pair<int, int>> resolutions = {{800, 600}, {1024, 768}, {1280, 720}, {1920, 1080}};
    int resolutionIndex = 0;

    int maxFramerate = 60;

    // Buttons for Resolution
    Rectangle resolutionLeftButton = {250, 145, 30, 30};
    Rectangle resolutionRightButton = {400, 145, 30, 30};

    // Buttons for Max Framerate
    Rectangle framerateUpButton = {250, 195, 30, 30};
    Rectangle framerateDownButton = {400, 195, 30, 30};
};

#endif // OPTION_SCENE_H
