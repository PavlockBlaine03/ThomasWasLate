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
			m_SM.playReachGoal();
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

	// Check if fire sound needs to be played
	vector<Vector2f>::iterator it;
	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{
		// Where is the emitter
		float posX = (*it).x;
		float posY = (*it).y;

		// is emitter near player
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		// is player inside localRect
		if (m_Thomas.getPosition().intersects(localRect))
		{
			// play sound and pass location
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
		}
	}

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

	// Update the Hud every required frame time
	m_FramesSinceLastHUDUpdate++;
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpate)
	{
		// Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;

		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		// Update the level text
		ssLevel << "Level: " << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());
		m_FramesSinceLastHUDUpdate = 0;
	}
}