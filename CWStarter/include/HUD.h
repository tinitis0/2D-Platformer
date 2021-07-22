#pragma once

/**
@file HUD.h
*/

#include "Box2D/Box2D.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include "DynamicBlocks.h"
#include "Coin.h"

/*! \class HUD
\brief Hud is and Display for the timer, coins and lives
*/

class HUD : public sf::Drawable
{
private:
	sf::Texture m_HeartTexture; //!< Texture to be used by picture
	sf::RectangleShape m_Heartshape; //!< Picture drawn to the scene
	sf::Texture m_CoinTexture; //!< Texture to be used by picture
	sf::RectangleShape m_Coinshape; //!< Picture drawn to the scene	
	sf::Font m_font;//!< Font for the text in the scene
	sf::Text m_coinText;//!< Text for the Coin counter
	sf::Text m_XText;//!< Text for the for X in lives counter
	sf::Text m_livesText;//!< Text for the lives remaining
	sf::Text m_levelText;//!< Text for the Level name
	


public:
	HUD();	 //!< Contructor
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //!< Overidden draw function from drawable - does the drawing
	void setHealthText(int lives); //!<  Sets the health text to be lives
	void updateCoins(int coin); //!< Uupdates the coin texts
	
};