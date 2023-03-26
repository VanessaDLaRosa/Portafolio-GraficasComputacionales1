////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
	m_Texture = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(OpenGLClass* OpenGL, char* textureFilename, 
	unsigned int textureUnit, bool wrap)
{
	bool result;


	// Initialize the vertex and index buffer that hold the geometry for the triangle.
	result = InitializeBuffers(OpenGL);
	if(!result)
	{
		return false;
	}

	// Load the texture for this model.
	result = LoadTexture(OpenGL, textureFilename, textureUnit, wrap);
	if(!result)
	{
		return false;
	}

	return true;
}


void ModelClass::Shutdown(OpenGLClass* OpenGL)
{
	// Release the texture used for this model.
	ReleaseTexture();

	// Release the vertex and index buffers.
	ShutdownBuffers(OpenGL);

	return;
}


void ModelClass::Render(OpenGLClass* OpenGL)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(OpenGL);

	return;
}


bool ModelClass::InitializeBuffers(OpenGLClass* OpenGL)
{
	VertexType* vertices;
	unsigned int* indices;


	// Set the number of vertices in the vertex array.
	m_vertexCount = 24;

	// Set the number of indices in the index array.
	m_indexCount = 36;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if(!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned int[m_indexCount];
	if(!indices)
	{
		return false;
	}

	// Load the vertex array with data.

	//Cara1
	// Bottom left.
	vertices[0].x = -1.0f;  // Position.
	vertices[0].y = -1.0f;
	vertices[0].z =  -1.0f;

	vertices[0].tu = 0.0f;  // Texture coordinates.
	vertices[0].tv = 0.33f;

	// Top middle.
	vertices[1].x = -1.0f;  // Position.
	vertices[1].y = 1.0f;
	vertices[1].z = -1.0f;

	vertices[1].tu = 0.0f;  // Texture coordinates.
	vertices[1].tv = 0.66f;

	// Bottom right.
	vertices[2].x =  1.0f;  // Position.
	vertices[2].y =  1.0f;
	vertices[2].z =  -1.0f;

	vertices[2].tu = 0.25f;  // Texture coordinates.
	vertices[2].tv = 0.66f;

	// Bottom right.
	vertices[3].x = 1.0f;  // Position.
	vertices[3].y = -1.0f;
	vertices[3].z = -1.0f;

	vertices[3].tu = 0.25f;  // Texture coordinates.
	vertices[3].tv = 0.33f;

	//Cara2
	// Bottom right.
	vertices[4].x = 1.0f;  // Position.
	vertices[4].y = -1.0f;
	vertices[4].z = -1.0f;

	vertices[4].tu = 0.25f;  // Texture coordinates.
	vertices[4].tv = 0.33f;

	// Bottom right.
	vertices[5].x = 1.0f;  // Position.
	vertices[5].y = 1.0f;
	vertices[5].z = -1.0f;

	vertices[5].tu = 0.25f;  // Texture coordinates.
	vertices[5].tv = 0.66f;

	// Bottom right.
	vertices[6].x = 1.0f;  // Position.
	vertices[6].y = 1.0f;
	vertices[6].z = 1.0f;

	vertices[6].tu = 0.5f;  // Texture coordinates.
	vertices[6].tv = 0.66f;

	// Bottom right.
	vertices[7].x = 1.0f;  // Position.
	vertices[7].y = -1.0f;
	vertices[7].z = 1.0f;

	vertices[7].tu = 0.5f;  // Texture coordinates.
	vertices[7].tv = 0.33f;

	//Cara3
	// Bottom right.
	vertices[8].x = 1.0f;  // Position.
	vertices[8].y = -1.0f;
	vertices[8].z = 1.0f;

	vertices[8].tu = 0.5f;  // Texture coordinates.
	vertices[8].tv = 0.33f;

	// Bottom right.
	vertices[9].x = 1.0f;  // Position.
	vertices[9].y = 1.0f;
	vertices[9].z = 1.0f;

	vertices[9].tu = 0.5f;  // Texture coordinates.
	vertices[9].tv = 0.66f;

	// Bottom right.
	vertices[10].x = -1.0f;  // Position.
	vertices[10].y = 1.0f;
	vertices[10].z = 1.0f;

	vertices[10].tu = 0.75f;  // Texture coordinates.
	vertices[10].tv = 0.66f;

	// Bottom left.
	vertices[11].x = -1.0f;  // Position.
	vertices[11].y = -1.0f;
	vertices[11].z = 1.0f;

	vertices[11].tu = 0.75f;  // Texture coordinates.
	vertices[11].tv = 0.33f;

	//Cara4
	// Bottom right.
	vertices[12].x = -1.0f;  // Position.
	vertices[12].y = -1.0f;
	vertices[12].z = 1.0f;

	vertices[12].tu = 0.75f;  // Texture coordinates.
	vertices[12].tv = 0.33f;

	// Bottom right.
	vertices[13].x = -1.0f;  // Position.
	vertices[13].y = 1.0f;
	vertices[13].z = 1.0f;

	vertices[13].tu = 0.75f;  // Texture coordinates.
	vertices[13].tv = 0.66f;

	// Bottom right.
	vertices[14].x = -1.0f;  // Position.
	vertices[14].y = 1.0f;
	vertices[14].z = -1.0f;

	vertices[14].tu = 1.0f;  // Texture coordinates.
	vertices[14].tv = 0.66f;

	// Bottom left.
	vertices[15].x = -1.0f;  // Position.
	vertices[15].y = -1.0f;
	vertices[15].z = -1.0f;

	vertices[15].tu = 1.0f;  // Texture coordinates.
	vertices[15].tv = 0.33f;

	//Cara5
	// Bottom left.
	vertices[16].x = -1.0f;  // Position.
	vertices[16].y = 1.0f;
	vertices[16].z = -1.0f;

	vertices[16].tu = 0.0f;  // Texture coordinates.
	vertices[16].tv = 0.66f;

	// Top middle.
	vertices[17].x = -1.0f;  // Position.
	vertices[17].y = 1.0f;
	vertices[17].z = 1.0f;

	vertices[17].tu = 0.0f;  // Texture coordinates.
	vertices[17].tv = 1.0f;

	// Bottom left.
	vertices[18].x = 1.0f;  // Position.
	vertices[18].y = 1.0f;
	vertices[18].z = 1.0f;

	vertices[18].tu = 0.25f;  // Texture coordinates.
	vertices[18].tv = 1.0f;

	// Top middle.
	vertices[19].x = 1.0f;  // Position.
	vertices[19].y = 1.0f;
	vertices[19].z = -1.0f;

	vertices[19].tu = 0.25f;  // Texture coordinates.
	vertices[19].tv = 0.66f;

	//Cara6
	// Bottom left.
	vertices[20].x = -1.0f;  // Position.
	vertices[20].y = -1.0f;
	vertices[20].z = 1.0f;

	vertices[20].tu = 0.0f;  // Texture coordinates.
	vertices[20].tv = 0.0f;

	// Bottom left.
	vertices[21].x = -1.0f;  // Position.
	vertices[21].y = -1.0f;
	vertices[21].z = -1.0f;

	vertices[21].tu = 0.0f;  // Texture coordinates.
	vertices[21].tv = 0.33f;

	// Bottom right.
	vertices[22].x = 1.0f;  // Position.
	vertices[22].y = -1.0f;
	vertices[22].z = -1.0f;

	vertices[22].tu = 0.25f;  // Texture coordinates.
	vertices[22].tv = 0.33f;

	// Bottom right.
	vertices[23].x = 1.0f;  // Position.
	vertices[23].y = -1.0f;
	vertices[23].z = 1.0f;

	vertices[23].tu = 0.25f;  // Texture coordinates.
	vertices[23].tv = 0.0f;

	// Top middle.
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top middle.
	indices[2] = 3;  // Bottom right.

	indices[3] = 1;  // Bottom left.
	indices[4] = 2;  // Top middle.
	indices[5] = 3;  // Bottom right.

	//Cara2
	indices[6] = 4;  // Bottom left.
	indices[7] = 5;  // Top middle.
	indices[8] = 7;  // Bottom right.

	indices[9] = 5;  // Bottom left.
	indices[10] = 6;  // Top middle.
	indices[11] = 7;  // Bottom right.

	//Cara3
	indices[12] = 8;  // Bottom left.
	indices[13] = 9;  // Top middle.
	indices[14] = 11;  // Bottom right.

	indices[15] = 9;  // Bottom left.
	indices[16] = 10;  // Top middle.
	indices[17] = 11;  // Bottom right.

	//Cara4
	indices[18] = 12;  // Bottom left.
	indices[19] = 13;  // Top middle.
	indices[20] = 15;  // Bottom right.

	indices[21] = 13;  // Bottom left.
	indices[22] = 14;  // Top middle.
	indices[23] = 15;  // Bottom right.

	//Cara5
	indices[24] = 16;  // Bottom left.
	indices[25] = 17;  // Top middle.
	indices[26] = 19;  // Bottom right.

	indices[27] = 17;  // Bottom left.
	indices[28] = 18;  // Top middle.
	indices[29] = 19;  // Bottom right.

	//Cara6
	indices[30] = 20;  // Bottom left.
	indices[31] = 21;  // Top middle.
	indices[32] = 23;  // Bottom right.

	indices[33] = 21;  // Bottom left.
	indices[34] = 22;  // Top middle.
	indices[35] = 23;  // Bottom right.


	// Allocate an OpenGL vertex array object.
	OpenGL->glGenVertexArrays(1, &m_vertexArrayId);

	// Bind the vertex array object to store all the buffers and vertex attributes we create here.
	OpenGL->glBindVertexArray(m_vertexArrayId);

	// Generate an ID for the vertex buffer.
	OpenGL->glGenBuffers(1, &m_vertexBufferId);

	// Bind the vertex buffer and load the vertex (position and texture) data into the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(VertexType), vertices, GL_STATIC_DRAW);

	// Enable the two vertex array attributes.
	OpenGL->glEnableVertexAttribArray(0);  // Vertex position.
	OpenGL->glEnableVertexAttribArray(1);  // Texture coordinates.

	// Specify the location and format of the position portion of the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(VertexType), 0);

	// Specify the location and format of the texture coordinate portion of the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(VertexType), (unsigned char*)NULL + (3 * sizeof(float)));

	// Generate an ID for the index buffer.
	OpenGL->glGenBuffers(1, &m_indexBufferId);

	// Bind the index buffer and load the index data into it.
	OpenGL->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferId);
	OpenGL->glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount* sizeof(unsigned int), indices, GL_STATIC_DRAW);
	
	// Now that the buffers have been loaded we can release the array data.
	delete [] vertices;
	vertices = 0;

	delete [] indices;
	indices = 0;

	return true;
}


