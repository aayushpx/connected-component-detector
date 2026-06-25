#include "detector.h"
#include <cstring>

static const int THRESHOLD = 128;

bool Detector::isForeground(Image& img, int x, int y) {
  return img.at(x, y).r > THRESHOLD;
}

void Detector::floodFill(Image& img, int x, int y, int w, int h) {

  if (x < 0 || y < 0 || x >= w || y >= h) return;
  if (visited[x][y]) return;
  if (!isForeground(img, x, y)) return;

  visited[x][y] = true;

  total++;

  if (x < xmin) xmin = x;
  if (x > xmax) xmax = x;
  if (y < ymin) ymin = y;
  if (y > ymax) ymax = y;

  floodFill(img, x - 1, y, w, h);
  floodFill(img, x + 1, y, w, h);
  floodFill(img, x, y - 1, w, h);
  floodFill(img, x, y + 1, w, h);
}

std::vector<Box> Detector::run(Image& img) {

  memset(visited, 0, sizeof(visited));

  std::vector<Box> boxes;

  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {

      if (!visited[x][y] && isForeground(img, x, y)) {

        xmin = xmax = x;
        ymin = ymax = y;
        total = 0;

        floodFill(img, x, y, img.width, img.height);

        Box b;
        b.xmin = xmin;
        b.xmax = xmax;
        b.ymin = ymin;
        b.ymax = ymax;
        b.size = total;

        boxes.push_back(b);
      }
    }
  }

  return boxes;
}
