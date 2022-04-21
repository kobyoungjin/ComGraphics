////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(ID3D11Device* device)
{
	bool result;


	// Initialize the vertex and index buffers.
	result = InitializeBuffers(device);
	if (!result)
	{
		return false;
	}

	return true;
}


void ModelClass::Shutdown()
{
	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}


void ModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


int ModelClass::GetIndexCount()
{
	return m_indexCount;
}


bool ModelClass::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;


	// Set the number of vertices in the vertex array.
	m_vertexCount = 50;

	// Set the number of indices in the index array.
	m_indexCount = 50;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	// Load the vertex array with data.

	vertices[0].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[0].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[1].position = XMFLOAT3(0.5f, -1.0f, 0.0f);  // Bottom right.
	vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[2].position = XMFLOAT3(-0.5f, -1.0f, 0.0f);  // Bottom left. 팔각형
	vertices[2].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);


	vertices[3].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[3].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[4].position = XMFLOAT3(-0.5f, -1.0f, 0.0f);  // Bottom left. 0
	vertices[4].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[5].position = XMFLOAT3(-1.0f, -0.5f, 0.0f);  // Bottom left.
	vertices[5].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);


	vertices[6].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[6].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[7].position = XMFLOAT3(-1.0f, -0.5f, 0.0f);  // Bottom left.
	vertices[7].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[8].position = XMFLOAT3(-1.0f, 0.5f, 0.0f);  // Bottom right.
	vertices[8].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);


	vertices[9].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[9].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[10].position = XMFLOAT3(-1.0f, 0.5f, 0.0f);  // Bottom right. 0 
	vertices[10].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[11].position = XMFLOAT3(-0.5f, 1.0f, 0.0f);  // Bottom left.
	vertices[11].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);


	vertices[12].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[12].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[13].position = XMFLOAT3(-0.5f, 1.0f, 0.0f);  // Bottom left.
	vertices[13].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[14].position = XMFLOAT3(0.5f, 1.0f, 0.0f);  // Bottom right.
	vertices[14].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);


	vertices[15].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[15].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[16].position = XMFLOAT3(0.5f, 1.0f, 0.0f);  // Bottom right.
	vertices[16].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[17].position = XMFLOAT3(1.0f, 0.5f, 0.0f);  // Bottom left.
	vertices[17].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);


	vertices[18].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[18].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[19].position = XMFLOAT3(1.0f, 0.5f, 0.0f);  // Bottom left.
	vertices[19].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	vertices[20].position = XMFLOAT3(1.0f, -0.5f, 0.0f);  // Bottom right.
	vertices[20].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);


	vertices[21].position = XMFLOAT3(0.0f, 0.0f, 0.0f);  // Top middle.
	vertices[21].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[22].position = XMFLOAT3(1.0f, -0.5f, 0.0f);  // Bottom right.
	vertices[22].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	vertices[23].position = XMFLOAT3(0.5f, -1.0f, 0.0f);  // Bottom right.  
	vertices[23].color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);


	vertices[24].position = XMFLOAT3(3.0f, 1.0f, 0.0f);      // 사각형
	vertices[24].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[25].position = XMFLOAT3(2.0f, 0.0f, 0.0f);
	vertices[25].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[26].position = XMFLOAT3(2.0f, 1.0f, 0.0f);
	vertices[26].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);

	vertices[27].position = XMFLOAT3(3.0f, 1.0f, 0.0f);
	vertices[27].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[28].position = XMFLOAT3(4.0f, 1.0f, 0.0f);
	vertices[28].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[29].position = XMFLOAT3(4.0f, 0.0f, 0.0f);
	vertices[29].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);

	vertices[30].position = XMFLOAT3(3.0f, -1.0f, 0.0f);
	vertices[30].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[31].position = XMFLOAT3(4.0f, 0.0f, 0.0f);
	vertices[31].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[32].position = XMFLOAT3(4.0f, -1.0f, 0.0f);
	vertices[32].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);

	vertices[33].position = XMFLOAT3(3.0f, -1.0f, 0.0f);
	vertices[33].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[34].position = XMFLOAT3(2.0f, -1.0f, 0.0f);
	vertices[34].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	vertices[35].position = XMFLOAT3(2.0f, 0.0f, 0.0f);
	vertices[35].color = XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);


	vertices[36].position = XMFLOAT3(-4.0f, 0.5f, 0.0f);    // 다이아몬드
	vertices[36].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[37].position = XMFLOAT3(-3.0f, -1.0f, 0.0f);
	vertices[37].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[38].position = XMFLOAT3(-4.5f, 0.0f, 0.0f);
	vertices[38].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);

	vertices[39].position = XMFLOAT3(-4.0f, 0.5f, 0.0f);
	vertices[39].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[40].position = XMFLOAT3(-2.0f, 0.5f, 0.0f);
	vertices[40].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[41].position = XMFLOAT3(-3.0f, -1.0f, 0.0f);
	vertices[41].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);

	vertices[42].position = XMFLOAT3(-2.0f, 0.5f, 0.0f);
	vertices[42].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[43].position = XMFLOAT3(-1.5f, 0.0f, 0.0f);
	vertices[43].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);
	vertices[44].position = XMFLOAT3(-3.0f, -1.0f, 0.0f);
	vertices[44].color = XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f);


	// Load the index array with data.
	// Create the triangle in the clockwise order (counterclockwise: back face culling).
	indices[0] = 0;  // Bottom left.   // 팔각형
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;
	indices[4] = 4;
	indices[5] = 5;
	indices[6] = 6;
	indices[7] = 7;  // Bottom left.
	indices[8] = 8;  // Bottom right.
	indices[9] = 9;  // Top middle.
	indices[10] = 10;  // Bottom left.
	indices[11] = 11;  // Bottom right.
	indices[12] = 12;  // Top middle.
	indices[13] = 13;  // Bottom left.
	indices[14] = 14;  // Bottom right.
	indices[15] = 15;  // Top middle.
	indices[16] = 16;  // Bottom left.
	indices[17] = 17;  // Bottom right.
	indices[18] = 18;  // Top middle.
	indices[19] = 19;  // Bottom left.
	indices[20] = 20;  // Bottom right.
	indices[21] = 21;  // Top middle.
	indices[22] = 22;  // Bottom left.
	indices[23] = 23;  // Bottom right.  

	indices[24] = 24;  // Top middle.  // 사각형
	indices[25] = 25;  // Bottom left.
	indices[26] = 26;  // Bottom right.
	indices[27] = 27;  // Top middle.
	indices[28] = 28;  // Bottom left.
	indices[29] = 29;  // Bottom right.
	indices[30] = 30;  // Top middle.
	indices[31] = 31;  // Bottom left.
	indices[32] = 32;  // Bottom right.
	indices[33] = 33;  // Top middle.
	indices[34] = 34;  // Bottom left.
	indices[35] = 35;  // Bottom right.

	indices[36] = 36;                 // 다이아몬드
	indices[37] = 37;
	indices[38] = 38;
	indices[39] = 39;
	indices[40] = 40;
	indices[41] = 41;
	indices[42] = 42;
	indices[43] = 43;
	indices[44] = 44;


	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}


void ModelClass::ShutdownBuffers()
{
	// Release the index buffer.
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

// This sets the vertex buffer and index buffer as active on the input assembler in the GPU. 
// Once the GPU has an active vertex buffer, it can then use the shader to render that buffer. 
// This function also defines how those buffers should be drawn such as triangles, lines, fans, 
// and etc using the IASetPrimitiveTopology DirectX function.
void ModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}