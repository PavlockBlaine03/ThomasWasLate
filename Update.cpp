#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;


void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// Spawn thomas and bob
		// this will be moved to a function later
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		// Make sure it is called once
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_Playing)
	{
		// Update thomas
		m_Thomas.update(dtAsSeconds);

		// Update bob
		m_Bob.update(dtAsSeconds);

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