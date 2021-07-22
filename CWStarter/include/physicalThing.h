#pragma once

/*!
\file physicalThing.h
*/

#include <Box2D/Box2D.h>

#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

/*!
\class PhysicsThing
\brief A simple class with common attributes and a few const values used in a few places.
*/
class PhysicalThing {
protected:
	b2Body * m_body = nullptr; //!< Box2D body, no need to delete this as BOX2D will look after it
	const float mk_fDensity = 1.0f; //!< Density of the material - used to give mass
	const float mk_fFriction = 0.0f; //!< Friction - I guess this is only friction from movement, not when static
	const float mk_fRestitution = 0.6f; //!< Restitution - bouncyness of stuff

public:
	enum class BodyType //!< sets the bodytypes for all objects in the game
	{		
		DYNAMICBLOCKS, 
		STATICBLOCKS,
		PLAYER,
		ROTATINGPLATFORMS,
		SPIKE,
		COIN,
		TELEPORTBLOCK,
		TELEPORTRIGHT,
		ENEMY
	};

	BodyType m_bodyType; //!< creating a bodytype

	
	void SetUserData() //!< sets user data
	{
		m_body->SetUserData(new std::pair<BodyType, void*>(m_bodyType, this)); //!< sets user data to m_body
	}

	
	void SetUserData(void * p) //!< ests user data yo pointer
	{
		m_body->SetUserData(p); //!< sets the pointer to m_body
	}
};
