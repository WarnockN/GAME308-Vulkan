#ifndef SCENE0_H
#define SCENE0_H
#include "Scene.h"
#include "Vector.h"
#include "Renderer.h"
#include "Camera.h"

using namespace MATH;
using namespace std;

/// Forward declarations 
union SDL_Event;


class Scene0 : public Scene {
private:
	Renderer* renderer;
	Camera* camera;
	Matrix4 marioModelMatrix;
	//Vec4 lightPos;
	Vec4 lightPos[2];

	//mouse moved?
	bool mouseMotion = false;
	
public:
	explicit Scene0(Renderer* renderer_);
	virtual ~Scene0();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE0_H