#pragma once
#include "image.h"
#include "detector.h"
#include <vector>

class Renderer {
public:
  void draw(Image& img, const std::vector<Box>& boxes);

private:
  static constexpr int THRESHOLD = 7660;
};
