#pragma once
#include "../HeaderFiles/GUI.h"

GUI::GUI()
{
	window = new RenderWindow(VideoMode(1200, 800), "Landing", Style::Titlebar | Style::Default);
	BackGround.setSize(Vector2f(1200, 800));

	music.openFromFile("Sounds/intro_sound.ogg");
	music.play();
	music.setVolume(100);
	Arial.loadFromFile("Fonts/arial.ttf");
	Free.loadFromFile("Fonts/Free.ttf");
	Prstartk.loadFromFile("Fonts/prstartk.ttf");
	Zerovelo.loadFromFile("Fonts/zerovelo.ttf");

	CurrentPage = "Landing";
	SetLandingPage();
}

void GUI::ResetLists()
{
	for (int i = 0; i < rectangles.size(); i++)
	{
		delete rectangles[i];
	}
	rectangles.clear();
	for (int i = 0; i < texts.size(); i++)
	{
		delete texts[i];
	}
	texts.clear();
	for (int i = 0; i < textures.size(); i++)
	{
		delete textures[i];
	}
	textures.clear();
	for (int i = 0; i < sprites.size(); i++)
	{
		delete sprites[i];
	}
	sprites.clear();
}
//////////////////////////////////////////////////////////////
void GUI::SetLandingPage()
{
	ResetLists();

	CurrentPage = "Landing";
	window->setTitle("Landing Page");
	cout << "landing";
	rectangles.push_back(GetRectangle(450, 800, Color(193, 255, 0), 0, 0, 0, Color::White));
	rectangles.push_back(GetRectangle(150, 800, Color(255, 0, 0), 450, 0, 0, Color::White));
	rectangles.push_back(GetRectangle(150, 800, Color(255, 180, 0), 600, 0, 0, Color::White));
	rectangles.push_back(GetRectangle(450, 800, Color(0, 120, 255), 750, 0, 0, Color::White));

	texts.push_back(GetText("Press 'Enter' To Continue...", &Prstartk, Color::White, 20, 350, 500));
	texts.push_back(GetText("Dino", &Zerovelo, Color::White, 170, 300, 80));

	sprites.push_back(GetSprite(*GetImage("DinoSprites_0.png"), 300, 400));
	sprites.push_back(GetSprite(*GetImage("DinoSprites_1.png"), 475, 400));
	sprites.push_back(GetSprite(*GetImage("DinoSprites_2.png"), 625, 400));
	sprites.push_back(GetSprite(*GetImage("DinoSprites_3.png"), 800, 400));

	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->setTextureRect(IntRect(0, 0, 24, 24));
		sprites[i]->scale(4,4);
	}
}

