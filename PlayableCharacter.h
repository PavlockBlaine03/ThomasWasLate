#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class PlayableCharacter
{
protected:
	Sprite m_Sprite;
	float m_JumpDuration;

	bool m_isJumping;
	bool m_isFalling;

	// Which direction is the character moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	float m_TimeThisJump;
	bool m_JustJumped = false;

private:
	float m_Gravity;
	float m_Speed = 400;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters body parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_Texture;

public:

	void spawn(Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;

	// Where is the player
	FloatRect getPosition();
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Make character stand firm
	void stopFalling(float Position);
	void stopRight(float Position);
	void stopLeft(float Position);
	void stopJump();

	// Get center of the character
	Vector2f getCenter();

	void update(float elapsedTime);
};