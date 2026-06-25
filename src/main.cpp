#include "image.h"
#include "detector.h"
#include "renderer.h"
#include <iostream>

int main() {

  Image img;

  if (!img.load("images/Buttons.ppm")) {
    std::cout << "Failed to load image\n";
    return 1;
  }

  Detector detector;
  Renderer renderer;

  auto boxes = detector.run(img);

  renderer.draw(img, boxes);

  img.save("images/output.ppm");

  return 0;
}
