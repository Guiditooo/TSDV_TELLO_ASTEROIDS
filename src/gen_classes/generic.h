#ifndef GENERIC_STUFF
#define GENERIC_STUFF

#include <iostream>
#include "vec2/vec2.h"

struct Offset
{
	int top;
	int bot;
	int left;
	int right;
	Offset();
	Offset(int offset);
	Offset(int t, int b, int l, int r);
	~Offset();
};

struct Quad 
{
public:
	Quad();
	~Quad();
	Vec2 pos;
	Dimentions dim;
	int thickness;
	Color color;
	Color lineColor;
	Vec2 GetQuadCenter();
	Rectangle GetRect();
	void DrawQuad();
	void DrawQuadLines();
	void DrawQuadWithLines();
};

struct Label
{
public:
	Label();
	~Label();
	Vec2 pos;
	std::string text;
	int textSize;
	int spacing;
	Color color;
	Font* font = nullptr;
	void DrawLabel();
	Dimentions GetLabelSize();
};

class TextureX
{
private:
	Texture2D tex;
public:
	TextureX();
	~TextureX();
	Vec2 pos;
	int rotation;
	int scale;
	Color color;
	void SetDimentions(Dimentions dim);
	void SetDimentions(int width, int height);
	void SetDimentions(int quad);
	Dimentions GetDimentions();
	void SetTexture(Texture2D tx);
	void Load(std::string path);
	Texture2D GetTexture();
	void Draw();
};

class Button
{
private:
	TextureX tex;
	Quad hitBox;
	Label lab;
	Vec2 pos;
	Dimentions dim;
	bool active;
	void CenterText();
public:
	Button();
	~Button();
	void SetTexture(TextureX tx);
	TextureX GetTexture();
	void SetActive(bool isActive);
	bool Active();
	Vec2 GetPosition();
	void SetPosition(Vec2 p);
	void SetPosition(int x, int y);
	void SetPosition(int rect);
	Dimentions GetDimentions();
	void SetDimentions(Dimentions d);
	void SetDimentions(int width, int height);
	void SetDimentions(int quad);
	void SetLabel(Label l);
	void SetLabelText(std::string text);
	Quad GetHitBox();
	void SetHitBox(Quad hb);
	void SetHitBox(Vec2 p, Dimentions d);
	void SetHitBox(int x, int y, int width, int height);
	void AdjustHitBoxToDim();
	void AdjustHitBoxToPos();
	void AdjustPosToHitBox();
	void AdjustDimToHitBox();
	bool IsBeingClicked();
	bool IsBeingHovered();
	void Draw();
};

#endif // !GENERIC_STUFF
