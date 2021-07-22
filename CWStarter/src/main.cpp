/*!
\file main.cpp
* \brief Main file for the application
*
* Contains the entry point of the application and the functions which combine
* to provide 2D Platformer game.
*/

/*!\
*
* This program contains a fully working 2D platformer game. 
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "game.h"

//! Main application
/*!
\return a int which creates the game
*/
int main() /** Entry point for the application */
{
	// Open main window
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Ancient Dungeons"); 
	
	Game game(&window);
	float timeElapsed = 0.f;
	float fFrameTime = 1.0f / 60.f;

	// Start a clock to provide time for the physics
	sf::Clock clock;	   

	// Run a game loop
	while (window.isOpen())
	{
		window.clear(sf::Color());

		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed  on button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			//gets the keyboard input for player
			if (event.type == sf::Event::KeyPressed)
					game.Keyboard(event.key.code);
			// debug mode if key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Tab)
				{
					game.toggleDebug();
				}
			}	
			//key release for player input
			if (event.type == sf::Event::KeyReleased)
				game.OnKeyRelease(event.key.code);
		}

		// Find out how much time has elapsed
		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past the update the physics
		if (m_fElapsedTime > fFrameTime)
		{
			game.update(m_fElapsedTime);
			clock.restart();
		}
		//draws the game
		window.draw(game);
		//displays the window
		window.display();
	}

}