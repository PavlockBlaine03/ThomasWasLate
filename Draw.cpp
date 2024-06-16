#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		// Switch background view
		m_Window.setView(m_BGMainView);

		// Draw the background
		m_Window.draw(m_BackgroundSprite);

		// Switch to the main view
		m_Window.setView(m_MainView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw bob
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		/* Split - screen view is active
		* First Draw thomas side of the screen
		* Switch background view
		*/
		m_Window.setView(m_BGLeftView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to the left view
		m_Window.setView(m_LeftView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw bob
		m_Window.draw(m_Bob.getSprite());

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// draw bob's side of screen
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());
		// Draw Bob
		m_Window.draw(m_Bob.getSprite());

	}

	// Draw hud
	m_Window.setView(m_HudView);



	m_Window.display();
}