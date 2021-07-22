/*!
\file ContactList.cpp
*/
#include "ContactList.h"

//! ContactList for coin deletion only
/*!
\param coin a Vector<Coin> -  vector for the coin class
\return a contactList which listens for coin deletion function to be called
*/
contactList::contactList(std::vector<Coin*>* coin)
{
	coinDeletion = coin;
}

//! Contact listener Begin contact listens for contact between all objects in game
/*!
\param contact a b2Contact* -  pointer for contact between fixtures
\return a void which listens for collision between objects
*/
void contactList::BeginContact(b2Contact* contact)
{
	
	// sets user data to listen for other userdata and detect when colliding 
	auto userdataA = *(std::pair<PhysicalThing::BodyType, void*>*)contact->GetFixtureA()->GetBody()->GetUserData();
 	auto userdataB = *(std::pair<PhysicalThing::BodyType, void*>*)contact->GetFixtureB()->GetBody()->GetUserData();

	// player collision
	if (userdataA.first == PhysicalThing::BodyType::PLAYER)
	{
		//gets player data  and sets it as data A
		Player* P = (Player*)userdataA.second;
		//gets the objects fixtur data which player is colliding with
		P->SitOn(contact->GetFixtureB());


		////Player collision with coins and coin collection 
		if (userdataB.first == Coin::BodyType::COIN)
		{
			Coin * coins = static_cast<Coin*>(userdataB.second);
			if (coins != nullptr)
			{
				coinDeletion->push_back(coins); // deletes the coin
				P->coins += 1; // adds 1 coin to coin count
			}
			
		}
		// player collision with spike
		if (userdataB.first == PhysicalThing::BodyType::SPIKE)
		{
			//calls respawn function from player class
			P->Respawn();			
		}
		// player collision with enemies
		if (userdataB.first == PhysicalThing::BodyType::ENEMY)
		{
			//calls respawn function from player class
			P->Respawn();	
		}
		// player collision with teleportLeft Block
		if (userdataB.first == PhysicalThing::BodyType::TELEPORTBLOCK)
		{
			//calls TeleportLeft function from player class
			P->TeleportLeft();
		}
		// player collision with teleportRight Block
		if (userdataB.first == PhysicalThing::BodyType::TELEPORTRIGHT)
		{
			//calls TeleportRight function from player class
			P->TeleportRight();
		}
		

	}
	// player collision
	if (userdataB.first == PhysicalThing::BodyType::PLAYER)
	{
		//gets player data  and sets it as dataB
		Player* P = (Player*)userdataB.second;
		//gets the objects fixtur data which player is colliding with
		P->SitOn(contact->GetFixtureA());		

		// player collision with spike
		if (userdataA.first == PhysicalThing::BodyType::SPIKE)
		{
			//calls respawn function from player class
			P->Respawn();			
		}
		// player collision with enemies
		if (userdataA.first == PhysicalThing::BodyType::ENEMY)
		{
			//calls respawn function from player class
			P->Respawn();			
		}
		// player collision with teleportLeft Block
		if (userdataA.first == PhysicalThing::BodyType::TELEPORTBLOCK)
		{
			//calls TeleportLeft function from player class
			P->TeleportLeft();
		}
		// player collision with teleportRight Block
		if (userdataA.first == PhysicalThing::BodyType::TELEPORTRIGHT)
		{
			//calls TeleportRight function from player class
			P->TeleportRight();
		}
	}





}
//! listens when the contact between objects ends
/*!
\param contact a b2Contact* -  pointer for contact between fixtures
\return a void which listens for collision between objects to end
*/
void contactList::EndContact(b2Contact* contact)
{
	// sets user data to listen for other userdata and detect when colliding and when it ends colliding
	auto userdataA = *(std::pair<PhysicalThing::BodyType, void*>*)contact->GetFixtureA()->GetBody()->GetUserData();
	auto userdataB = *(std::pair<PhysicalThing::BodyType, void*>*)contact->GetFixtureB()->GetBody()->GetUserData();
	
	// player collision
	if (userdataA.first == PhysicalThing::BodyType::PLAYER)
	{
		//gets player data  and sets it as data A
		Player* P = (Player*)userdataA.second;
		P->SitOff(contact->GetFixtureB());
	}
	if (userdataB.first == PhysicalThing::BodyType::PLAYER)
	{
		//gets player data  and sets it as data B
		Player* P = (Player*)userdataB.second;
		P->SitOff(contact->GetFixtureA());
	}




}
