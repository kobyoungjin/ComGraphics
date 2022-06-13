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
	//void MoveLeft(float);
	//void MoveRight(float);
	//void MoveBack(float);
	//void MoveForward(float);
	//void MoveUp(float);
	//void MoveDown(float);

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetRotation();
	XMVECTOR GetCamPos();

	void Render(float, float, float, float, XMVECTOR, XMVECTOR);
	void GetViewMatrix(XMMATRIX&);
	void RotateCamer(float, float, float);

	XMVECTOR camPosition;
	XMVECTOR camTarget = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR camUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR m_camRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f) , m_camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	XMVECTOR playerTarget = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR playerUp = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR playerRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), playerForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

private:
	XMFLOAT3 m_position;
	XMFLOAT3 m_rotation;
	XMMATRIX m_viewMatrix;
	XMMATRIX camRotationMatrix;
};

#endif