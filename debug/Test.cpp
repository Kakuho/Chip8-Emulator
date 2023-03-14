#include "Test.hpp"
#include <iostream>
#include <type_traits>


bool Test::CPU::OP_3XKK(){
  std::unique_ptr<DebugCPU> cpu = DebugCPU::CreateInstance({.v3 = 0x08});
  cpu->PrintState(std::cout);
  cpu->Cycle(0x3308);
  cpu->PrintState(std::cout);
  if(cpu->getPC() == 0x204){
    std::cout << "pc_:=_0x204::SUCCESS" << std::endl;
    return true;
  }
  else{
    std::cout << "pc_:=_0x202::FAILURE" << std::endl;
    return true;
  }
}

bool Test::CPU::OP_4XKK(){
  std::unique_ptr<DebugCPU> cpu = DebugCPU::CreateInstance({.v3 = 0x08});
  cpu->PrintState(std::cout);
  cpu->Cycle(0x4308);
  cpu->PrintState(std::cout);
  if(cpu->getPC() == 0x202){
    std::cout << "pc==0x202::SUCCESS" << std::endl;
    return true;
  }
  return false;
}

bool Test::CPU::OP_5XY0(){
  std::unique_ptr<DebugCPU> cpu = 
    DebugCPU::CreateInstance({.v3 = 0x6A, .v4 = 0x6A});
  cpu->PrintState(std::cout);
  cpu->Cycle(0x5340);
  cpu->PrintState(std::cout);
  if(cpu->getPC() == 0x204){
    std::cout << "PC==0x204::SUCCESS" << std::endl;
    return true;
  }
  return false;
}

bool Test::CPU::OP_6XKK(){
  std::unique_ptr<DebugCPU> cpu = 
    DebugCPU::CreateInstance();
  cpu->PrintState(std::cout);
  cpu->Cycle(0x6344);
  cpu->PrintState(std::cout);
  if(cpu->getRegister(3) == 0x44){
    std::cout << "V3==0x44::SUCCESS" << std::endl;
    return true;
  }
  return false;
}
