#include "PixelBuffer.hpp"
/* Pixel operator overloads */
std::ostream& operator<<(std::ostream& ost, const Pixel& px){
  ost << std::setw(4) << std::setfill(' ') << px.red   << ' ' 
             << std::setw(4) << std::setfill(' ') << px.green << ' ' 
             << std::setw(4) << std::setfill(' ') << px.blue;
  return ost;
}

Pixel& Pixel::operator^=(const Pixel& px2){
  this->red   ^= px2.red;
  this->green ^= px2.green;
  this->blue  ^= px2.blue;
  return *this;
}

/* Pixel Member Functions */

bool Pixel::on() const{
  if(red == 0 && green == 0 && blue == 0)
    return false;
  else 
    return true;
}

/*********************************************************************/

PixelBuffer::PixelBuffer(const unsigned int width, const unsigned int height)
  :width_{width}, height_{height}{
    std::cout << std::dec << getWidth() << ' ' << getHeight() << std::endl;
    unsigned int SZ = width_ * height_;
    pixels = std::vector<Pixel>(SZ);
    nchan = 3;
    for(unsigned int i = 0; i < SZ; i++){
      pixels[i] = Pixel{0, 0, 0};
  }
}

void PixelBuffer::print(std::ostream& ost) const{
  for(int i = 0; i < width_*height_; i++){
    ost << std::setw(4) << std::setfill(' ') << i << '|' << pixels[i] << '\n';
  }
}

const unsigned int PixelBuffer::indx(const unsigned int x, 
                                     const unsigned int y) const{
  if(x > width_){
    std::cout << "x out of bounds. we do modulo\n";
  }
  if(y > height_){
    std::cout << "y out of bounds. we do modulo\n";
  }
  return (y % height_) *width_ + (x % width_);
}

// getters and setters for pixels

const Pixel& PixelBuffer::PixelRef(const unsigned int x, const unsigned int y) const{
  return pixels[indx(x,y)];
}

Pixel& PixelBuffer::GetPixel(const unsigned int x, 
                                const unsigned int y){
  return pixels[indx(x, y)];
}

void PixelBuffer::SetPixel(const unsigned int x, const unsigned int y, 
                           const Pixel& px){
  pixels[indx(x, y)] = px;
}

// pixel manipulators

void PixelBuffer::TurnOff(){
  // function to set all the pixels to black.
  for(int i = 0; i < pixels.size(); i++){
    pixels[i] = Pixel{0, 0, 0};
  }
}

void PixelBuffer::TurnOn(){
  for(int i = 0; i < pixels.size(); i++){
    pixels[i] = Pixel{255, 255, 255};
  }
}


const bool PixelBuffer::PixelOn(const unsigned int x, const unsigned int y) 
  const{
    if(PixelRef(x, y).on()){
      return true;
    }
    else{
      return false;
    }
}

const bool PixelBuffer::PixelOff(const unsigned int x, const unsigned int y) 
  const{
    if(PixelRef(x, y).on()){
      return false;
    }
    else{
      return true;
    }
}

// drawing functions 

void PixelBuffer::printASCII() const{
  for(int row = 0; row < height_; row++){
    for(int col = 0; col < width_; col++){
      if(PixelRef(col, row).on()){
        std::cout << "*";
      }
      else{
        std::cout << "0";
      }
    }
    std::cout << '\n';
  }
}

void PixelBuffer::drawBMP() const{
  std::ofstream ofst{"output.pbm", std::ios_base::binary};
  ofst << 'P'   << 6   << std::endl 
       << width_ << ' ' << height_ << std::endl
       << 255   << std::endl; 
  for(int i = 0; i < pixels.size(); i++){
    ofst << (char)pixels[i].red
         << (char)pixels[i].green
         << (char)pixels[i].blue;
  }
}

void PixelBuffer::printData(){
  const unsigned char* raw_data = data();
  for(int i = 0; i < width_ * height_; i++){
    std::cout << raw_data[i] << '\n';
  }
}

// Copying functions // 

std::vector<unsigned char> PixelBuffer::cpPixels() const{
  std::vector<unsigned char> data(width_ * height_ * nchan);
  int dataIndex = 0;
  for(int i = 0; i < pixels.size(); i++){
    data[dataIndex] = pixels[i].red;
    data[dataIndex+1] = pixels[i].green;
    data[dataIndex+2] = pixels[i].blue;
    dataIndex+=3;
  }
  return data;
}

const unsigned char* PixelBuffer::data() const{
  std::vector<unsigned char> raw_data(width_ * height_ * nchan);
  int dataIndex = 0;
  for(int i = 0; i < pixels.size(); i++){
    raw_data[dataIndex]   = pixels[i].red;
    raw_data[dataIndex+1] = pixels[i].green;
    raw_data[dataIndex+2] = pixels[i].blue;
    dataIndex+=3;
  }
  //printASCII();
  return raw_data.data();
}
