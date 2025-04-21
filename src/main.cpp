#include "raylib.h"
#include <string>
#include <memory>
#include <vector>

// Base Scene class
class Scene
{
public:
	virtual ~Scene() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

// Option Scene class
class OptionScene : public Scene
{
public:
	void Update() override
	{
		// Handle updates for the Option scene
	}

	void Draw() override
	{
		ClearBackground(LIGHTGRAY);
		DrawText("Option Scene", GetScreenWidth() / 2 - MeasureText("Option Scene", 40) / 2, GetScreenHeight() / 2 - 20, 40, DARKGRAY);
	}
};

// Title Scene class
class TitleScene : public Scene
{
private:
	Rectangle button;
	std::string buttonText;
	bool buttonHovered;
	std::unique_ptr<Scene> &currentScene; // Reference to the current scene pointer

public:
	TitleScene(std::unique_ptr<Scene> &sceneRef) : currentScene(sceneRef)
	{
		button = {GetScreenWidth() / 2.0f - 100, GetScreenHeight() / 2.0f - 25, 200, 50};
		buttonText = "Start";
		buttonHovered = false;
	}

	void Update() override
	{
		Vector2 mousePoint = GetMousePosition();
		buttonHovered = CheckCollisionPointRec(mousePoint, button);

		if (buttonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			// Transition to OptionScene
			currentScene = std::make_unique<OptionScene>();
		}
	}

	void Draw() override
	{
		ClearBackground(RAYWHITE);

		// Draw button
		DrawRectangleRec(button, buttonHovered ? LIGHTGRAY : GRAY);
		DrawText(buttonText.c_str(), button.x + button.width / 2 - MeasureText(buttonText.c_str(), 20) / 2, button.y + button.height / 2 - 10, 20, buttonHovered ? DARKGRAY : WHITE);

		// Draw title
		DrawText("Title Scene", GetScreenWidth() / 2 - MeasureText("Title Scene", 40) / 2, 100, 40, BLACK);
	}
};

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
