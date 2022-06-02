////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _CAMERACLASS_H_
#define _CAMERACLASS_H_

#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
//////////////
// INCLUDES //
//////////////
#include <dinput.h>
#include <directxmath.h>

#include "AlignedAllocationPolicy.h"

using namespace DirectX;

////////////////////////////////////////////////////////////////////////////////
// Class name: CameraClass
////////////////////////////////////////////////////////////////////////////////
class CameraClass : public AlignedAllocationPolicy<16>
{
public:
	CameraClass();
	CameraClass(const CameraClass&);
	~CameraClass();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);
	void MovePosition(float, float, float);
	void SetFrameTime(float);

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetRotation();
	float GetYaw();
	float GetPitch();
	void SetYaw(float yaw);
	void SetPitch(float pitch);


	void Render();
	void GetViewMatrix(XMMATRIX&);
private:
	XMFLOAT3 m_position;
	XMFLOAT3 m_rotation;
	XMMATRIX m_viewMatrix;
	float m_frameTime;
	float yaw, pitch, roll;
};

#endif