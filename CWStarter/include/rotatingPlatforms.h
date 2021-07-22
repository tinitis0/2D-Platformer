#pragma once

/*!
\file rotatingPlatforms.h
*/

#include <SFML/Graphics.hpp>

#include "physicalThing.h"


/*! \class RotatingPlatforms
\brief creates a platform using revolute joint, which can interact with player object
*/

class RotatingPlatforms : public PhysicalThing, public sf::Drawable
{
private:
	sf::RectangleShape m_rectangle; //!< creates rectangle shape
	b2Body * m_anchor; //!< creates body for anchor
	b2RevoluteJoint * m_hinge; //!< creates the joint for the platform
public:
	RotatingPlatforms(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Color colour); //!< Complete contructor
	void draw(sf::RenderTarget& render, sf::RenderStates states) const; //!< Draw rotating platform
	void update();  //!< Update rendering infomation every frame
};