void ModelClass::ShutdownBuffers(OpenGLClass* OpenGL)
{
	// Disable the two vertex array attributes.
	OpenGL->glDisableVertexAttribArray(0);
	OpenGL->glDisableVertexAttribArray(1);
	
	// Release the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OpenGL->glDeleteBuffers(1, &m_vertexBufferId);

	// Release the index buffer.
	OpenGL->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OpenGL->glDeleteBuffers(1, &m_indexBufferId);

	// Release the vertex array object.
	OpenGL->glBindVertexArray(0);
	OpenGL->glDeleteVertexArrays(1, &m_vertexArrayId);

	return;
}


void ModelClass::RenderBuffers(OpenGLClass* OpenGL)
{
	// Bind the vertex array object that stored all the information about the vertex and index buffers.
	OpenGL->glBindVertexArray(m_vertexArrayId);

	// Render the vertex buffer using the index buffer.
	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

	return;
}


bool ModelClass::LoadTexture(OpenGLClass* OpenGL, char* textureFilename, 
	unsigned int textureUnit, bool wrap)
{
	bool result;


	// Create the texture object.
	m_Texture = new TextureClass;
	if(!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialize(OpenGL, textureFilename, textureUnit, wrap);
	if(!result)
	{
		return false;
	}

	return true;
}


void ModelClass::ReleaseTexture()
{
	// Release the texture object.
	if(m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}

	return;
}