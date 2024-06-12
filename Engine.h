#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace sf;

class Engine
{
	TextureHolder th;
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// gravity
	const int GRAVITY = 300;

	// create a window
	RenderWindow m_Window;

	// The main view
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// The three views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HudView;

	// Declare a sprite texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// is the game playing?
	bool m_Playing = false;

	// is character 1 or 2 the current focus?
	bool m_Character1 = true;

	// Start in full screen (not split) mode
	bool m_SplitScreen = false;

	// Time left in current level(seconds)
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// is it time for a new/first level?
	bool m_NewLevelRequired = true;

	//Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:

	// The engine constructor
	Engine();

	// Run will call all the private functions
	void run();
};