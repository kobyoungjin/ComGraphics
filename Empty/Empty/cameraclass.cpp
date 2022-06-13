////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "cameraclass.h"


CameraClass::CameraClass()
{
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 0.0f;

	m_rotation.x = 0.0f;
	m_rotation.y = 0.0f;
	m_rotation.z = 0.0f;
}


CameraClass::CameraClass(const CameraClass& other)
{
}


CameraClass::~CameraClass()
{
}


void CameraClass::SetPosition(float x, float y, float z)
{
	camPosition = XMVectorSet(x, y, z, 0);
}



void CameraClass::SetRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}
 

XMFLOAT3 CameraClass::GetPosition()
{
	return m_position;
}


XMFLOAT3 CameraClass::GetRotation()
{
	return m_rotation;
}

XMVECTOR CameraClass::GetCamPos()
{
	return camPosition;
}

// This uses the position and rotation of the camera to build and to update the view matrix.
void CameraClass::Render(float camYaw, float camPitch, float moveLeftRight, float moveBackForward, XMVECTOR defaultRight, XMVECTOR defaultForward)
{
	XMMATRIX RotationTempMatrix;
	XMMATRIX matrixRotation;

	RotationTempMatrix = XMMatrixRotationRollPitchYaw(0, camYaw, camPitch);
	camTarget = XMVector3TransformCoord(defaultForward, RotationTempMatrix);
	camTarget = XMVector3Normalize(camTarget);
	
	matrixRotation = XMMatrixRotationRollPitchYaw(0, camYaw, 0);

	camUp = XMVector3TransformCoord(camUp, matrixRotation);
	m_camRight = XMVector3TransformCoord(defaultRight, matrixRotation);
	m_camForward = XMVector3TransformCoord(defaultForward, matrixRotation);
	
	camPosition += moveLeftRight * m_camRight;
	camPosition += moveBackForward * m_camForward;
;
	camTarget = camPosition + camTarget;

	m_viewMatrix = XMMatrixLookAtLH(camPosition, camTarget, camUp);

	return;
}


void CameraClass::GetViewMatrix(XMMATRIX& viewMatrix)
{
	viewMatrix = m_viewMatrix;
}

void CameraClass::RotateCamer(float x, float y, float z)
{
	m_rotation.x += x;
	m_rotation.y += y;
	m_rotation.z += z;
}


