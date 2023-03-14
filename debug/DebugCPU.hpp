// class for debugging the cpu

#ifndef DEBUG_CPU_H
#define DEBUG_CPU_H

#include <memory>
#include <iostream>
#include <fstream>
#include <array>
#include <limits.h>         // for detecting overflow of uint8_t
#include <ostream>
#include "./../CPU.hpp"

class DebugCPU: public CPU{
  public:
    // constructors and Deconstructors // 
    DebugCPU();
    DebugCPU(const CPUState& RegisterState);
    // debug functions // 
    const void PrintState(std::ostream& ofst) const;
    static std::unique_ptr<DebugCPU> 
      CreateInstance(const CPUState& registerState){
        std::unique_ptr<DebugCPU> instanceCPU(new DebugCPU(registerState));
        return instanceCPU;
    }
    static std::unique_ptr<DebugCPU> 
      CreateInstance(){
        return std::unique_ptr<DebugCPU>(new DebugCPU());
    }
};

#endif
