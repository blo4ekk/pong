#pragma once
#include "game_state.h"
#include"Entity.h"


class main_game : public tine_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	entity* paddle;

};