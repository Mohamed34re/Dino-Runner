#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "SoundManager.h"
#include "temp.h"
#include <vector>
#include "Menu.h"
using namespace sf;
using namespace std;

class Menu;


class GUI
{
private:
	Music music;
	RenderWindow* window;
	RectangleShape BackGround;
	Menu* menu;

	string sc;
	string charachter;

	vector <RectangleShape*> rectangles;
	vector <Text*> texts;
	vector <Texture*> textures;
	vector <Sprite*> sprites;

	string difficulty;

	Clock clock;

	Font Arial;
	Font Free;
	Font Prstartk;
	Font Zerovelo;
	string CurrentPage;

	void ResetLists();

	void SetLandingPage();
	void RunLandingPage(Event x);

	void SetClickablePage();
	void RunClickablePage(Event x);

	void SetDufficultyPage();
	void RunDufficultyPage(Event x);

	void SetSceneryPage();
	void RunSceneryPage(Event x);

	void SetCharacterPage();
	void RunCharacterPage(Event x);

	void SetHowToPlayPage();
	void RunHowToPlayPage(Event x);

	void SetGamePage();
	void RunGamePage(Event x);

	void SetWindowbackground(string ImageName);

public:
	GUI();


	void RunPage(Event x);
	void DrawPage();
	bool Is_Open();
	bool PollNextEvent(Event& x);
	void ClearWindow();
	bool CloseWindow();

	Text* GetText(string str, Font* fnt, Color clr, int size, int x, int y);
	Texture* GetImage(string ImageName);
	RectangleShape* GetRectangle(int width, int height, Color clr, int x, int y, int BrdSize, Color brd_clr);
	Sprite* GetSprite(Texture& z, int x, int y);

	void AddToRectangles(RectangleShape* rect);
	void AddToSprites(Sprite* spr);
	void AddToTexts(Text* txt);
	void AddToTextures(Texture* texture);
};