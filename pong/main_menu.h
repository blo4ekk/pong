#pragma once

#include "game_state.h"

class main_menu : public tine_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

	~main_menu();
private:
	sf::Font* font;
	sf::Font* font1;
	sf::Text* title;
	sf::Text* play;
	sf::Text* information;
	sf::Text* exit;
};