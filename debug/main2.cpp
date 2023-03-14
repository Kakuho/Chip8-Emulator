// program to test if the pixel buffer object allocate information as expected.
#include <exception>
#include "./../System.hpp"

int main(){
  try{
    /*
    System chip8{"./Pong.ch8"};
    chip8.Run();
    */
    PixelBuffer pbo{64, 32};
    pbo.printASCII();
    char ch = '0';
    int y = 0;
    int x = 0;
    while(ch != 'd'){
      if(ch == 'j'){
        if(y < 32){
          y+=1;
        }
        pbo.setPixel(x, y, Pixel{255, 255, 255});
        std::cout << "(x, y) == (" << x << ", " << y << ")\n";

      }
      if(ch == 'k'){
        if(y > 0){
          y-=1;
        }
        pbo.setPixel(x, y, Pixel{255, 255, 255});
        std::cout << "(x, y) == (" << x << ", " << y << ")\n";
      }
      if(ch == 'l'){
        if(x < 64){
          x+=1;
        }
        pbo.setPixel(x, y, Pixel{255, 255, 255});
        std::cout << "(x, y) == (" << x << ", " << y << ")\n";
      }
      if(ch == 'h'){
        if(x > 0){
          x-=1;
        }
        pbo.setPixel(x, y, Pixel{255, 255, 255});
        std::cout << "(x, y) == (" << x << ", " << y << ")\n";
      }
      pbo.printASCII();
      std::cin >> ch;
    }
    pbo.clear_pixels();
    pbo.printASCII();
  }
  catch(std::exception& e){
  }
}
