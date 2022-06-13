////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_Text = 0;
	m_Model = 0;
	m_Model2 = 0;
	bird = 0;
	flower = 0;
	banana = 0;
	tree = 0;
	tree2 = 0;

	m_LightShader = 0;
	m_Light = 0;
	m_Light2 = 0;
	pumpkin = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;
	XMMATRIX baseViewMatrix;
	XMFLOAT3 position;

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 4.0f, 5.0f);	// for cube
//	m_Camera->SetPosition(0.0f, 0.5f, -3.0f);	// for chair
		
	position.x = 0;
	position.y = 0;
	position.z = 0;


	// Create the model object.
	m_Model = new ModelClass(1, position);
	if(!m_Model)
	{
		return false;
	}
	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), L"./data/cube.obj", L"./data/grass.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	pumpkin = new ModelClass(1, position);
	if (!pumpkin)
	{
		return false;
	}

	// Initialize the model object.
	result = pumpkin->Initialize(m_D3D->GetDevice(), L"./data/pumpkin.obj", L"./data/pumpkin.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	flower = new ModelClass(2, position);
	if (!flower)
	{
		return false;
	}

	// Initialize the model object.
	result = flower->Initialize(m_D3D->GetDevice(), L"./data/flower.obj", L"./data/flower.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	position.x = 0;
	position.y = 0;
	position.z = 0;
	banana = new ModelClass(1, position);
	if (!banana)
	{
		return false;
	}

	// Initialize the model object.
	result = banana->Initialize(m_D3D->GetDevice(), L"./data/banana.obj", L"./data/banana.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	tree = new ModelClass(30, position);
	if (!tree)
	{
		return false;
	}

	// Initialize the model object.
	result = tree->Initialize(m_D3D->GetDevice(), L"./data/tree.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	tree2 = new ModelClass(20, position);
	if (!tree2)
	{
		return false;
	}

	// Initialize the model object.
	result = tree2->Initialize(m_D3D->GetDevice(), L"./data/tree2.obj", L"./data/flower.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	bird = new ModelClass(1, position);
	if (!pumpkin)
	{
		return false;
	}

	// Initialize the model object.
	result = bird->Initialize(m_D3D->GetDevice(), L"./data/Bird.obj", L"./data/Bird.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}


	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
//	m_Light->SetAmbientColor(0.0f, 0.0f, 0.0f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
//	m_Light->SetDiffuseColor(0.0f, 0.0f, 0.0f, 1.0f);
//	m_Light->SetDirection(0.0f, 0.0f, 1.0f);
//	m_Light->SetDirection(1.0f, 0.0f, 0.0f);
	m_Light->SetDirection(1.0f, -1.5f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(32.0f);


	m_Light2 = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	m_Light2->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light2->SetDiffuseColor(1.0f, 0.0f, 0.0f, 1.0f);
	m_Light2->SetDirection(0.0f, -1.0f, 0.0f);
	m_Light2->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light2->SetSpecularPower(32.0f);
	m_Light2->SetPosition(15.0f, 1.0f, 40.0f);

	m_Camera->Render(camYaw, camPitch, moveLeftRight, moveBackForward, defaultForward, defaultRight);
	m_Camera->GetViewMatrix(baseViewMatrix);

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the model object.
	if(m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	if (bird)
	{
		bird->Shutdown();
		delete bird;
		bird = 0;
	}

	if (flower)
	{
		flower->Shutdown();
		delete flower;
		flower = 0;
	}

	if (banana)
	{
		banana->Shutdown();
		delete banana;
		banana = 0;
	}
	
	if (tree)
	{
		tree->Shutdown();
		delete tree;
		tree = 0;
	}
	
	if (tree2)
	{
		tree2->Shutdown();
		delete tree2;
		tree2 = 0;
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	if (m_Light2)
	{
		delete m_Light2;
		m_Light2 = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}
	
	return;
}

bool GraphicsClass::Frame(int mouseX, int mouseY)
{
	bool result;

	static float rotation = 0.0f;

	// Set the location of the mouse.
	/*result = m_Text->SetMousePosition(mouseX, mouseY, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}*/

	// Update the rotation variable each frame.
	rotation += XM_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if(!result)
	{
		return false;
	}

	return true;
}

LightClass* GraphicsClass::GetLightClass()
{
	return m_Light;
}

CameraClass* GraphicsClass::GetCamerClass()
{
	return m_Camera;
}

bool GraphicsClass::Render(float rotation)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, rotY;
	XMFLOAT3 camPos;
	bool result;
	static float transX = 0.0f;

	float x = 0.05f;

	transX += XM_PI * x;
		
	if (transX >= 20.0f)
	{
		transX = 20.0f;
		x = -0.05f;
		//transX -= XM_PI * x;
	}
	if (transX <= -20.0f)
	{
		x = 0.05f;
		transX -= 20.0f;
	}

	XMVECTOR camVectorPos = m_Camera->GetCamPos();
	camPos.x = XMVectorGetX(camVectorPos);
	camPos.y = XMVectorGetY(camVectorPos);
	camPos.z = XMVectorGetZ(camVectorPos);
	XMFLOAT3 camRot = m_Camera->GetRotation();

	//rotY = XMMatrixRotationY(XMConvertToRadians(90));

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render(camYaw, camPitch, moveLeftRight, moveBackForward, defaultForward, defaultRight);
	moveLeftRight = 0;
	moveBackForward = 0;

	//transformMatrixForObj = XMMatrixTranslation(camPos.x, camPos.y, camPos.z);
	//rotateMatrixForObj = XMMatrixRotationRollPitchYaw(camRot.x, camRot.y, camRot.z);

	//worldMatrixForObj = scaleMatrixForObj * temp * rotateMatrixForObj * transformMatrixForObj;

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	worldMatrix *= XMMatrixScaling(120, 0.1f, 120);
	worldMatrix *= XMMatrixTranslation(0.0f, 0.0f, 0.0f);

	m_Model->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model->GetVertexCount(), m_Model->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		m_Model->GetTexture(), m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(), m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	
	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(1.0, 1.0f, 1.0f);
	worldMatrix *= XMMatrixRotationY(rotation);
	worldMatrix *= XMMatrixTranslation(-45.0f, 0.0f, -20.0f);

	pumpkin->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), pumpkin->GetVertexCount(), pumpkin->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		pumpkin->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(0.05f, 0.05f, 0.05f);
	worldMatrix *= XMMatrixTranslation(0, 0, 0.0f);

	flower->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), flower->GetVertexCount(), flower->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		flower->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(15.0f, 15.0f, 15.0f);
	worldMatrix *= XMMatrixRotationY(rotation);
	worldMatrix *= XMMatrixTranslation(15.0f, 1.0f, 40.0f);

	banana->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), banana->GetVertexCount(), banana->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		banana->GetTexture(),
		m_Light2->GetDirection(), m_Light2->GetAmbientColor(), m_Light2->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light2->GetSpecularColor(), m_Light2->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(3.0f, 3.0f, 3.0f);
	worldMatrix *= XMMatrixTranslation(0, 0, 0.0f);

	tree->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), tree->GetVertexCount(), tree->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		tree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(1.0f, 1.0f, 1.0f);
	worldMatrix *= XMMatrixTranslation(0.0f, 0.0f, 0.0f);

	tree2->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), tree2->GetVertexCount(), tree2->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		tree2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	worldMatrix = XMMatrixIdentity();
	worldMatrix *= XMMatrixScaling(0.2f, 0.2f, 0.2f);
	worldMatrix *= XMMatrixTranslation(transX, 0.0f, -20.0f);

	bird->Render(m_D3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), bird->GetVertexCount(), bird->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix,
		bird->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}
