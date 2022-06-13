////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "textclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(int, int);
	LightClass* GetLightClass();
	CameraClass* GetCamerClass();
	bool Render(float);

public:
	float moveLeftRight = 0.0f;
	float moveBackForward = 0.0f;
	float camYaw = 0.0f;
	float camPitch = 0.0f;

	float xAngle = 0;
	float yAngle = 0;
	XMFLOAT3 birdPos;

private:
	D3DClass* m_D3D;
	CameraClass* m_Camera;
	TextClass* m_Text;

	ModelClass* m_Model, * m_Model2, * bird, * flower, * banana, * tree, * tree2, * pumpkin;

	LightShaderClass* m_LightShader;
	LightClass* m_Light, * m_Light2;

	XMVECTOR defaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR defaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);

	XMMATRIX worldMatrixForObj;
	XMMATRIX rotateMatrixForObj;
	XMMATRIX transformMatrixForObj;
	XMMATRIX scaleMatrixForObj = XMMatrixScaling(0.02f, 0.02f, 0.02f);

	XMMATRIX temp = XMMatrixTranslation(0.0f, 0.2f, -2.0f);
};

#endif