#pragma once
#include "matrix3.hpp"
#include "Camera.hpp"
#include "CameraView.hpp"

class View
{
private:
	Camera camera{};
	CameraView cameraView{};
	matrix3<float> ndc;

public:
	void Init();
	void Update(float dt);
	Camera& GetCamera();
	CameraView& GetCameraView();
	matrix3<float> GetNDC();

};