#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));
	m_JumpDuration = .25;
}

bool Bob::handleInput()
{
	m_JustJumped = false;
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (!m_isJumping && !m_isFalling)
		{
			m_isJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_isJumping = false;
		m_isFalling = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;
}