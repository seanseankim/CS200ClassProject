/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "matrix3.hpp"
#include "vector2.hpp"

class [[nodiscard]] CameraView
{
public:
	void            SetViewSize(vector2<float> pixel_size) noexcept;
	void            SetViewSize(int new_pixel_width, int new_pixel_height) noexcept;
	void            SetZoom(float new_zoom) noexcept;
	constexpr float GetZoom() const noexcept { return zoom; }
	matrix3<float>         GetCameraToNDCTransform() const noexcept { return cameraToNDC; }
	void            AddZoom(float new_zoom);
	enum class FrameOfReference
	{
		RightHanded_OriginCenter,
		RightHanded_OriginBottomLeft,
		LeftHanded_OriginTopLeft,
		NormalizedDeviceCoordinates
	};
	void                       SetFrameOfReference(FrameOfReference frame_of_reference) noexcept;
	constexpr FrameOfReference GetFrameOfReference() const noexcept { return frameOfReference; }

private:
	vector2<float>          displaySize{};
	matrix3<float>          cameraToNDC = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	float            zoom{0.5f};
	FrameOfReference frameOfReference = FrameOfReference::RightHanded_OriginCenter;
};