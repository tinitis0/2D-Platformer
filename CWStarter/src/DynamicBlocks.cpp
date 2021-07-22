/*!
\file dynamicBlock.cpp
*/

#include "dynamicBlocks.h"

//! DynamicBlock constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a dynamic blocks.
\param size a Vector2f - the size of the dynamic blocks.
\param orientation a float - orientation of the dynamic blocks in the world
\param maxDistance a float - max distance that the block can travel
\return a DynamicBlocks which creates the dynamic Block
*/
DynamicBlocks::DynamicBlocks(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation, const float maxDistance)
{
	// creates dynamic block for the game to draw

	// creates the dynamic block body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// sets the start position 
	m_startPosition = b2Vec2(position.x, position.y);
	// sets the max distance the block can travel
	m_maxDistance = maxDistance; 
	//sets the velocity that the block trevels at on x and y axes
	m_velocity = b2Vec2(0, 0.5); 
	// set the position when creating in game
	l_bodyDef.position.Set(position.x , position.y); 
	// set the rotation when creating in game
	l_bodyDef.angle = orientation * DEG2RAD;  
	// set it as Kinematic body
	l_bodyDef.type = b2_kinematicBody;
	// creates the body in the world
	m_body = world->CreateBody(&l_bodyDef);
	// set the box size when creating in game
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f); 
	// set the radius for the shape
	l_shape.m_radius = 0.0f; 
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = 0.f;
	l_fixtureDef.shape = &l_shape;
	// creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	// sets the position, size, origin and rotation of the dynamic block
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setFillColor(sf::Color::Magenta);
	setOutlineThickness(0.f);
	//Sets fixed rotation to be true. stops the dynamic block from rotating
	m_body->SetFixedRotation(true); 
	//Sets the linear velocity
	m_body->SetLinearVelocity(m_velocity);
	//Sets the body type lable
	m_bodyType = BodyType::DYNAMICBLOCKS;
}
//! DynamicBlock update
/*!
\return a void which updates all the information and drawables in the dynamic block
*/
void DynamicBlocks::update()
{	  
	// updates the Dynamic blocks every frame
	// gets the position and rotation of the dynamic block and sets it as new position every frame
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);

	// calculates the position of the dynamic blocks
	b2Vec2 vector = m_body->GetPosition() - m_startPosition;
	float result = sqrt(pow(vector.x, 2)) + pow(vector.y, 2);
	// if the result of calculation is more than the max distance then the velocity inverts and block travels other direction
	if (result > m_maxDistance)
	{
		m_velocity = -m_velocity;
		m_body->SetLinearVelocity(m_velocity);
	}
}
