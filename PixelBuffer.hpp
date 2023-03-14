#ifndef PIXEL_BUFFER_HPP
#define PIXEL_BUFFER_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <exception>

class Pixel{
  public:
  Pixel():
    red{0}, blue{0}, green{0}{}

  Pixel(int Red, int Green, int Blue):
    red{Red}, blue{Blue}, green{Green}{}

  int red;
  int green;
  int blue;

  virtual bool on() const;
  Pixel& operator^=(const Pixel& p2);
};

class PixelBuffer{
  public:
  PixelBuffer(const unsigned int width, const unsigned int height);
  PixelBuffer(const PixelBuffer&);
  // utilities
  const unsigned int indx(const unsigned int x, const unsigned int y) const;
  // getter and setters
  const Pixel& PixelRef(const unsigned int x, const unsigned int y) const;
  Pixel& GetPixel(const unsigned int x, const unsigned int y);
  void SetPixel(const unsigned int x, const unsigned int y, const Pixel& px);
  // pixel manipulators
  void TurnOff();
  void TurnOn();
  const bool PixelOn(const unsigned int x, const unsigned int y) const;
  const bool PixelOff(const unsigned int x, const unsigned int y) const;
  // frame size information
  const int getHeight() const{return height_;}
  const int getWidth() const{return width_;}
  // drawing functions
  void printASCII() const;
  void drawBMP() const;
  void print(std::ostream& ost) const;
  void printData();
  // copying functions
  std::vector<unsigned char> cpPixels()const;
  const unsigned char* data() const;
  unsigned char* GetRawData();

  private:
  std::vector<Pixel> pixels;
  unsigned int width_ = 0;
  unsigned int height_ = 0;
  int nchan;
  // prevent copying
  PixelBuffer& operator=(const PixelBuffer& PBO);
};

#endif
