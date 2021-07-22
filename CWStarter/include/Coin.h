#pragma once

/*!
\file Coin.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "physicalThing.h"
#include <iostream>

/*! \class Coin
\brief Coin is a simple block object with texture which can not move or rotate but can collide with player
*/

class Coin : public sf::RectangleShape, public PhysicalThing
{
public:
	Coin(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation, sf::Texture* texture); //!< Complete contructor
	void Update();//!< Updates the coin
	void Action();	//!< Does action for the coin which can be set in .cpp file
};