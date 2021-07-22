#pragma once


/**
@file Game.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "staticObj.h"
#include "DynamicBlocks.h"
#include "rotatingPlatforms.h"
#include "SFMLDebugDraw.h"
#include "ContactList.h"
#include "physicalThing.h"
#include "Coin.h"
#include "HUD.h"
#include "Enemies.h"


/*! \class Game
\brief Game class references all shapes and draws them in the scene
*/

class Game : public sf::Drawable
{

private:
	sf::Texture m_texture; //!< Texture to be used by picture
	sf::RectangleShape m_picture; //!< Picture drawn to the scene

	sf::View m_view; //!< The view maps from physical co-ordinates to rendering co-ordinates
	sf::Vector2f m_worldSize = sf::Vector2f(10.24f, 8.f); //!< Size of the physical worlds is 10.24 X 8 metres
	 
	b2World* m_pWorld = nullptr; //!< Pointer to the Box2D world.  Using pointers as BOX2D has it's own memory management
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update
	const b2Vec2 mk_gravity = b2Vec2(0.f, 9.8f); //!< Standard earth gravity
	
	std::vector<StaticObj> m_staticBlocks; //!< A collection of fixed blocks. 
	std::vector<DynamicBlocks> m_dynamicBlocks; //!< A collection of moving blocks.
	std::vector<Player> m_Player; //!< block that player controls
	std::vector<Spikes> m_spikes; //!< spikes that kill player if touched
	std::vector<RotatingPlatforms> m_rotatingPlat; //!< platform that rotates around
	std::vector<Coin> m_coin; //!< coin that can be intereacted with
	std::vector<Coin*> coinDeletion; //!< deletion for the coin
	std::vector<TeleportBlock> m_telBlock; //!< block that deletes and creates player in another position
	std::vector<TeleportRight> m_telRight; //!< block that deletes and creates player in another position
	std::vector<Enemies> m_enemies; //!< enemies that kill player when interacted with
	HUD m_hud; //!< desplays lives, coins and timer
	
	 

	sf::Texture m_coinsTexture; //!< creates a texture for coins
	sf::Texture m_spikeTexture; //!< creates a texture for coins


	bool m_debug = false; //!< Toggle for debug drawing
	SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing

	contactList* m_contact; //!< crerates a contact listener

	

public:
	Game(sf::RenderWindow* window); //!<Constructor for the game
	~Game(); //!< Deconstructor
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //!< Overidden draw function from drawable - does the drawing
	void update(float timestep); //!< Updates the game based on time passing
	void toggleDebug() { m_debug = !m_debug; } //!< Toggle for debug drawing
	void Keyboard(sf::Keyboard::Key code); //!< key pressed for player
	void OnKeyRelease(sf::Keyboard::Key code); //!< key release for player

	sf::RenderWindow* m_window; //!< creates render window with pointer

};