#include "generic.h"


Quad::Quad()
{
	pos = Vec2(0,0);
	dim.width = 0;
	dim.height = 0;
	thickness = 1;
	color = WHITE;
	lineColor = RED;
}
Quad::~Quad(){}
Vec2 Quad::GetQuadCenter()
{
	Vec2 center = Vec2();
	center.x = pos.x + dim.width / 2;
	center.y = pos.y + dim.height / 2;
	return center;
}
Rectangle Quad::GetRect() 
{
	Rectangle rec = Rectangle();
	rec.x = pos.x;
	rec.y = pos.y;
	rec.width = dim.width;
	rec.height = dim.height;
	return rec;
}
void Quad::DrawQuad()
{
	DrawRectangleRec(this->GetRect(), color);
}
void Quad::DrawQuadLines()
{
	DrawRectangleLinesEx(this->GetRect(), thickness, lineColor);
}
void Quad::DrawQuadWithLines()
{
	DrawQuad();
	DrawQuadLines();
}

Label::Label() 
{
	pos = Vec2(0,0);
	text = "IDLE";
	textSize = 20;
	spacing = 1;
	color = BLACK;
	font = nullptr;
}
Label::~Label(){}
Dimentions Label::GetLabelSize()
{
	Dimentions vec = Dimentions();
	if (font != nullptr) 
	{
		vec = Dimentions(MeasureTextEx(*font, &text[0], textSize, spacing));
	}
	else 
	{
		vec = Dimentions(MeasureText(&text[0], textSize), textSize);
	}
	return vec;
}
void Label::DrawLabel()
{
	if (font != nullptr)
	{
		DrawTextEx(*font, &text[0], pos.ToVector2(), textSize, spacing, color);
	}
	else
	{
		DrawText(&text[0], pos.x, pos.y, textSize, color);
	}
}

TextureX::TextureX()
{
	pos = Vec2(0,0);
	rotation = 0;
	scale = 1;
	color = WHITE;
	tex = Texture2D();
}
TextureX::~TextureX(){}
void TextureX::SetDimentions(Dimentions dim)
{
	tex.width = dim.width;
	tex.height = dim.height;
}
void TextureX::SetDimentions(int width, int height)
{
	tex.width = width;
	tex.height = height;
}
void TextureX::SetDimentions(int quad)
{
	tex.width = quad;
	tex.height = quad;
}
Dimentions TextureX::GetDimentions()
{
	return Dimentions(tex.width, tex.height);
}
void TextureX::SetTexture(Texture2D tx)
{
	tex = tx;
}
Texture2D TextureX::GetTexture()
{
	return tex;
}
void TextureX::Load(std::string path)
{
	tex = LoadTexture(&path[0]);
}
void TextureX::Draw()
{
	DrawTextureEx(tex, pos.ToVector2(), rotation, scale, color);
}

Offset::Offset()
{
	top = 0;
	bot = 0;
	left = 0;
	right = 0;
}
Offset::Offset(int offset)
{
	top = offset;
	bot = offset;
	left = offset;
	right = offset;
}
Offset::Offset(int t, int b, int l, int r)
{
	top = t;
	bot = b;
	left = l;
	right = r;
}
Offset::~Offset() {}

Button::Button()
{
	tex = TextureX();
	hitBox = Quad();
	lab = Label();
	pos = Vec2(0,0);
	dim = Dimentions(0,0);
	CenterText();
	active = true;
}
Button::~Button() {}
void Button::SetTexture(TextureX tx)
{
	tex = tx;
}
TextureX Button::GetTexture()
{
	return tex;
}
void Button::SetActive(bool isActive)
{
	active = isActive;
}
bool Button::Active()
{
	return active;
}
bool Button::IsBeingClicked()
{
	if (IsBeingHovered())
	{
		return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
	}
}
bool Button::IsBeingHovered()
{
	Vector2 mousePos = GetMousePosition();
	return CheckCollisionPointRec(mousePos, hitBox.GetRect());
}
Vec2 Button::GetPosition()
{
	return pos;
}
void Button::SetPosition(Vec2 p)
{
	pos = p;
	tex.pos = pos;
}
void Button::SetPosition(int x, int y)
{
	pos = Vec2(x, y);
	tex.pos = pos;
}
void Button::SetPosition(int rect)
{
	pos = Vec2(rect, rect);
	tex.pos = pos;
}
Dimentions Button::GetDimentions()
{
	return dim;
}
void Button::SetDimentions(Dimentions d)
{
	dim = d;
	tex.SetDimentions(dim);
}
void Button::SetDimentions(int width, int height)
{
	dim.width = width;
	dim.height = height;
	tex.SetDimentions(dim);
}
void Button::SetDimentions(int quad)
{
	dim.width = quad;
	dim.height = quad;
	tex.SetDimentions(dim);
}
void Button::SetLabel(Label l)
{
	lab = l;
	CenterText();
}
void Button::SetLabelText(std::string text)
{
	lab.text = text;
	CenterText();
}
Quad Button::GetHitBox()
{
	return hitBox;
}
void Button::SetHitBox(Quad hb)
{
	hitBox = hb;
}
void Button::SetHitBox(Vec2 p, Dimentions d)
{
	hitBox.pos = p;
	hitBox.dim = d;
}
void Button::SetHitBox(int x, int y, int width, int height)
{
	hitBox.pos.x = x;
	hitBox.pos.y = y;
	hitBox.dim.width = width;
	hitBox.dim.height = height;
}
void Button::AdjustHitBoxToDim()
{
	hitBox.dim = dim;
}
void Button::AdjustHitBoxToPos()
{
	hitBox.pos = pos;
}
void Button::AdjustPosToHitBox()
{
	pos = hitBox.pos;
}
void Button::AdjustDimToHitBox()
{
	dim = hitBox.dim;
}
void Button::Draw()
{
	hitBox.DrawQuadWithLines();
	lab.DrawLabel();
}
void Button::CenterText()
{
	dim = lab.GetLabelSize().ToVec2() * 1.5f;
	lab.pos.x = pos.x + dim.width / 2 - lab.GetLabelSize().width / 2;
	lab.pos.y = pos.y + dim.height / 2 - lab.GetLabelSize().height / 2;
	AdjustHitBoxToDim();
	AdjustHitBoxToPos();
}