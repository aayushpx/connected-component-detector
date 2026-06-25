#pragma once
#include <fstream>

class Pixel {
public:
  int r, g, b;
};

class Image {
public:
  int width, height, maxColor;
  Pixel data[600][600];

  bool load(const std::string& filename);
  bool save(const std::string& filename);

  Pixel& at(int x, int y);
};
