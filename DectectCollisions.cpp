#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character) {

	bool reachedGoal = false;

	FloatRect detectionZone = character.getPosition();

	// Make a floatrec to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	if (endX >= m_LM.getLevelSize().x) endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y) endY = m_LM.getLevelSize().y;

	// Has the player fallen out the map
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level)) {
		// respawn character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// loop through all blocks
	for (int x = startX; x < endX; x++) {
		for (int y = startY; y < endY; y++) {
				// initialize starting position
				block.left = x * TILE_SIZE;
				block.top = y * TILE_SIZE;

				// Has character burnt or drowned
				if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {
					if (character.getHead().intersects(block)) {
						character.spawn(m_LM.getStartPosition(), GRAVITY);
					}
					if (m_ArrayLevel[y][x] == 2) { // fire 
						// Play sound
					}
					else { // Waterdwad
						// Play sound
					}
				}

			// is character colliding with regular block
			if (m_ArrayLevel[y][x] == 1) {

				if (character.getRight().intersects(block)) {
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block)) {
					character.stopLeft(block.left);
				}
				if (character.getFeet().intersects(block)) {
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block)) {
					character.stopJump();
				}
			}

			// More collisions go here


			// Has character reached goal
			if (m_ArrayLevel[y][x] == 4) {
				reachedGoal = true;
			}
		}
	}
	return reachedGoal;
}
