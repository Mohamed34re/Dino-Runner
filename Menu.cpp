#include "../HeaderFiles/Menu.h"
#include <SFML/System/String.hpp>


Menu::Menu(int X, int Y, vector<string> Choices,GUI* gui)
{
	mode = 1;
	gUI = gui;
	x = X;
	y = Y;
	ChoicesNames = Choices;
	selected = -1;
}

Menu::Menu(int X, int Y, vector<Sprite*> characters,GUI* gui)
{
	mode = 2;
	gUI = gui;
	x = X;
	y = Y;
	Characters = characters;
	selected = 0;
}

// Show the text on the window
void Menu::CreateMode1()
{
	int displacement = 0;
	for (int i = 0; i < ChoicesNames.size(); i++)
	{
		RectangleShape* rect = gUI->GetRectangle(200, 50, Color::Blue, x, y + displacement, 0, Color::White);
		Text* txt = gUI->GetText(ChoicesNames[i], nullptr, Color::White, 20, x + 75, y + 10 + displacement);		
		Rectangles.push_back(rect);
		Texts.push_back(txt);
		gUI->AddToRectangles(rect);
		gUI->AddToTexts(txt);
		displacement += 50;
	}
}

void Menu::MoveUp()
{
	if (selected == -1)
	{
		selected++;
		int x;
		int y;
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::Black);
		Texts[selected]->setCharacterSize(30);
		Texts[selected]->setPosition(x - 10, y);
		return;
	}
	if (selected - 1 >= -1)
	{
		int x;
		int y;
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::White);
		Texts[selected]->setCharacterSize(20);
		Texts[selected]->setPosition(x + 10, y);
		selected--;
		if (selected == -1)
			selected = Texts.size() - 1;
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::Black);
		Texts[selected]->setCharacterSize(30);
		Texts[selected]->setPosition(x - 10, y);
	}
}

void Menu::MoveDown()
{
	if (selected == -1)
	{
		selected++;
		int x;
		int y;
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::Black);
		Texts[selected]->setCharacterSize(30);
		Texts[selected]->setPosition(x - 10, y);
		return;
	}
	if (selected + 1 <= Texts.size())
	{
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::White);
		Texts[selected]->setCharacterSize(20);
		Texts[selected]->setPosition(x + 10, y);
		selected++;
		if (selected == Texts.size())
			selected = 0;
		x = Texts[selected]->getPosition().x;
		y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::Black);
		Texts[selected]->setCharacterSize(30);
		Texts[selected]->setPosition(x - 10, y);

	}
}

void Menu::MoveRight()
{
	if (mode == 1)
		return;

}

void Menu::MoveLeft()
{
	if (mode == 1)
		return;

}

void Menu::MouseMoving(int x, int y)
{
	for (int i = 0; i < Rectangles.size(); i++)
	{
		if (x > Rectangles[i]->getPosition().x && x < Rectangles[i]->getPosition().x + Rectangles[i]->getSize().x
			&& y > Rectangles[i]->getPosition().y && y < Rectangles[i]->getPosition().y + Rectangles[i]->getSize().y)
		{
			while (selected != i)
			{
				MoveUp();
			}
			return;
		}
	}
	RemoveAnySelected();
}


void Menu::RemoveAnySelected()
{
	if (selected != -1)
	{
		int x = Texts[selected]->getPosition().x;
		int y = Texts[selected]->getPosition().y;
		Texts[selected]->setFillColor(Color::White);
		Texts[selected]->setCharacterSize(20);
		Texts[selected]->setPosition(x + 10, y);
		selected = -1;
	}
}

void Menu::setSelected(int n)
{
	selected = n;
}

int Menu::getselected()
{
	return selected;
}

Menu::~Menu()
{

}
