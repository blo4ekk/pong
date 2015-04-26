#include "main_game.h"
#include "main_menu.h"


void main_game::Initialize(sf::RenderWindow* window)
{
	this->paddle = new entity();
	this->paddle->load("paddle1.png");
}
void main_game::Destroy(sf::RenderWindow* window)
{	
	delete this->paddle;
}
void main_game::Render(sf::RenderWindow* window)
{	
	window->draw(*this->paddle);
}
void main_game::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
	{
		corestate.SetState(new main_menu());
	}
}
