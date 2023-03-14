#ifndef CPU_HPP
#define CPU_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <limits.h>         // for detecting overflow of uint8_t
#include <string_view>
#include <exception>
#include "PixelBuffer.hpp"
#include "MMU.hpp"

struct CPUState{
  uint8_t v0 = 0;
  uint8_t v1 = 0;
  uint8_t v2 = 0;
  uint8_t v3 = 0;
  uint8_t v4 = 0;
  uint8_t v5 = 0;
  uint8_t v6 = 0;
  uint8_t v7 = 0;
  uint8_t v8 = 0;
  uint8_t v9 = 0;
  uint8_t vA = 0;
  uint8_t vB = 0;
  uint8_t vC = 0;
  uint8_t vD = 0;
  uint8_t vE = 0;
  uint8_t vF = 0;
  uint8_t sp = 0;
  uint16_t pc = 0x200;
  uint16_t index = 0;
  uint8_t delay = 0;
  uint8_t soundTimer = 0;
  std::array<uint16_t, 16> _stack;
};

class CPU{
  public:
    // constructors and Deconstructors // 
    CPU();
    CPU(const CPUState& state);
    CPU(std::shared_ptr<MMU>& pmmu);
    //~CPU();
    /* register based functions */
    const uint8_t getRegister(const uint8_t v) const;
    void WriteRegister(const uint8_t v, const uint8_t byte);
    const uint16_t getPC() const;
    const uint16_t getIndex() const;
    const uint8_t getSP() const;
    const uint8_t getDelay() const;
    const uint8_t getSound() const;
    /* Full Decode and Execute*/
    void Cycle(uint16_t opcode);
    /* Binding components */
    void BindMMU(std::shared_ptr<MMU>& pMMU);
    /* useful for debugging */
    void PrintState(std::ostream& ost) const;
    /* classes */
    class RegisterSelection_Error: public std::exception{
      public:
      RegisterSelection_Error(const std::string& message){
        message_ = "ERROR::REGISTER_SELECTION_ERROR::" + message;

      }
      virtual const char* what() const noexcept override{
        return message_.c_str();
      }
      private:
      std::string message_;
    };
    /* Op codes */
    void op_00E0();
    void op_00EE();
    void op_1nnn(uint16_t opcode);
    void op_2nnn(uint16_t opcode);
    void op_3xkk(uint16_t opcode);
    void op_4xkk(uint16_t opcode);
    void op_5xy0(uint16_t opcode);
    void op_6xkk(uint16_t opcode);
    void op_7xkk(uint16_t opcode);
    void op_8xy0(uint16_t opcode);
    void op_8xy1(uint16_t opcode);
    void op_8xy2(uint16_t opcode);
    void op_8xy3(uint16_t opcode);
    void op_8xy4(uint16_t opcode);
    void op_8xy5(uint16_t opcode);
    void op_8xy6(uint16_t opcode);
    void op_8xy7(uint16_t opcode);
    void op_8xyE(uint16_t opcode);
    void op_9xy0(uint16_t opcode);
    void op_Annn(uint16_t opcode);
    void op_Bnnn(uint16_t opcode);
    void op_Cxkk(uint16_t opcode);
    void op_Dxyn(uint16_t opcode);
    void op_Ex9E(uint16_t opcode);
    void op_ExA1(uint16_t opcode);
    void op_Fx07(uint16_t opcode);
    void op_Fx0A(uint16_t opcode);
    void op_Fx15(uint16_t opcode);
    void op_Fx18(uint16_t opcode);
    void op_Fx1E(uint16_t opcode);
    void op_Fx29(uint16_t opcode);
    void op_Fx33(uint16_t opcode);
    void op_Fx55(uint16_t opcode);
    void op_Fx65(uint16_t opcode);
  private:
    /* CPU registers */
    std::array<uint8_t, 16> _register{
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0
    };
    /* Stack */
    std::array<uint16_t, 16> _stack{ 
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0
    };
    /* special registers */
    uint16_t pc = 0;
    uint8_t sp = 0;
    uint16_t index = 0;
    /* delay and sound registers */
    uint8_t delay = 0;
    uint8_t sound_timer= 0;
    /* interacts with mmu to read / write to memory */
    std::shared_ptr<MMU> mmu;
    /* good for debugging */
    unsigned int instruction_counter = 0;
};

#endif
