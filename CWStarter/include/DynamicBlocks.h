#pragma once

/*!
\file dynamicBlocks.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "physicalThing.h"
#include <cmath>

/*! \class DynamicBlocks
\brief A simple block which can move, rotate and collide with stuff
*/

class DynamicBlocks : public sf::RectangleShape, public PhysicalThing
{
public:	
	DynamicBlocks(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation, const float maxDistance); //!< Complete contructor
	void update(); //!< Update rendering infomation 

private:
	b2Vec2 m_startPosition; //!< start position for block
	b2Vec2 m_velocity; //!< movement speed for the block
	float m_maxDistance; //!< maximum distance block can travel

};


/*! \class Player
\brief Player controlled block which can move and collide with stuff
*/

class Player : public sf::RectangleShape, public PhysicalThing
{
private:
	b2Fixture* m_OnFixture = nullptr; //!< fixture for player character 
	bool m_canJump = false; //!< checks to see if player can jump, set to false by default
	bool m_respawn = false; //!< checks to see if player needs to respawn, set to false by default
	bool m_teleport = false; //!< checks to see if player needs to teleport to other side, set to false by default
	bool m_teleportRight = false;  //!< checks to see if player needs to teleport to other side, set to false by default

	b2World* m_world; //!< creates world for player
	void init(const sf::Vector2f& position, const sf::Vector2f &size, const float orientation); //!< player creation
	

public: 	
	Player(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation); //!< Complete contructor
	void update(); //!< Update rendering infomation 
	void Keyboard(sf::Keyboard::Key code); //!< player keyboard inputs
	void OnKeyRelease(sf::Keyboard::Key code); //!< player keyboard button release
	void Respawn(); //!< player respawn 
	void TeleportLeft(); //!< player teleport left side
	void TeleportRight(); //!< player teleport right side



	int lives = 3; //!< sets player lives to 3 as an int
	int getlives() //!< gets the lives count
	{
		return lives;
	}

	int coins = 0; //!< sets coins to be 0 as an int
	int getcoins()//!< gets the coin count
	{
		return coins;
	}

	
	bool canJump()//!< checks if player can jump
	{
		return m_canJump;
	}

	//! Function to check if player is touching another fixture
	/*!
	\param b2Fixture - passes through fixture.
	\return a boolean if true a collision has occurred
	*/
	void SitOn(b2Fixture* fixture) 
	{
		// player is standing on a fixture
		// checks if player can jump and sets the player to be on the fixture
		m_canJump = true;
		m_OnFixture = fixture;
	}

	//! Function to check if player is not touching another fixture
	/*!
	\param b2Fixture - passes through fixture.
	\return a boolean if true a player is no longer in contact with another fixture
	*/
	void SitOff(b2Fixture* fixture) 		
	{ 
		// player is not touching a fixture
		//player is not on a fixture and player can jump is set to false
		if (m_OnFixture == fixture) m_canJump = false; 	
	}

	
	
};
