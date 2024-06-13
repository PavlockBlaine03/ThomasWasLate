#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));
	m_JumpDuration = .45;
}

bool Thomas::handleInput()
{
	m_JustJumped = false;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		// Start jumping if not already
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
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
	return m_JustJumped;
}