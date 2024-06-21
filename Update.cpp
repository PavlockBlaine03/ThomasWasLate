#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;


void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}

	if (m_Playing)
	{
		// Update thomas
		m_Thomas.update(dtAsSeconds);

		// Update bob
		m_Bob.update(dtAsSeconds);

		// detect collisions
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New Level Required
			m_NewLevelRequired = true;

			// Play sound
		}
		else
		{
			// Run bobs collisions
			detectCollisions(m_Bob);
		}

		// Let Bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead())) {
			
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead())) {

			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}// End if Playing

	// Set appropriate view
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}