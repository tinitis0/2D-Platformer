/*!
\file Coin.cpp
*/

#include "Coin.h"

//! Coin constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a coin.
\param size a Vector2f - the size of the coin.
\param orientation a float - orientation of the coin in the world
\param texture a Texture - texture for the coin
\return a Coin which creates the coin
*/

Coin::Coin(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation, sf::Texture* texture)
{
	// creates coins for the game to draw

	// creates the coins body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// coins are static objects
	l_bodyDef.type = b2_staticBody; 
	//lets the position and angle 
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	// creates the body in the world
	m_body = world->CreateBody(&l_bodyDef);
	// sets the shape as a box 
	l_shape.SetAsBox(size.x * 0.4f, size.y * 0.4f);
	l_shape.m_radius = 0.0f;
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = 0.0f;
	l_fixtureDef.shape = &l_shape;
	 // creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	// sets the position, size, origin and rotation of the coin
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	// gives the coin bodytype lable
	m_bodyType = BodyType::COIN;
	// sets the texture for the coin
	setTexture(texture);
}

//! Coin Update
/*!
\return a void which updates the coin every frame
*/
void Coin::Update()
{
	// updates the coin every frame
	// gets the position of the coin and sets it as new position every frame
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);	
}

//! Coin Action
/*!
\return a void which when called gets the coin body and destroys it
*/
void Coin::Action()
{
	m_body->GetWorld()->DestroyBody(m_body);
}