#include "Engine.h"
using namespace std;
using namespace sf;

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel)
{
	// Make sure the vector is empty
	vSoundEmitters.empty();

	// Keep track of previous emitters
	FloatRect previousEmitter;

	// Search for fire in level
	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)
			{
				// Skip over any fire tiles too near a prev emitter
				if (!FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter))
				{
					// Add coords of this water block
					vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					// Make a rectangle 6 x 6 blocks
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = y * TILE_SIZE * 6;
				}
			}
		}
	}
	return;
}