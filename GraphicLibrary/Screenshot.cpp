/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include <GL/glew.h>
#include "Screenshot.hpp"

	Image capture_screenshot_of_back_buffer_to_image(int pixels_width, int pixels_height, int left_x,
		int bottom_y) noexcept
	{
		Image pixel;
		pixel.ResizeToPixelWidthHeight(pixels_width, pixels_height);
		glReadBuffer(GL_BACK_LEFT);
		if (glReadnPixels != nullptr)
		{
			glReadnPixels(left_x, bottom_y, pixels_width, pixels_height, GL_RGBA, GL_UNSIGNED_BYTE, pixel.GetPixelsBufferBytesSize(), pixel.GetPixelsPointer());
		}
		else
		{
			glReadPixels(left_x, bottom_y, pixels_width, pixels_height, GL_RGBA, GL_UNSIGNED_BYTE, pixel.GetPixelsPointer());
		}
		pixel.FlipVertically();
		return pixel;
	}
