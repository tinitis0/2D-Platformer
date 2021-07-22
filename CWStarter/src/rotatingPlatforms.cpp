/*!
\file RotatingPlatforms.cpp
*/
#include "rotatingPlatforms.h"

//! RotatingPlatform constructor
/*!
\param world a pointer to b2World - refrerence to world of the game.
\param position a Vector2f - the position of a rotating poplatform.
\param size a Vector2f - the size of the platform
\param anchor a Vector2f - the size of the anchor of the platform
\param orientation a float - orientation of the platform
\param colour a Color - sts the color for the platform
\return a RotatingPlatform which creates the rotating platforms
*/
RotatingPlatforms::RotatingPlatforms(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Color colour)
{
	// creates therotating platform body definition, shape and fixture
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;
	// set the box size and radius when creating in game
	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;
	// gives the fixture density, friction restitution and shape. 
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = 0.f;
	l_fixtureDef.shape = &l_shape;
	// set the position and rotation when creating in game
	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	// set it as Dynamic body for platform
	l_bodyDef.type = b2_dynamicBody;
	m_body = world->CreateBody(&l_bodyDef);
	// creates the fixture
	m_body->CreateFixture(&l_fixtureDef);
	m_body->SetAngularDamping(18.f);
	
	//set it as static body for circle thats a joint
	l_bodyDef.type = b2_staticBody;
	//creates circle shape that platform rotates around
	b2CircleShape l_circ;
	//sets the radius and shape fixture
	l_circ.m_radius = fminf(size.x / 2.0f, size.y / 2.0f);
	l_fixtureDef.shape = &l_circ;
	//creates it as an anchor for the platform
	m_anchor = world->CreateBody(&l_bodyDef);
	m_anchor->CreateFixture(&l_fixtureDef);

	//creates the revolutejoin definition 
	b2RevoluteJointDef jointDef;
	//gets the body a and body b fixtures
	jointDef.bodyA = m_anchor;
	jointDef.bodyB = m_body;
	//connects the joins together
	jointDef.collideConnected = false;
	jointDef.localAnchorA.Set(0.f, 0.f);// Centre of the box
	jointDef.localAnchorB.Set(anchor.x, anchor.y); // from constructor
	m_hinge = (b2RevoluteJoint*)world->CreateJoint(&jointDef);

	// sets the position, size, origin, rotation and colour
	m_rectangle.setPosition(position);
	m_rectangle.setSize(size);
	m_rectangle.setOrigin(size * 0.5f);
	m_rectangle.setRotation(orientation);
	m_rectangle.setFillColor(sf::Color::Magenta);
	m_rectangle.setOutlineThickness(0.f);
	//gives body type label
	m_bodyType = BodyType::ROTATINGPLATFORMS;
}

//! RotatingPlatforms draw
/*!
\param target a Rendertarget - gets the target that needs to be drawn
\param states a RenderState - the state of the render object
\return a void which draws the target objects
*/
void RotatingPlatforms::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rectangle);
}

//! RotatingPlatforms update
/*!
\return a void which updates all the information and drawables in the  rotating platforms
*/
void RotatingPlatforms::update()
{
	// updates the rotatingplatforms every frame
	// gets the position and rotation of the rotating platforms and sets it as new position every frame
	b2Vec2 pos = m_body->GetPosition();
	m_rectangle.setPosition(pos.x, pos.y);
	float angle = m_body->GetAngle()* RAD2DEG;
	m_rectangle.setRotation(angle);
}
