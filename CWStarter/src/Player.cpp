/*!
\file Player.cpp
*/

#include "dynamicBlocks.h"
//! movement states
/*!
\return a enum which has movement states in it
*/
enum _moveState {
	MS_LEFT,
	MS_RIGHT,
	MS_STOP,

};
_moveState moveState;

//! Player constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a player
\param size a Vector2f - the size of the dynamic blocks.
\param orientation a float - orientation of the Player
\return a Player which creates the player character
*/
Player::Player(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
{
	m_world = world; // references the world
	init( position, size, orientation); // calls init function
}
//! Init function creates the player
/*!
\param position a Vector2f - the position of a player
\param size a Vector2f - the size of player
\param orientation a float - orientation of the player
\return a void which creates the player character
*/
void Player::init(const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
{
	// creates player for the game to draw

	// creates the player body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// set the position when creating in game
	l_bodyDef.position.Set(position.x, position.y);
	// set it as dynamic body
	l_bodyDef.type = b2_dynamicBody; 
	// creates the body in the world
	m_body = m_world->CreateBody(&l_bodyDef);
	// set the box size when creating in game
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = 0.2f;
	l_fixtureDef.friction = 1;
	l_fixtureDef.restitution = 0.0f;
	l_fixtureDef.shape = &l_shape;
	// creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	// sets the position, size, origin and rotation of player
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setFillColor(sf::Color::Blue);
	//sets fixed rotation to be true. stops the player from rotating
	m_body->SetFixedRotation(true); 
	// default movementState is stop
	moveState = MS_STOP; 
	//Sets the body type lable
	m_bodyType = BodyType::PLAYER;
}
/*!Player Respawn
\return a void which sets the respawn bool to be true
*/
void Player::Respawn()
{
	m_respawn = true;
	std::cout << "respawn";
}
/*!Player Teleport
\return a void which sets the teleport bool to be true
*/
void Player::TeleportLeft()
{
	m_teleport = true;
	std::cout << "teleport";
}
/*!Player TeleportRight
\return a void which sets the teleportRight bool to be true
*/
void Player::TeleportRight()
{
	m_teleportRight = true;
	std::cout << "teleport";
}

//! Player update
/*!
\return a void which updates all the information and drawables in the Player class
*/
void Player::update()
{
	// updates the player character every frame
	// gets the position player character and sets it as new position every frame
	b2Vec2 pos = m_body->GetPosition();
	setPosition(pos.x, pos.y);
	// gets player velocity and sets the deired velocity to 0 when in stop state
	b2Vec2 vel = m_body->GetLinearVelocity();
	float desiredVelocity = 0;
	// updates the movement states when the keyboard keys are pressed
	switch (moveState)
	{
	case MS_LEFT:  desiredVelocity = -1.5; break;
	case MS_STOP:  desiredVelocity = 0; break;
	case MS_RIGHT: desiredVelocity = 1.5; break;


	}
	// changes the velocity and applyse it to character body
	float velChange = desiredVelocity - vel.x;
	float impulse = m_body->GetMass() * velChange; //disregard time factor
	m_body->ApplyLinearImpulse(b2Vec2(impulse, 0), m_body->GetWorldCenter(), true);

	// respown statment 
	if (m_respawn)
	{
		//gets the body from the world and destroys it
		m_world->DestroyBody(m_body);	
		//creates new palyer body at set loctaion
		init(sf::Vector2f(5.12f, 6.3f), sf::Vector2f(0.27f, 0.38f), 0.f);
		//sets the respawn to be false
		m_respawn = false;	
		//sets the user data for the new body
		m_body->SetUserData(new std::pair<BodyType, void*>(m_bodyType, this));
		//takes 1 lives of the player
		lives--;
	}

	if (m_teleport)
	{
		//gets the body from the world and destroys it
		m_world->DestroyBody(m_body);
		//creates new palyer body at set loctaion
		init(sf::Vector2f(10.04f, 5.2f), sf::Vector2f(0.27f, 0.38f), 0.f);
		//sets the respawn to be false
		m_teleport = false;
		//sets the user data for the new body
		m_body->SetUserData(new std::pair<BodyType, void*>(m_bodyType, this));
	}

	if (m_teleportRight)
	{
		//gets the body from the world and destroys it
		m_world->DestroyBody(m_body);
		//creates new palyer body at set loctaion
		init(sf::Vector2f(0.2f, 5.2f), sf::Vector2f(0.27f, 0.38f), 0.f);
		//sets the respawn to be false
		m_teleportRight = false;
		//sets the user data for the new body
		m_body->SetUserData(new std::pair<BodyType, void*>(m_bodyType, this));
	}

}


//! Player Keyboard input
/*!
\param code a keyboard key - keyboard key pressed
\return a void which creates switch case statments for player movement state and applys jump impulse
*/
void Player::Keyboard(sf::Keyboard::Key code)
{
	switch (code)
	{		
	case sf::Keyboard::A:  //move left
		moveState = MS_LEFT;
		break;
	case sf::Keyboard::D: //move right
		moveState = MS_RIGHT;
		break;
	case sf::Keyboard::Space: // jump
		if (canJump())
		{
			float Jimpulse = m_body->GetMass() * -5;
			m_body->ApplyLinearImpulse(b2Vec2(0, Jimpulse), m_body->GetWorldCenter(), true);
		}
		break;

	}
}
//! Player Keyboard input
/*!
\param code a keyboard key - keyboard key release
\return a void which creates switch case statments for player movement state
*/
void Player::OnKeyRelease(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::A:  //move left
		if (moveState == MS_LEFT)
		{
			moveState = MS_STOP;
		}		
		break;
	case sf::Keyboard::D: //move right
		if (moveState == MS_RIGHT)
		{
			moveState = MS_STOP;
		}	
		break;
	}
}
