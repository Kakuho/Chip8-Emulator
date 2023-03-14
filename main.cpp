#include "GraphicsManager.hpp"
#include "System.hpp"
#include "CPU.hpp"
#include "MMU.hpp"
#include <algorithm>
#include <memory>

int main(){
  std::shared_ptr<MMU>mum = std::make_shared<MMU>("./../Pong.ch8");
  mum->PrintROM(std::cout);
  //CPU cpu{mum};

  System Chip8{"./../Pong.ch8"};
  Chip8.Run();
}
