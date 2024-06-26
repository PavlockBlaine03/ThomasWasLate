#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(Color::White);

	// Update the shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

	if (!m_SplitScreen)
	{
		// Switch background view
		m_Window.setView(m_BGMainView);

		// Draw background with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to the main view
		m_Window.setView(m_MainView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		// Draw bob
		m_Window.draw(m_Bob.getSprite());

		if (m_PS.running()) m_Window.draw(m_PS);
	}
	else
	{
		/* Split - screen view is active
		* First Draw thomas side of the screen
		* Switch background view
		*/
		m_Window.setView(m_BGLeftView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		
		// Switch to the left view
		m_Window.setView(m_LeftView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw bob
		m_Window.draw(m_Bob.getSprite());

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());

		if (m_PS.running()) m_Window.draw(m_PS);

		// draw bob's side of screen
		m_Window.setView(m_BGRightView);
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);
		m_Window.setView(m_RightView);

		// draw the level
		m_Window.draw(m_VaLevel, &m_TextureTiles);

		// Draw thomas
		m_Window.draw(m_Thomas.getSprite());
		// Draw Bob
		m_Window.draw(m_Bob.getSprite());

		if (m_PS.running()) m_Window.draw(m_PS);

	}

	// Draw hud
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}



	m_Window.display();
}