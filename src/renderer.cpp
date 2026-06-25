#include "renderer.h"

void Renderer::draw(Image& img, const std::vector<Box>& boxes) {

  for (const auto& b : boxes) {

    bool damaged = b.size < THRESHOLD;

    int r = damaged ? 255 : 0;
    int g = damaged ? 0 : 255;

    for (int x = b.xmin; x <= b.xmax; x++) {
      img.at(x, b.ymin).r = r;
      img.at(x, b.ymin).g = g;

      img.at(x, b.ymax).r = r;
      img.at(x, b.ymax).g = g;
    }

    for (int y = b.ymin; y <= b.ymax; y++) {
      img.at(b.xmin, y).r = r;
      img.at(b.xmin, y).g = g;

      img.at(b.xmax, y).r = r;
      img.at(b.xmax, y).g = g;
    }
  }
}
