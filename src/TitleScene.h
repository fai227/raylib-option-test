#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "scene.h"
#include "raylib.h"
#include <string>
#include <memory>

class TitleScene : public Scene
{
private:
    Rectangle button;
    std::string buttonText;
    bool buttonHovered;
    std::unique_ptr<Scene> &currentScene;

public:
    TitleScene(std::unique_ptr<Scene> &sceneRef);
    void Update() override;
    void Draw() override;
};

#endif // TITLE_SCENE_H
