#include "System.hpp"
#include <memory>

System::System(const std::string& ROM_name){
  mmu_ = std::make_shared<MMU>(ROM_name);
  cpu_ = std::make_unique<CPU>(mmu_);
  graphicsManager_ = std::make_unique<GraphicsManager>(mmu_);
  std::cout << "END_INIT_SYSTEM" << std::endl;
}

void System::Run(){
  while(!graphicsManager_->ShouldClose()){
    uint16_t opcode = mmu_->GetByte(cpu_->getPC());
      opcode <<= 8;
      opcode |= (mmu_->GetByte(cpu_->getPC() + 0x01));
      //(mmu_->GetByte(cpu_->getPC()+1) << 8) | (mmu_->GetByte(cpu_->getPC()));
    cpu_->PrintState(std::cout);
    /*mmu_->printRawData();*/
    mmu_->PrintKeyState();
    std::cout << std::hex << cpu_->getPC() << '\n'
              << std::hex << (unsigned)mmu_->GetByte(cpu_->getPC()) << '\n'
              << std::hex << (unsigned)mmu_->GetByte(cpu_->getPC() + 0x01) << '\n';
    std::cout << std::hex << opcode << std::endl;
    graphicsManager_->ProcessInput();
    cpu_->Cycle(opcode);   /* cycle contains decode and execute instructions */
    graphicsManager_->PollEvents();
    /*mmu_->printASCII(); */
    graphicsManager_->Render();
  }
}
