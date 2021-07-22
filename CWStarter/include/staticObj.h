#pragma once

/*!
\file staticObj.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "physicalThing.h"

/*! \class staticObj
\brief A simple block which can't move or rotate but can collide with stuff
*/

class StaticObj : public sf::RectangleShape, public PhysicalThing
{
private:
	sf::Texture texture; //!< Texture to be used by picture
	sf::RectangleShape B_picture; //!< Picture drawn to the scene
	
public:
	StaticObj() {} //!< Empty contructor
	StaticObj(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation); //!< Complete contructor
	

};

/*! \class Spikes
\brief A simple block which can not move or rotate but can collide with stuff
*/

class Spikes : public sf::RectangleShape, public PhysicalThing
{
public:
	Spikes(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation, sf::Texture* texture); //!< Complete contructor
};

/*! \class TeleportBlock
\brief Simple block which cant move or rotate but can interact with stuff
*/

class TeleportBlock : public sf::RectangleShape, public PhysicalThing
{
private:
	b2Fixture* m_teleport = nullptr;	//!< creates fixture which is set to null pointer
public:
	TeleportBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float orientation); //!< Complete contructor	
};

/*! \class TeleportRight
\brief A simple block which can not move or rotate but can collide with stuff
*/

class TeleportRight : public sf::RectangleShape, public PhysicalThing
{
private:
	b2Fixture* m_teleRight = nullptr;	//!< creates fixture which is set to null pointer
public:
	TeleportRight(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float orientation); //!< Complete contructor	
};
