#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene0.h"
#include "MMath.h"
#include "Debug.h"
#include "VulkanRenderer.h"

Scene0::Scene0(Renderer *renderer_) : Scene(nullptr), renderer(renderer_), camera(nullptr) {
	camera = new Camera(45.0f, 1.7777779f, 0.5f, 20.0f);
	
	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
}

Scene0::~Scene0() {}

bool Scene0::OnCreate() {
	int width = 0, height = 0;
	float aspectRatio;
	
	switch (renderer->getRendererType()){
	case RendererType::VULKAN:
		
		SDL_SetRelativeMouseMode(SDL_TRUE);

		SDL_GetWindowSize(dynamic_cast<VulkanRenderer*>(renderer)->GetWindow(), &width, &height);
		aspectRatio = static_cast<float>(width) / static_cast<float>(height);
		camera->Perspective(45.0f, aspectRatio, 0.5, 20.0f);
		camera->SetPosition(Vec3(0.0f, 0.0f, -5.0f));
		camera->SetOrientation(0.0f, Vec3(0.0f, 1.0f, 0.0f));
		//lightPos = Vec4(0.0f, 0.0f, 5.0f, 1.0f);
		lightPos[0] = Vec4(5.0f, 0.0f, -4.0f, 1.0f);
		lightPos[1] = Vec4(-5.0f, 0.0f, -4.0f, 1.0f);
		break;

	case RendererType::OPENGL:
		break;
	}

	

	return true;
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {
	///TODO make that shit work
	if (sdlEvent.type == SDL_WINDOWEVENT) {
		switch (sdlEvent.window.event) {
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			printf("Size changed &d &d\n", sdlEvent.window.data1, sdlEvent.window.data2);
			float aspectRatio = static_cast<float>(sdlEvent.window.data1) / static_cast<float>(sdlEvent.window.data2);
			camera->Perspective(45.0f, aspectRatio, 0.5, 20.0f);
			break;
		}
	}

	/*else if (sdlEvent.type == SDL_MOUSEMOTION && sdlEvent.button.button == SDL_BUTTON(SDL_BUTTON_RIGHT)) {
		mouseMotion = true;
		sdlEvent.motion.xrel
		sdlEvent.motion.yrel
	}*/
}

void Scene0::Update(const float deltaTime) {
	static float totalTime = 0.0f;
	totalTime += deltaTime;

	marioModelMatrix = /*/MMath::translate(Vec3(0.0, 0.0, 0.0)) * */ MMath::rotate(totalTime * 90.0f, Vec3(0.0f, 1.0f, 0.0f));
}

void Scene0::Render() const {
	switch (renderer->getRendererType()) {

	case RendererType::VULKAN:
		VulkanRenderer* vRenderer;
		vRenderer = dynamic_cast<VulkanRenderer*>(renderer);
		vRenderer->SetCameraUBO(camera->GetProjectionMatrix(), camera->GetViewMatrix());
		vRenderer->SetModelUBO(marioModelMatrix, &lightPos[0]);
		vRenderer->Render();
		break;

	case RendererType::OPENGL:
		/// Clear the screen
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		/// Draw your scene here
		
		
		glUseProgram(0);
		
		break;
	}
}


void Scene0::OnDestroy() {
	delete camera;
	camera = nullptr;
}
