#include "raylib.h"

int main()
{
	// Initialization
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Gen AI");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		BeginDrawing();

		DrawCircle(400, 225, 50, RED);

		EndDrawing();

	}

	return 0;

}