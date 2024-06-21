#include "Engine.h"

void Engine::input()
{
	Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{

			// handle player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// handle player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between thomas and bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			// Switch between full and split-screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
		}
	}

	// Handle input specific to thomas
	if (m_Thomas.handleInput())
	{
		// Play jump sound
		m_SM.playJump();
	}

	// Handle input specific to bob
	if (m_Bob.handleInput())
	{
		// Play jump sound
		m_SM.playJump();
	}
}