#include "image.h"
#include <iostream>

Pixel& Image::at(int x, int y) {
  return data[x][y];
}

bool Image::load(const std::string& filename) {
  std::fstream file(filename, std::fstream::in);
  if (!file) return false;

  std::string line;

  // read magic number
  file >> line;
  if (line != "P3") return false;

  // skip comments / junk lines safely
  auto skipComments = [&](std::fstream& f) {
    while (f >> std::ws && f.peek() == '#') {
      std::getline(f, line);
    }
  };

  skipComments(file);
  file >> width >> height;

  skipComments(file);
  file >> maxColor;

  if (width <= 0 || height <= 0) {
    return false; 
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      file >> data[x][y].r >> data[x][y].g >> data[x][y].b;
    }
  }

  return true;
}

bool Image::save(const std::string& filename) {
  std::fstream file(filename, std::fstream::out);

  file << "P3\n";
  file << width << " " << height << "\n";
  file << maxColor << "\n";

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      file << data[x][y].r << " "
           << data[x][y].g << " "
           << data[x][y].b << " ";
    }
    file << "\n";
  }

  return true;
}
