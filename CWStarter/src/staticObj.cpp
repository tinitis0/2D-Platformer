/*!
\file staticObj.cpp
*/

#include "staticObj.h"

//! StaticObj constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a static objects
\param size a Vector2f - the size of the static objects
\param orientation a float - orientation of the static objects in the world
\return a StaticObj which creates the static block
*/
StaticObj::StaticObj(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation)
{
	// creates static objects for the game to draw
	// creates the static objects body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// set the position  and rotation when creating in game
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	// creates the body in the world
	m_body = world->CreateBody(&l_bodyDef);
	// set the box size and radius when creating in game
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = 0.0f;
	l_fixtureDef.shape = &l_shape;
	// creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	// sets the position, size, origin and rotation of the static objects
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);	
	setFillColor(sf::Color::White);
	setOutlineThickness(0.f);
	//Sets the body type lable
	m_bodyType = BodyType::STATICBLOCKS;	

}

