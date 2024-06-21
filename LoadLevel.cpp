#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;
	// Delete previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i) {
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LM.nextLevel(m_VaLevel);

	// Prepare sound emitters
	populateEmitters(m_FireEmitters, m_ArrayLevel);

	// How long is this new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);
	m_NewLevelRequired = false;
}