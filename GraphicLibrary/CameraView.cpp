/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "CameraView.hpp"

void helper_set_ndc(matrix3<float>& camtoNDC, CameraView::FrameOfReference frame_reference, vector2<float> display_size, float zoom = 1)
{
	if (frame_reference == CameraView::FrameOfReference::RightHanded_OriginBottomLeft)
	{
		camtoNDC =
		{
			2 / display_size.x * zoom, 0, -1,
			0, 2 / display_size.y * zoom, -1,
			0,0,1
		};

		camtoNDC = MATRIX3::transpose(camtoNDC);
	}
	else if (frame_reference == CameraView::FrameOfReference::RightHanded_OriginCenter)
	{
		camtoNDC =
		{
			2 / display_size.x * zoom, 0, 0,
			0, 2 / display_size.y * zoom, 0,
			0,0,1
		};
		camtoNDC = MATRIX3::transpose(camtoNDC);
	}
	else if (frame_reference == CameraView::FrameOfReference::LeftHanded_OriginTopLeft)
	{
		camtoNDC =
		{
			2 / display_size.x * zoom, 0, -1,
			0, -2 / display_size.y * zoom, 1,
			0,1,1
		};
		camtoNDC = MATRIX3::transpose(camtoNDC);
	}
}

void CameraView::SetViewSize(vector2<float> pixel_size) noexcept
{
	displaySize = pixel_size;
	cameraToNDC = GetCameraToNDCTransform();
	helper_set_ndc(cameraToNDC, frameOfReference, displaySize);
}

void CameraView::SetViewSize(int new_pixel_width, int new_pixel_height) noexcept
{
	displaySize.x = static_cast<float>(new_pixel_width);
	displaySize.y = static_cast<float>(new_pixel_height);
	cameraToNDC = GetCameraToNDCTransform();
	helper_set_ndc(cameraToNDC, frameOfReference, displaySize);
}

void CameraView::SetZoom(float new_zoom) noexcept
{
	zoom = new_zoom;
	cameraToNDC = GetCameraToNDCTransform();
	helper_set_ndc(cameraToNDC, frameOfReference, displaySize, zoom);
}

void CameraView::AddZoom(float new_zoom)
{
	zoom += new_zoom;
	if (zoom > 0.0f)
	{
		cameraToNDC = GetCameraToNDCTransform();
		helper_set_ndc(cameraToNDC, frameOfReference, displaySize, zoom);
	}
	if (zoom < 0.1f)
	{
		zoom = 0.1f;
	}
}

void CameraView::SetFrameOfReference(FrameOfReference frame_of_reference) noexcept
{
	frameOfReference = frame_of_reference;
	cameraToNDC = GetCameraToNDCTransform();
	helper_set_ndc(cameraToNDC, frameOfReference, displaySize);
}