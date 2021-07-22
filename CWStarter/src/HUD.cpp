/*!
\file HUD.cpp
*/
#include "HUD.h"

//! HUD constructor
/*!
\return a HUD which creates Hud elements
*/
	HUD::HUD()
	{

		// creates Hud elements

		//loads texture from the files
		m_HeartTexture.loadFromFile("./assets/textures/Heart.png");
		// set the texture for the background image
		m_Heartshape.setTexture(&m_HeartTexture); 
		// sets the background image size
		m_Heartshape.setSize(sf::Vector2f(0.5f, 0.5f)); 
		//sets the position
		m_Heartshape.setPosition(sf::Vector2f(0.2f, 7.35f));	

		//loads texture from the files
		m_CoinTexture.loadFromFile("./assets/textures/Coin.png");
		// set the texture for the background image
		m_Coinshape.setTexture(&m_CoinTexture);
		// sets the background image size
		m_Coinshape.setSize(sf::Vector2f(0.5f, 0.35f));
		//sets the position
		m_Coinshape.setPosition(sf::Vector2f(8.75f, 7.42f));
		// loads the font for the text elements
		if (!m_font.loadFromFile("./assets/Fonts/Text.otf"))
		{
			// error...
		}
		// sets font   
		m_coinText.setFont(m_font);
		// sets position
		m_coinText.setPosition(9.25f, 7.42f);
		//sets the character size
		m_coinText.setCharacterSize(19);
		//sets the color of the texts
		m_coinText.setFillColor(sf::Color::White);
		//sets the scale of the text
		m_coinText.scale(sf::Vector2f(0.02f, 0.015f));
		//sets the text to be 0
		m_coinText.setString("0");

		// sets font   
		m_livesText.setFont(m_font);
		// sets position
		m_livesText.setPosition(1.04f, 7.415f);
		//sets the character size
		m_livesText.setCharacterSize(18);
		//sets the color of the texts
		m_livesText.setFillColor(sf::Color::White);
		//sets the scale of the text
		m_livesText.scale(sf::Vector2f(0.02f, 0.015f));
		//sets the text to be 0
		m_livesText.setString("0");
		
		// sets font   
		m_XText.setFont(m_font);
		// sets position
		m_XText.setPosition(0.73f, 7.41f);
		//sets the character size
		m_XText.setCharacterSize(19);
		//sets the color of the texts
		m_XText.setFillColor(sf::Color::White);
		//sets the scale of the text
		m_XText.scale(sf::Vector2f(0.021f, 0.014f));
		//sets the text to be X
		m_XText.setString("X");

		
		// sets font 
		m_levelText.setFont(m_font);
		// sets position
		m_levelText.setPosition(4.4f, 7.41f);
		//sets the character size
		m_levelText.setCharacterSize(18);
		//sets the color of the texts
		m_levelText.setFillColor(sf::Color::White);
		//sets the scale of the text
		m_levelText.scale(sf::Vector2f(0.02f, 0.015f));
		//sets the text to be level_1
		m_levelText.setString("Level_1");

	};
//!Hud set lives text
/*!
\param lives a int - player lives
\return a void which creates a string for player lives to change
*/
	void HUD::setHealthText(int lives)
	{
		m_livesText.setString(std::to_string(lives));
	}
/*!Hud update coin text
\param  coin a int - coins collected
\return a void which creates a string for  coins to change
*/
	void HUD::updateCoins(int coin)
	{
		m_coinText.setString(std::to_string(coin));
	}	
//! HUD draw
/*!
\param target a Rendertarget - gets the target that needs to be drawn
\param states a RenderState - the state of the render object
\return a void which draws the target objects
*/
	void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(m_Heartshape);
		target.draw(m_Coinshape);	
		target.draw(m_coinText);
		target.draw(m_livesText);
		target.draw(m_XText);
		target.draw(m_levelText);	
	};

	
