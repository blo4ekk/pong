#pragma once 
#include <SFML\Graphics.hpp>
#include <string>

class entity : public sf::Sprite
{
public:
	entity()
	{
		this->texture = new sf::Texture();
	}

	void load(std::string filename)
	{
		this->texture->loadFromFile("Graphics/sprites/" +filename);
		this->setTexture(*this->texture);
	}
	void update()
	{
		this->move(this->velocity);
	}
	 
	bool checkcollision(entity* entity)
	{

	}
	~entity()
	{
		delete this->texture;
	}
private:
	sf::Texture* texture;
	sf::Vector2f velocity;

};