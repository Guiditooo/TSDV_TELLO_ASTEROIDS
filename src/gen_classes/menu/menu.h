#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include <vector>
#include "gen_classes/generic.h"

enum class SortType
{
	ALPHABETH_ASC,
	ALPHABETH_DES,
	NONE
};

class MenuManager
{
private:
	std::vector<Button> buttons;
	Quad rec;
	Dimentions dim;
	Offset offset;
	Vec2 pos;
	int separation;
	void SwapButtons(int index1, int index2);
public:
	MenuManager();
	MenuManager(Dimentions d, Offset off, Vec2 p);
	~MenuManager();
	Vec2 GetPosition();
	Dimentions GetDimentions();
	void SetDimentions(Dimentions d);
	void SetPosition(Vec2 p);
	void SetOffset(Offset off);
	void SetSeparation(int sep);
	void AddButton(Button button);
	void PopButton(int index);
	void SortButtons(SortType sort);
	void StartMenu();
};


#endif
