#pragma once


/*!
\file ContactList.h
*/

#include "Box2D/Box2D.h"
#include "physicalThing.h"
#include "DynamicBlocks.h"
#include "staticObj.h"
#include "Coin.h"
#include "rotatingPlatforms.h"
#include "HUD.h"

/*! \class ContactList
\brief Contact listener listens to contact/collisions between objects in the game
*/

class contactList : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact); //!< Where contact listener begins
	void EndContact(b2Contact* contact); //!< Where contact listener ends
	contactList(std::vector<Coin*>* coin); //!< Creates contact listener for coin deletion
	
private:
	std::vector<Coin*>* coinDeletion; //!< Creates a vector fo coin deletion

};