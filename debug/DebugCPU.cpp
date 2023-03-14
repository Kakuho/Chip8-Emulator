#include "DebugCPU.hpp"
#include <algorithm>
#include <fstream>
#include <memory>
// constructors // 
DebugCPU::DebugCPU(){
}

DebugCPU::DebugCPU(const CPUState& registerState)
  : CPU(registerState){
  }

/************************************************************************/

const void DebugCPU::PrintState(std::ostream& ost) const{
  ost << "------------------------------------------------------------------";
  ost << "\n";

  ost << "PC: 0x" << std::hex     << std::setfill('0') << std::setw(4) << (unsigned)getPC() 
      << " I: 0x" << std::hex     << std::setfill('0') << std::setw(4) << (unsigned)getIndex() 
      << " SP: 0x" << std::hex    << std::setfill('0') << std::setw(2) << (unsigned)getSP() << "\n\n"
      << "Delay: 0x" << std::hex  << std::setfill('0') << std::setw(2) << (unsigned)getDelay() 
      << " Sound: 0x" << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getSound();


  ost <<  "\n\n";
  ost << "V0: 0x" <<  std::hex << std::setfill('0') << std::setw(2) 
      << (unsigned)getRegister(0x00) 
      << " V4: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x04) 
      << " V8: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x08)
      << " VC: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0C) << '\n'
      << "V1: 0x"   << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x01) 
      << " V5: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x05) 
      << " V9: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x09) 
      << " VD: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0D) << '\n'
      << "V2: 0x"   << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x02) 
      << " V6: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x06) 
      << " VA: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0A)
      << " VE: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0E) << '\n'
      << "V3: 0x"   << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x03) 
      << " V7: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x07) 
      << " VB: 0x"  << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0B)
      << " VF: 0x"   << std::hex << std::setfill('0') << std::setw(2) << (unsigned)getRegister(0x0F) << '\n';

  ost << "\n------------------------------------------------------------------" <<std::endl;
}
