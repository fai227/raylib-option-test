#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "raylib.h"
#include "Scene.h"
#include "TitleScene.h"

int main()
{
	InitWindow(800, 600, "Scene Example");

	std::unique_ptr<Scene> currentScene = std::make_unique<TitleScene>(currentScene);

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		// Update
		currentScene->Update();

		// Draw
		BeginDrawing();
		currentScene->Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
