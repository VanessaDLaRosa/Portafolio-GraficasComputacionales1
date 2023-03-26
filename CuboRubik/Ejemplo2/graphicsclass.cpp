////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_OpenGL = 0;
	m_Camera = 0;
	m_Model = 0;
	m_TextureShader = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(OpenGLClass* OpenGL, HWND hwnd)
{
	bool result;


	// Store a pointer to the OpenGL class object.
	m_OpenGL = OpenGL;

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	// Create the model object.
	m_Model = new ModelClass;
	if(!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_OpenGL, (char*)"data/CuboRubikTextura.tga", 0, true);
	if(!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the model object.", (LPCSTR)"Error", MB_OK);
		return false;
	}
	
	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if(!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_OpenGL, hwnd);
	if(!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the texture shader object.", (LPCSTR)"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the texture shader object.
	if(m_TextureShader)
	{
		m_TextureShader->Shutdown(m_OpenGL);
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	// Release the model object.
	if(m_Model)
	{
		m_Model->Shutdown(m_OpenGL);
		delete m_Model;
		m_Model = 0;
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the pointer to the OpenGL class object.
	m_OpenGL = 0;

	return;
}


bool GraphicsClass::Frame()
{
	bool result;


	// Render the graphics scene.
	result = Render();
	if(!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render()
{
	float worldMatrix[16];
	float viewMatrix[16];
	float projectionMatrix[16];


	// Clear the buffers to begin the scene.
	m_OpenGL->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the opengl and camera objects.
	static float angulo = 3.1415;
	angulo += 0.03;
	m_OpenGL->GetWorldMatrix(worldMatrix);
	m_OpenGL->MatrixRotationX(worldMatrix, angulo);
	m_OpenGL->MatrixRotationY(worldMatrix, angulo);
	m_OpenGL->MatrixRotationZ(worldMatrix, angulo);
	m_Camera->GetViewMatrix(viewMatrix);
	m_OpenGL->GetProjectionMatrix(projectionMatrix);

	// Set the texture shader as the current shader program and set the matrices that it will use for rendering.
	m_TextureShader->SetShader(m_OpenGL);
	m_TextureShader->SetShaderParameters(m_OpenGL, worldMatrix, viewMatrix, projectionMatrix, 0,0);

	// Render the model using the texture shader.
	m_Model->Render(m_OpenGL);
	
	// Present the rendered scene to the screen.
	m_OpenGL->EndScene();

	return true;
}