/*!
\file Game.cpp
*/
#include "Game.h"


//! Game constructor
/*!
\param window a RenderWindow - creats window that opens when played
\return a Game which creates the game objects and draws them
*/
Game::Game(sf::RenderWindow* window)
{
	// creates the window
	m_window = window;
	//loads texture from the files
	m_texture.loadFromFile("./assets/textures/Background.png"); 
	

	 // sets the background image size
	m_picture.setSize(sf::Vector2f(10.24f, 8.f));
	// set the texture for the background image
	m_picture.setTexture(&m_texture); 

	// set the view center point
	m_view.setCenter(5.12f, 4.f);
	// set the view size	
	m_view.setSize(10.24f, 8.f); 

	// create basic gravity
	m_pWorld = new b2World(mk_gravity); 
	// create debug draw world to be world
	m_debugDraw.setWorld(m_pWorld);
	
	
	//Floor and Ceiling
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(5.12f,  0.f), sf::Vector2f(10.24f, 0.08f), 0.f));
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(5.12f, 7.15f ), sf::Vector2f(10.24f, 0.08f), 0.f));
	// side walls for top half
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(10.09f, 2.58f), sf::Vector2f(0.3f, 4.5f ), 0.f)); // right wall
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.15f, 2.58f), sf::Vector2f(0.3f, 4.5f ), 0.f)); // left wall
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(5.12f, 6.95f), sf::Vector2f(2.f, 0.4f), 0.f)); // middle
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.34f, 6.95f), sf::Vector2f(1.80f, 0.4f), 0.f)); // right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.9f, 6.95f), sf::Vector2f(1.80f, 0.4f), 0.f)); // left	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(5.87f, 6.55f), sf::Vector2f(0.5f, 0.4f), 0.f)); //middle right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(4.37f, 6.55f), sf::Vector2f(0.5f, 0.4f), 0.f)); //middle left
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.79f, 6.4f), sf::Vector2f(0.9f, 0.7f), 0.f)); // right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.45f, 6.4f), sf::Vector2f(0.9f, 0.7f), 0.f)); // left 	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.99f, 5.7f), sf::Vector2f(0.5f, 0.7f), 0.f)); // right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.25f, 5.7f), sf::Vector2f(0.5f, 0.7f), 0.f)); // left	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.64f, 0.18f), sf::Vector2f(1.3f, 0.3f), 0.f)); // right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.6f, 0.18f), sf::Vector2f(1.3f, 0.3f), 0.f)); // left
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(6.52f, 0.18f), sf::Vector2f(1.4f, 0.3f), 0.f)); // M_right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(3.72f, 0.18f), sf::Vector2f(1.4f, 0.3f), 0.f)); // M_left	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.74f, 0.45f), sf::Vector2f(0.4f, 0.3f), 0.f)); // right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.5f, 0.45f), sf::Vector2f(0.4f, 0.3f), 0.f)); // left
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(6.52f, 0.45f), sf::Vector2f(0.75f, 0.3f), 0.f)); // M_right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(3.72f, 0.45f), sf::Vector2f(0.75f, 0.3f), 0.f)); // M_left	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.14f, 2.2f), sf::Vector2f(2.f, 0.25f), 0.f)); //right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(1.10f, 2.2f), sf::Vector2f(2.f, 0.25f), 0.f)); //left	
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.54f, 2.48f), sf::Vector2f(0.8f,0.3f), 0.f)); //medium underblock right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.7f, 2.48f), sf::Vector2f(0.8f, 0.3f), 0.f)); //medium underblock left
	//walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(9.74f, 2.78f), sf::Vector2f(0.4f, 0.3f), 0.f)); //small underblock right
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(0.5f, 2.78f), sf::Vector2f(0.4f, 0.3f), 0.f)); //small underblock left	   	
	//Right centre block walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(8.6f, 4.9f), sf::Vector2f(0.55f, 0.4f), 0.f)); //Right_1
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(8.1f, 4.6f), sf::Vector2f(0.55f, 1.f), 0.f));//Right_2
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(7.65f, 4.1f), sf::Vector2f(0.35f, 1.5f), 0.f));//Right_3
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(6.95f, 4.5f), sf::Vector2f(1.45f, 0.3f), 0.f));//Right_4
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(6.05f, 3.45f), sf::Vector2f(0.35f, 2.8f), 0.f)); //middle right		
	//Left centre block walls
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(1.64f, 4.9f), sf::Vector2f(0.55f, 0.4f), 0.f));  //Left_1
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(2.14f, 4.6f), sf::Vector2f(0.55f, 1.f), 0.f)); //Left_2
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(2.59f, 4.1f), sf::Vector2f(0.35f, 1.5f), 0.f)); //Left_3
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(3.29f, 4.5f), sf::Vector2f(1.45f, 0.3f), 0.f)); //Left_4
	m_staticBlocks.push_back(StaticObj(m_pWorld, sf::Vector2f(4.19f, 3.45f), sf::Vector2f(0.35f, 2.8f), 0.f)); //middle left
	
	//Player character
	m_Player.push_back(Player(m_pWorld, sf::Vector2f(5.12f, 6.3f), sf::Vector2f(0.27f, 0.38f), 0.f));
	   
	//Enemy characters
	m_enemies.push_back(Enemies(m_pWorld, sf::Vector2f(7.32f, 6.9f), sf::Vector2f(0.2f, 0.3f), 0.f, 0.85f));//Bottom Right enemy
	m_enemies.push_back(Enemies(m_pWorld, sf::Vector2f(2.92f, 6.9f), sf::Vector2f(0.2f, 0.3f), 0.f, 0.85f));//Bottom Left enemy
	m_enemies.push_back(Enemies(m_pWorld, sf::Vector2f(9.05f, 1.9f), sf::Vector2f(0.2f, 0.3f), 0.f, 0.72f));//Top Right enemy
	m_enemies.push_back(Enemies(m_pWorld, sf::Vector2f(1.19f, 1.9f), sf::Vector2f(0.2f, 0.3f), 0.f, 0.72f));//Top Left enemy

	//Dynamic block 
	m_dynamicBlocks.push_back(DynamicBlocks(m_pWorld, sf::Vector2f(5.12f, 3.65f), sf::Vector2f(0.92f, 0.2f), 0.f, 4.1f)); // Block moving up and down in the middle of the scene
	
																														  //texture for spikes
	if (!m_spikeTexture.loadFromFile("./assets/textures/spikes.png"))
	{
		std::cout << "Couldn't load spike texture!" << std::endl;
	}
	//Left side spikes		
	m_spikes.push_back(Spikes(m_pWorld, sf::Vector2f(3.09f, 4.1f), sf::Vector2f(0.6f, 0.5f), 0.f, &m_spikeTexture));
	m_spikes.push_back(Spikes(m_pWorld, sf::Vector2f(3.69f, 4.1f), sf::Vector2f(0.6f, 0.5f), 0.f, &m_spikeTexture));
	//Right side spikes
	m_spikes.push_back(Spikes(m_pWorld, sf::Vector2f(6.57f, 4.1f), sf::Vector2f(0.6f, 0.5f), 0.f, &m_spikeTexture));
	m_spikes.push_back(Spikes(m_pWorld, sf::Vector2f(7.17f, 4.1f), sf::Vector2f(0.6f, 0.5f), 0.f, &m_spikeTexture));

	//Coins texture
	if (!m_coinsTexture.loadFromFile("./assets/textures/Coin.png"))
	{
		std::cout << "Couldn't load coin texture!" << std::endl;
	}	
	//Coins
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(5.12f, 0.21f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(0.48f, 3.1f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(9.76f, 3.1f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(0.48f, 0.85f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(9.76f, 0.85f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(3.f, 4.85f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	m_coin.push_back(Coin(m_pWorld, sf::Vector2f(7.24f, 4.85f), sf::Vector2f(0.3f, 0.3f), 0.f, &m_coinsTexture));
	
	//Rotating platforms above spikes
	m_rotatingPlat.push_back(RotatingPlatforms(m_pWorld, sf::Vector2f(3.34f, 2.8f), sf::Vector2f(0.8f, 0.07f), sf::Vector2f(0.f, 0.f), 0.f, sf::Color::Yellow));
	m_rotatingPlat.push_back(RotatingPlatforms(m_pWorld, sf::Vector2f(6.88f, 2.8f), sf::Vector2f(0.8f, 0.07f), sf::Vector2f(0.f, 0.f), 0.f, sf::Color::Yellow));
	
	//teleport blocks
	m_telRight.push_back(TeleportRight(m_pWorld, sf::Vector2f(10.34f, 5.08f), sf::Vector2f(0.2f, 0.5f), 0.f));
	m_telBlock.push_back(TeleportBlock(m_pWorld, sf::Vector2f(-0.1f, 5.08f), sf::Vector2f(0.2f, 0.5f), 0.f));

	// contact listeners for all body types
	for (auto& body : m_staticBlocks) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body));}
	for (auto& body : m_dynamicBlocks) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_Player) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_rotatingPlat) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_spikes) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_coin) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_enemies) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_telBlock) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }
	for (auto& body : m_telRight) { body.SetUserData(new std::pair<PhysicalThing::BodyType, void*>(body.m_bodyType, &body)); }

	// contact listener for coin deletion
	m_pWorld->SetContactListener(new contactList(&coinDeletion));
}
//! Game deconstructor
/*!
\return a ~Game which deletes pointers
*/
Game::~Game() 
{
	// Clean up all pointers
	delete m_pWorld;
	m_pWorld = nullptr;
}
//! Game update
/*!
\return a void which updates the game based on time passing
*/
void Game::update(float timestep)
{
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iPosIterations);
	// Update each dyanmic element - effectively update render information
	for (DynamicBlocks& blocks : m_dynamicBlocks) blocks.update();
	for(Player& block : m_Player) block.update();
	for (RotatingPlatforms& plat : m_rotatingPlat) plat.update();
	for (Coin& coin : m_coin) coin.Update();
	for (Enemies& block : m_enemies) block.update();
	//updates coin deletion
	for (auto coin : coinDeletion)
	{
		coin->Action();
	}
	coinDeletion.clear();
	// updates coin and health for the hud elements
	m_hud.updateCoins(m_Player.at(0).getcoins());   
	m_hud.setHealthText(m_Player.at(0).getlives());
	if (m_Player.at(0).getlives() == 0 || m_Player.at(0).getcoins() == 7)
	{
		m_window->close();
	}
	   	 
	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// Draw everything
	target.draw(m_picture);
	target.setView(m_view);
	target.draw(m_hud);	
	for (Spikes spikes : m_spikes) target.draw(spikes);	
	for (DynamicBlocks blocks : m_dynamicBlocks) target.draw(blocks);
	for (Player block : m_Player) target.draw(block);
	for (RotatingPlatforms plat : m_rotatingPlat) target.draw(plat);
	for (Coin coin : m_coin) target.draw(coin);
	for (Enemies block : m_enemies) target.draw(block);
	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

//on keyboard key press for player
void Game::Keyboard(sf::Keyboard::Key code)
{
	m_Player.at(0).Keyboard(code);
}
//on keyboard key release for player
void Game::OnKeyRelease(sf::Keyboard::Key code)
{
	m_Player.at(0).OnKeyRelease(code);
}
