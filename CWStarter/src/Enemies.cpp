/*!
\file Enemies.cpp
*/

#include "Enemies.h"

//! Enemies constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a enemies.
\param size a Vector2f - the size of the enemies.
\param orientation a float - orientation of the enemies in the world
\param maxDistance a float - max distance that the enemies can travel
\return a Enemies which creates the enemies
*/
Enemies::Enemies(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation, const float maxDistance) //!< Complete contructor
{
	// creates enemies for the game to draw

	// creates the enemies body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// sets the start position 
	m_startPosition = b2Vec2(position.x, position.y);
	// sets the max distance the enemies can travel
	m_maxDistance = maxDistance;
	//sets the velocity that the enemies trevels at on x and y axes
	m_velocity = b2Vec2(1, 0);
	// set the position when creating in game
	l_bodyDef.position.Set(position.x, position.y); 
	// set the rotation when creating in game
	l_bodyDef.angle = orientation * DEG2RAD;
	// set it as dynamic body
	l_bodyDef.type = b2_dynamicBody; 
	// creates the body in the world
	m_body = world->CreateBody(&l_bodyDef);
	// set the enemies size when creating in game
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f); 
	// set the radius for the shape
	l_shape.m_radius = 0.0f; 
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;
	// creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	// sets the position, size, origin and rotation
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setFillColor(sf::Color::Red);
	setOutlineThickness(0.f);
	//sets fixed rotation to be true. stops the enemies from rotating
	m_body->SetFixedRotation(true); 
	//Sets the linear velocity
	m_body->SetLinearVelocity(m_velocity);
	//Sets the body type lable
	m_bodyType = BodyType::ENEMY;
	
}
//! Enemies update
/*!
\return a void which updates all the information and drawables of the enemies
*/
void Enemies::update()
{
	// updates the enemies every frame
	// gets the position and rotation of the enemies and sets it as new position every frame
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(angle);
	// calculates the position of the enemies
	b2Vec2 vector = m_body->GetPosition() - m_startPosition;
	float result = sqrt(pow(vector.x, 2)) + pow(vector.y, 2);
	// if the result of calculation is more than the max distance then the velocity inverts and enemies travels other direction
	if (result> m_maxDistance)
	{
		m_velocity = -m_velocity;
		m_body->SetLinearVelocity(m_velocity);
	}

}