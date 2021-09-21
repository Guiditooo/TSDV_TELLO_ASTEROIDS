#include "menu.h"

MenuManager::MenuManager()
{
	rec = Quad();
	dim = Dimentions(0,0);
	offset = Offset(0,0,0,0);
	pos = Vec2(0,0);
	separation = 5;
}
MenuManager::MenuManager(Dimentions d, Offset off, Vec2 p)
{
	rec = Quad();
	dim = d;
	offset = off;
	pos = p;
	separation = 5;
}
MenuManager::~MenuManager() {}
void MenuManager::SetSeparation(int sep)
{
	separation = sep;
}
Vec2 MenuManager::GetPosition()
{
	return pos;
}
Dimentions MenuManager::GetDimentions()
{
	return dim;
}
void MenuManager::SetDimentions(Dimentions d)
{ 
	dim = d;
}
void MenuManager::SetPosition(Vec2 p)
{
	pos = p;
}
void MenuManager::SetOffset(Offset off)
{
	offset = off;
}
void MenuManager::AddButton(Button button)
{
	buttons.push_back(button);
}
void MenuManager::PopButton(int index)
{
	buttons[index].SetActive(false);
}
void MenuManager::SortButtons(SortType sort)
{
	switch (sort)
	{
	case SortType::ALPHABETH_DES:

		break;
	case SortType::ALPHABETH_ASC:
	default:
		
		break;
	}
}
void MenuManager::StartMenu()
{
	
}
void MenuManager::SwapButtons(int index1, int index2)
{
	Button aux = buttons[index2];
	buttons[index2] = buttons[index1];
	buttons[index1] = buttons[index2];
}