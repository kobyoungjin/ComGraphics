////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "inputclass.h"


InputClass::InputClass()
{
}


InputClass::InputClass(const InputClass& other)
{
}


InputClass::~InputClass()
{
}


void InputClass::Initialize()
{
	int i;
	

	// Initialize all the keys to being released and not pressed.
	for(i=0; i<256; i++)
	{
		m_keys[i] = false;
	}

	return;
}

void InputClass::Shutdown()
{
	DIMouse->Unacquire();
}


void InputClass::KeyDown(unsigned int input)
{
	// If a key is pressed then save that state in the key array.
	m_keys[input] = true;
	return;
}


void InputClass::KeyUp(unsigned int input)
{
	// If a key is released then clear that state in the key array.
	m_keys[input] = false;
	return;
}

IDirectInputDevice8* InputClass::GetDiMouse()
{
	return DIMouse;
}

bool InputClass::IsKeyDown(unsigned int key)
{
	return m_keys[key];
}




void InputClass::MouseInput(DIMOUSESTATE mouseCurrState)
{
	if ((mouseCurrState.lX != mouseLastState.lX) || (mouseCurrState.lY != mouseLastState.lY))
	{
		float yaw = m_Camera->GetYaw();
		float pitch = m_Camera->GetPitch();

		yaw += mouseLastState.lX * 0.001f;

		pitch += mouseCurrState.lY * 0.001f;

		m_Camera->SetYaw(yaw);
		m_Camera->SetPitch(pitch);

		mouseLastState = mouseCurrState;
	}

	//m_Camera->Render();
}




