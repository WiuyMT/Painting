// <Copyright> Minh Tran 2018 CSCI 3081W

#include <cmath>

#include "imagetools/convolution_filter_blur.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterBlur::ConvolutionFilterBlur(float radius) : radius_(radius) {}

ConvolutionFilterBlur::ConvolutionFilterBlur() : radius_(5.0) {}

ConvolutionFilterBlur::~ConvolutionFilterBlur() {}

FloatMatrix* ConvolutionFilterBlur::CreateKernel() {
  FloatMatrix* kernel =
      new FloatMatrix(round(radius_ * 2.0) + 1, round(radius_ * 2.0) + 1);

  for (int j = 0; j < kernel->height(); j++) {
    for (int i = 0; i < kernel->width(); i++) {
      int x = i - kernel->width() / 2;
      int y = j - kernel->height() / 2;
      float dist = sqrt(x * x + y * y);
      float intensity = ImageToolsMath::Gaussian(dist, radius_);
      kernel->set_value(i, j, intensity);
    }
  }
  kernel->Normalize();

  return kernel;
}

bool ConvolutionFilterBlur::convolve_alpha() const { return true; }

float ConvolutionFilterBlur::radius() { return radius_; }

void ConvolutionFilterBlur::set_radius(float r) {
  radius_ = r;
  if (radius_ < 1.0) {
    radius_ = 1.0;
  }
}

}  // namespace image_tools
