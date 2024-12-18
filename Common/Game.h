#pragma once
#include <glm/vec2.hpp>
#include <vector>

#ifdef WINDOWS_BUILD
#include <GLFW/glfw3.h>

#else
#include <GLES2/gl2.h>

#endif
struct ImFont;
#include "btBulletDynamicsCommon.h"


#ifdef Raspberry_BUILD
#include <GLES3/gl3.h>
#endif

#ifdef WINDOWS_BUILD
#include "glad/glad.h"
#endif



class GameObject;
class IGraphics;
class Input;

constexpr unsigned int WINDOW_WIDTH = 1024;
constexpr unsigned int WINDOW_HEIGHT = 768;
constexpr float ASPECT_RATIO = 1024.0f / 768.0f;

class Game
{
public:
	Game(const Input* const input, IGraphics* graphics);
	virtual ~Game();
	void Start(); 
	btDiscreteDynamicsWorld* World() const;
	const Input& GetInput() const;
	void Quit();
protected:
	void ProcessInput();
	virtual void Update(float /*gameDeltaTime*/) {}
	virtual void Render() {}
	virtual void PostRender() {}
	
	const Input* const input;
	bool quitting{false};
	float gameDeltaTime;

	btDefaultCollisionConfiguration* configuration;
	btDbvtBroadphase* pairCache;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* constraintSolver;
	btDiscreteDynamicsWorld* world;
	IGraphics* graphics;


private:
	void InitializeOpenGLES();
	void ClearScreen();

	int frameCount{0};
};

