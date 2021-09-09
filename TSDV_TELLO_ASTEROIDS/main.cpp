#include <iostream>
#include "raylib.h"


void main()
{

	std::cout << "Hello World";

	InitWindow(400, 400, "Blasteroids");
	SetTargetFPS(60);

	do
	{
		ClearBackground(DARKGRAY);

		BeginDrawing();
		DrawCircle(50, 50, 10, RED);
		EndDrawing();

	} while (!WindowShouldClose());
	CloseWindow();
}