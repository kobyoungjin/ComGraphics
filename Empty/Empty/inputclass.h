////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_

#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>
#include "cameraclass.h"
////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	void Initialize();
	void Shutdown();
	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	IDirectInputDevice8* GetDiMouse();

	bool IsKeyDown(unsigned int key);
	void MouseInput(DIMOUSESTATE mouseState);
private:
	bool m_keys[256];
	CameraClass* m_Camera;
	DIMOUSESTATE mouseLastState;
	IDirectInputDevice8* DIMouse;
};

#endif