#include <iostream>
#include "main_menu.h"
#include "main_game.h"


void main_menu::Initialize(sf::RenderWindow* window)
{
	this->selected = 0;
	this->font = new sf::Font();
	this->font1 = new sf::Font();
	this->font->loadFromFile("font.ttf");
	this->font1->loadFromFile("font1.ttf");


	this->title = new sf::Text("Pong", *this->font, 248U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2.5, window->getSize().y / 4);
	
	this->play = new sf::Text("Play", *this->font1, 100U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 5, window->getSize().y / 2);
	
	this->information = new sf::Text(" Information", *this->font1, 100U);
	this->information->setOrigin(this->information->getGlobalBounds().width / 2, this->information->getGlobalBounds().height / 2);
	this->information->setPosition(window->getSize().x / 3, window->getSize().y / 1.7);
	
	this->exit = new sf::Text("Exit", *this->font1, 100U);
	this->exit->setOrigin(this->exit->getGlobalBounds().width / 2, this->exit->getGlobalBounds().height / 2);
	this->exit->setPosition(window->getSize().x / 5, window->getSize().y / 1.48);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->information;
	delete this->exit;
}
void main_menu::Render(sf::RenderWindow* window)
{
	this->play->setColor(sf::Color::White);
	this->information->setColor(sf::Color::White);
	this->exit->setColor(sf::Color::White);
	switch (this->selected)
	{
	case 0:
		this->play->setColor(sf::Color::Red);
		break;
	case 1:
		this->information->setColor(sf::Color::Red);
		break;
	case 2:
		this->exit->setColor(sf::Color::Red);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->information);
	window->draw(*this->exit);
}
void main_menu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upkey)
	{
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downkey)
	{
		this->selected += 1;
	}
	if (this->selected > 1)
	{
		this->selected = 2;
	}
	if (this->selected < 1)
	{
		this->selected = 0;
	}
	this->upkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			corestate.SetState(new main_game());
			break;
		case 1:
			break;
		case 2:
			quitgame = true;
			break;
		}
	}
}
