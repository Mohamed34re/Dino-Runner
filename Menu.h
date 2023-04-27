#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "GUI.h"
#include <vector>
using namespace sf;
using namespace std;

class GUI;   // forward declaration

class Menu
{
private:
	GUI* gUI;
	int mode;
	int x;
	int y;
	int selected;

	vector<RectangleShape*> Rectangles;
	vector<Text*> Texts;


	vector<Sprite*> Characters;
	vector <string> ChoicesNames;
	vector <Text> texts;


public:
	Menu(int X, int Y, vector <string> Choices,GUI* gui);
	Menu(int X, int Y, vector<Sprite*> Characters, GUI* gui);

	void CreateMode1();

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void MouseMoving(int x, int y);

	void RemoveAnySelected();
	void setSelected(int n);
	int getselected();
	~Menu();

};

