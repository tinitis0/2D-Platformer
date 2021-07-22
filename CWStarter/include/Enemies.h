#pragma once

/*!
\file Enemies.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "physicalThing.h"
#include <cmath>

/*! \class Enemies
\brief A simple block which can move, rotate and collide with stuff
*/

class Enemies : public sf::RectangleShape, public PhysicalThing
{
public:
	Enemies(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation, const float maxDistance); //!< Complete contructor
	void update(); //!< Update rendering infomation every frame
private :	
	b2Vec2 m_startPosition; //!< start position for block
	b2Vec2 m_velocity; //!< movement speed for the block
	float m_maxDistance; //!< maximum distance block can travel
};