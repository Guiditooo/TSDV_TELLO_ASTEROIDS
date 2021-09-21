#include <iostream>
#include "raylib.h"
#include "gen_classes/generic.h"

void main()
{

	std::cout << "Hello World";

	InitWindow(400, 400, "Blasteroids");
	//LoadFont("")
	SetTargetFPS(60);

	Button b = Button();


	do
	{
		ClearBackground(DARKGRAY);
		BeginDrawing();
		b.Draw();
		EndDrawing();

	} while (!WindowShouldClose());
	CloseWindow();
}