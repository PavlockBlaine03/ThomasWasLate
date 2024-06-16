#include "Engine.h"

Engine::Engine()
{
	// Get screen resolution and create window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(resolution.x, resolution.y, 32), "Thomas Was Late", Style::Fullscreen);

	// Initialize the full screen view
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Initialize split-screen view
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	if (!Shader::isAvailable()) {
		m_Window.close();
	}

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/Background.png");

	// Associate sprite with texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// load texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");
}

void Engine::run()
{
	Clock clock;
	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// update the total game time
		m_GameTimeTotal += dt;

		// Make a decimal fraction from delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}