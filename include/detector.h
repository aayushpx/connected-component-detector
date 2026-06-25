#pragma once
#include <vector>
#include "image.h"

struct Box {
  int xmin, xmax, ymin, ymax;
  int size;
};

class Detector {
public:
  std::vector<Box> run(Image& img);

private:
  bool visited[600][600];

  int xmin, xmax, ymin, ymax;
  int total;

  bool isForeground(Image& img, int x, int y);
  void floodFill(Image& img, int x, int y, int w, int h);
};