void GUI::RunLandingPage(Event x)
{
	if (x.key.code == Keyboard::Enter)
	{
		SetClickablePage();
	}
	else if (x.type == Event::MouseButtonReleased)
	{
		SetClickablePage();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetClickablePage()
{
	ResetLists();

	music.openFromFile("Sounds/main_theme.ogg");
	music.play();
	music.setVolume(20);

	CurrentPage = "Clickable";
	window->setTitle("Clickable Page");
	cout << "clickable";
	SetWindowbackground("Back1.png");

	vector <string> words;
	words.push_back("Play");
	words.push_back("About");
	words.push_back("Credits");
	words.push_back("Exit");

	menu = new Menu(475,240,words,this);
	menu->CreateMode1();

	texts.push_back(GetText("Main Menu:", &Zerovelo, Color::White, 60, 350, 100));

	sprites.push_back(GetSprite(*GetImage("enter.png"), 1100, 700));
	sprites.push_back(GetSprite(*GetImage("up.png"), 1000, 700));
	sprites.push_back(GetSprite(*GetImage("down.png"), 900, 700));
}

void GUI::RunClickablePage(Event x)
{
	if (x.key.code == Keyboard::Enter || x.type == Event::MouseButtonReleased)
	{
		switch (menu->getselected())
		{
			case -1:
			{
				break;
			}
			case 0:
			{
				delete menu;
				menu = nullptr;
				SetDufficultyPage();
				break;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				window->close();
				break;
			}
		}
	}
	else if (x.key.code == Keyboard::Backspace)
	{
		delete menu;
		menu = nullptr;
		SetLandingPage();
	}
	else if (x.type == Event::MouseMoved)
	{
		Vector2i mousePos = Mouse::getPosition(*window);
		menu->MouseMoving(mousePos.x,mousePos.y);
	}
	else if (x.key.code == Keyboard::Up)
	{
		menu->MoveUp();
	}
	else if (x.key.code == Keyboard::Down)
	{
		menu->MoveDown();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetDufficultyPage()
{
	ResetLists();

	CurrentPage = "Dufficulty";
	window->setTitle("Dufficulty Page");

	vector <string> words;
	words.push_back("Easy");
	words.push_back("Medium");
	words.push_back("Hard");

	menu = new Menu(475, 240, words, this);
	menu->CreateMode1();

	cout << "difficulty";
}

void GUI::RunDufficultyPage(Event x)
{
	if (x.key.code == Keyboard::Enter || x.type == Event::MouseButtonReleased)
	{
		switch (menu->getselected())
		{
			case -1:
			{
				break;
			}
			case 0:
			{
				delete menu;
				menu = nullptr;
				difficulty = "Easy";
				SetSceneryPage();
				break;
			}
			case 1:
			{
				delete menu;
				menu = nullptr;
				difficulty = "Medium";
				SetSceneryPage();
				break;
			}
			case 2:
			{
				delete menu;
				menu = nullptr;
				difficulty = "Hard";
				SetSceneryPage();
				break;
			}
		}
		cout << difficulty;
	}
	else if (x.key.code == Keyboard::Backspace)
	{
		delete menu;
		menu = nullptr;
		SetClickablePage();
	}
	else if (x.type == Event::MouseMoved)
	{
		Vector2i mousePos = Mouse::getPosition(*window);
		menu->MouseMoving(mousePos.x, mousePos.y);
	}
	else if (x.key.code == Keyboard::Up)
	{
		menu->MoveUp();
	}
	else if (x.key.code == Keyboard::Down)
	{
		menu->MoveDown();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetSceneryPage()
{
	ResetLists();

	CurrentPage = "Scenery";
	window->setTitle("Scenery Page");
	cout << "Scenery";

	vector <string> words;
	words.push_back("City");
	words.push_back("Forest");
	words.push_back("CandyCountry");
	words.push_back("Camelot");

	menu = new Menu(475, 240, words, this);
	menu->CreateMode1();
}

void GUI::RunSceneryPage(Event x)
{
	if (x.key.code == Keyboard::Enter || x.type == Event::MouseButtonReleased)
	{
		switch (menu->getselected())
		{
			case -1:
			{
				break;
			}
			case 0:
			{
				delete menu;
				menu = nullptr;
				sc = "City";
				SetCharacterPage();
				break;
			}
			case 1:
			{
				delete menu;
				menu = nullptr;
				sc = "Forest";
				SetCharacterPage();
				break;
			}
			case 2:
			{
				delete menu;
				menu = nullptr;
				sc = "CandyCountry";
				SetCharacterPage();
				break;
			}
			case 3:
			{
				delete menu;
				menu = nullptr;
				sc = "Camelot";
				SetCharacterPage();
				break;
			}
		}
		cout << sc;
	}
	else if (x.key.code == Keyboard::Backspace)
	{
		delete menu;
		menu = nullptr;
		SetDufficultyPage();
	}
	else if (x.type == Event::MouseMoved)
	{
		Vector2i mousePos = Mouse::getPosition(*window);
		menu->MouseMoving(mousePos.x, mousePos.y);
	}
	else if (x.key.code == Keyboard::Up)
	{
		menu->MoveUp();
	}
	else if (x.key.code == Keyboard::Down)
	{
		menu->MoveDown();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetCharacterPage()
{
	ResetLists();

	CurrentPage = "Character";
	window->setTitle("Character Page");
	cout << "character";

	vector <string> words;
	words.push_back("Char1");
	words.push_back("Char2");
	words.push_back("Char3");
	words.push_back("Char4");

	menu = new Menu(475, 240, words, this);
	menu->CreateMode1();
}

void GUI::RunCharacterPage(Event x)
{
	if (x.key.code == Keyboard::Enter || x.type == Event::MouseButtonReleased)
	{
		switch (menu->getselected())
		{
			case -1:
			{
				break;
			}
			case 0:
			{
				delete menu;
				menu = nullptr;
				charachter = "char1";
				SetHowToPlayPage();
				break;
			}
			case 1:
			{
				delete menu;
				menu = nullptr;
				charachter = "char2";
				SetHowToPlayPage();
				break;
			}
			case 2:
			{
				delete menu;
				menu = nullptr;
				charachter = "char3";
				SetHowToPlayPage();
				break;
			}
			case 3:
			{
				delete menu;
				menu = nullptr;
				charachter = "char4";
				SetHowToPlayPage();
				break;
			}
		}
		cout << sc;
	}
	else if (x.key.code == Keyboard::Backspace)
	{
		delete menu;
		menu = nullptr;
		SetSceneryPage();
	}
	else if (x.type == Event::MouseMoved)
	{
		Vector2i mousePos = Mouse::getPosition(*window);
		menu->MouseMoving(mousePos.x, mousePos.y);
	}
	else if (x.key.code == Keyboard::Up)
	{
		menu->MoveUp();
	}
	else if (x.key.code == Keyboard::Down)
	{
		menu->MoveDown();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetHowToPlayPage()
{
	ResetLists();

	CurrentPage = "HowToPlay";
	window->setTitle("How To Play Page");
	cout << "how to play";

	texts.push_back(GetText("How to play:", &Prstartk, Color::White, 40, 200, 90));
	texts.push_back(GetText("Dino Actions:\n  Jump: Press 'w'\n  Double jump: press 'w' (x2)\n  Duck: press 's'\n\nOthers:\n  Pause: Press'p'\n  End the game Press'ESC'\n  Mute the background music longPress 'M'\n  Unmutebackground music Press 'M'\n\nPress Enter to start play ", &Prstartk, Color::White, 20, 50, 180));

	sprites.push_back(GetSprite(*GetImage("enter.png"), 1100, 700));
	sprites.push_back(GetSprite(*GetImage("up.png"), 1000, 700));
	sprites.push_back(GetSprite(*GetImage("down.png"), 900, 700));


}

void GUI::RunHowToPlayPage(Event x)
{
	if (x.key.code == Keyboard::Enter)
	{
		SetGamePage();
	}
	else if (x.key.code == Keyboard::Backspace)
	{
		SetCharacterPage();
	}
	else if (x.type == Event::MouseButtonReleased)
	{
		SetGamePage();
	}
}
//////////////////////////////////////////////////////////////
void GUI::SetGamePage()
{
	ResetLists();

	CurrentPage = "Game";
	window->setTitle("Game Page");
	cout << "game";

	temp tmp;
	tmp.StartPlay(*window);
}

void GUI::RunGamePage(Event x)
{
	if (x.key.code == Keyboard::Enter)
	{

	}
	else if (x.key.code == Keyboard::Backspace)
	{
		SetHowToPlayPage();
	}
	else if (x.type == Event::MouseButtonReleased)
	{

	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GUI::RunPage(Event x)
{
	if (CurrentPage == "Landing")
	{
		RunLandingPage(x);
	}
	else if (CurrentPage == "Clickable")
	{
		RunClickablePage(x);
	}
	else if (CurrentPage == "Dufficulty")
	{
		RunDufficultyPage(x);
	}
	else if (CurrentPage == "Scenery")
	{
		RunSceneryPage(x);
	}
	else if (CurrentPage == "Character")
	{
		RunCharacterPage(x);
	}
	else if (CurrentPage == "HowToPlay")
	{
		RunHowToPlayPage(x);
	}
	else if (CurrentPage == "Game")
	{
		RunGamePage(x);
	}
}

void GUI::DrawPage()
{
	if (CurrentPage == "Landing" && clock.getElapsedTime().asMilliseconds() > 200)
	{
		for (int i = 0; i < sprites.size(); i++)
		{
			int x = sprites[i]->getTextureRect().left;

			if (x == 384)
			{
				sprites[i]->setTextureRect(IntRect(0, 0, 24, 24));
			}
			else
			{
				sprites[i]->setTextureRect(IntRect(x + 24, 0, 24, 24));
				clock.restart();
			}
		}
	}
	window->draw(BackGround);
	for (int i = 0; i < rectangles.size(); i++)
	{
		window->draw(*rectangles[i]);
	}
	for (int i = 0; i < texts.size(); i++)
	{
		window->draw(*texts[i]);
	}
	for (int i = 0; i < sprites.size(); i++)
	{
		window->draw(*sprites[i]);
	}
	window->display();
}

bool GUI::Is_Open()
{
	return window->isOpen();
}

bool GUI::PollNextEvent(Event& x)
{
	if (window->pollEvent(x))
	{
		return true;
	}
	return false;
}

void GUI::ClearWindow()
{
	window->clear(Color::Black);
}

bool GUI::CloseWindow()
{
	window->close();
	return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GUI::SetWindowbackground(string ImageName)
{
	Texture* MainMenuTexture = GetImage(ImageName);
	BackGround.setTexture(MainMenuTexture);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Text* GUI::GetText(string str, Font* fnt, Color clr, int size, int x, int y)
{
	if (fnt == nullptr)
	{
		fnt = &Arial;
	}
	Text* text = new Text(str, *fnt);
	text->setFillColor(clr);
	text->setCharacterSize(size);
	text->setPosition(x, y);
	return text;
}

Texture* GUI::GetImage(string ImageName)
{
	Texture* MainMenuTexture = new Texture();
	MainMenuTexture->loadFromFile("Images/" + ImageName);
	return MainMenuTexture;
}

RectangleShape* GUI::GetRectangle(int width, int height, Color clr, int x, int y, int BrdSize, Color brd_clr)
{
	RectangleShape* rectangle = new RectangleShape(Vector2f(width, height));
	rectangle->setFillColor(clr);
	rectangle->setPosition(Vector2f(x, y));
	rectangle->setOutlineColor(brd_clr);
	rectangle->setOutlineThickness(BrdSize);
	return rectangle;
}

Sprite* GUI::GetSprite(Texture& z, int x, int y)
{
	Sprite* sprite = new Sprite();
	sprite->setTexture(z);
	sprite->setPosition(x, y);
	return sprite;
}


void GUI::AddToRectangles(RectangleShape* rect)
{
	rectangles.push_back(rect);
}
void GUI::AddToSprites(Sprite* spr)
{
	sprites.push_back(spr);
}
void GUI::AddToTexts(Text* txt)
{
	texts.push_back(txt);
}
void GUI::AddToTextures(Texture* texture)
{
	textures.push_back(texture);
}
