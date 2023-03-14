#include "CPU.hpp"
#include "utilities.hpp"
#include <memory>
// constructors // 
CPU::CPU(){
  pc = 0x200;
}

CPU::CPU(const CPUState& state){
  /* construct a CPU at the current register state */
  _register[0x0] = state.v0;
  _register[0x1] = state.v1;
  _register[0x2] = state.v2;
  _register[0x3] = state.v3;
  _register[0x4] = state.v4;
  _register[0x5] = state.v5;
  _register[0x6] = state.v6;
  _register[0x7] = state.v7;
  _register[0x8] = state.v8;
  _register[0x9] = state.v9;
  _register[0xA] = state.vA;
  _register[0xB] = state.vB;
  _register[0xC] = state.vC;
  _register[0xD] = state.vD;
  _register[0xE] = state.vE;
  _register[0xF] = state.vF;
  pc = state.pc;
  sp = state.sp;
  index = state.index;
  delay = state.delay;
  sound_timer = state.soundTimer;
  _stack = state._stack;
}

CPU::CPU(std::shared_ptr<MMU>& pmmu){
  BindMMU(pmmu);
  pc = 0x200;
}

/****************************************************************************/

void CPU::BindMMU(std::shared_ptr<MMU>& pMMU){
  mmu = pMMU;
}

/* get registers */
const uint8_t CPU::getRegister(const uint8_t v)const {
  try{
    if(v > 0x0F){
      throw RegisterSelection_Error{"input_v_is_greater_than_0x0F"};
    }
    else{
      return _register[v];
    }
  }
  catch(RegisterSelection_Error& e){
    std::cout << e.what() << "::returning_0" << std::endl;
    return 0;
  }
}

void CPU::WriteRegister(const uint8_t v, const uint8_t byte){
  try{
    if(v > 0x0F){
      throw RegisterSelection_Error{"input_v_is_greater_than_0x0F"};
    }
    else{
      _register[v] = byte;
    }
  }
  catch(RegisterSelection_Error& e){
    std::cout << e.what() << "::returning_0" << std::endl;
  }
}

const uint16_t CPU::getPC() const{
  return pc;
}

const uint16_t CPU::getIndex() const{
  return index;
}

const uint8_t CPU::getSP() const{
  return sp;
}

const uint8_t CPU::getDelay() const{
  return delay;
}

const uint8_t CPU::getSound() const{
  return sound_timer;
}

/* execute cycle */
void CPU::Cycle(uint16_t opcode){
  //std::cout << "first nibble = " << (opcode & 0xF000) << '\n';
  instruction_counter += 1;
  switch(opcode & 0xF000){
    case 0x0000:
      switch(opcode & 0x00FF){
        case 0x00E0:
          // clear the screen
          op_00E0();
          break;
        case 0x00EE:
          op_00EE();
          break;
      }
      break;
    case 0x1000:
      op_1nnn(opcode);
      break;
    case 0x2000:
      op_2nnn(opcode);
      break;
    case 0x3000:
      op_3xkk(opcode);
      break;
    case 0x4000:
      op_4xkk(opcode);
      break;
    case 0x5000:
      op_5xy0(opcode);
      break;
    case 0x6000:
      op_6xkk(opcode);
      break;
    case 0x7000:
      op_7xkk(opcode);
      break;
    case 0x8000:
      switch(opcode & 0x000F){
        case 0x0:
          op_8xy0(opcode);
          break;
        case 0x1:
          op_8xy1(opcode);
          break;
        case 0x2:
          op_8xy2(opcode);
          break;
        case 0x3:
          op_8xy3(opcode);
          break;
        case 0x4:
          op_8xy4(opcode);
          break;
        case 0x5:
          op_8xy5(opcode);
          break;
        case 0x6:
          op_8xy6(opcode);
          break;
        case 0x7:
          op_8xy7(opcode);
          break;
        case 0xE:
          op_8xyE(opcode);
          break;
      }
      break;
    case 0x9000:
      op_9xy0(opcode);
      break;
    case 0xA000:
      op_Annn(opcode);
      break;
    case 0xB000:
      op_Bnnn(opcode);
      break;
    case 0xC000:
      op_Cxkk(opcode);
      break;
    case 0xD000:
      op_Dxyn(opcode);
      break;
    case 0xE000:
      switch(opcode & 0x00FF){
        case 0x9E:
          op_Ex9E(opcode);
          break;
        case 0xA1:
          op_ExA1(opcode);
          break;
      }
      break;
    case 0xF000:
      switch(opcode & 0x00FF){
        case 0x07:
          op_Fx07(opcode);
          break;
        case 0x0A:
          op_Fx0A(opcode);
          break;
        case 0x15:
          op_Fx15(opcode);
          break;
        case 0x18:
          op_Fx18(opcode);
          break;
        case 0x1E:
          op_Fx1E(opcode);
          break;
        case 0x29:
          op_Fx29(opcode);
          break;
        case 0x33:
          op_Fx33(opcode);
          break;
        case 0x55:
          op_Fx55(opcode);
          break;
        case 0x65:
          op_Fx65(opcode);
          break;
      }
      break;
    default:
      throw std::runtime_error{"ERROR::UNKOWN_OPCODE"};
  }
}

/* Op codes */
void CPU::op_00E0(){
  std::cout << "00E0" << '\t' << "Clear the screen\n";
  mmu->TurnOff();
  pc+=2;
}

void CPU::op_00EE(){
  std::cout << "00EE" << '\t' << "Return from subroutine\n";
  sp -= 1;
  pc = _stack[sp];
}

void CPU::op_1nnn(uint16_t opcode){
  std::cout << "1nnn" << '\t' << "Jump to location\n";
  uint16_t nnn = opcode & 0x0FFF;
  pc = nnn;
}

void CPU::op_2nnn(uint16_t opcode){
  std::cout << "2nnn" << '\t' << "Call subroutine at 2nnn\n";
  uint16_t nnn = opcode & 0x0FFF;
  _stack[sp] = pc+2;
  sp += 1;
  pc = nnn;
}

void CPU::op_3xkk(uint16_t opcode){
  std::cout << opcode << '\t' << "3xkk" << '\t' 
            << "Skip next instruction if Vx = kk\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t kk = opcode & 0x00FF;
  if(getRegister(x) == kk){
    pc += 4;
  }
  else{
    pc += 2;
  }
}

void CPU::op_4xkk(uint16_t opcode){
  std::cout << opcode << '\t' << "4xkk" << '\t' 
            << "Skip next instruction if Vx != kk\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t kk = opcode & 0x00FF;
  if(getRegister(x) != kk){
    pc += 4;
  }
  else{
    pc += 2;
  }
}

void CPU::op_5xy0(uint16_t opcode){
  std::cout << opcode << '\t' << "5xy0" << '\t' 
            << "Skip next instruction if Vx = Vy\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  if(getRegister(x) == getRegister(y)){
    pc += 4;

  }
  else{
    pc += 2;
  }
}

void CPU::op_6xkk(uint16_t opcode){
  std::cout << opcode << '\t' << "6xkk" << '\t' 
            << "Sets Vx = kk\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint16_t kk = (opcode & 0x00FF);
  WriteRegister(x, kk);
  pc += 2;
}

void CPU::op_7xkk(uint16_t opcode){
  std::cout << opcode << '\t' << "7xkk" << '\t' 
            << "Sets Vx = Vx + kk\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t kk = (opcode & 0x00FF);
  WriteRegister(x, getRegister(x) + kk);
  pc += 2;
}

void CPU::op_8xy0(uint16_t opcode){
  std::cout << "8xy0" << '\t' 
            << "Sets Vx = Vy\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  WriteRegister(x, getRegister(y));
  pc += 2;
}

void CPU::op_8xy1(uint16_t opcode){
  std::cout << "8xy1" << '\t' 
            << "Sets Vx = Vx OR Vy \n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  WriteRegister(x, getRegister(x) | getRegister(y));
  pc += 2;
}

void CPU::op_8xy2(uint16_t opcode){
  std::cout << "8xy2" << '\t' 
            << "Sets Vx = Vx AND Vy\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  WriteRegister(x, getRegister(x) & getRegister(y));
  pc += 2;
}

void CPU::op_8xy3(uint16_t opcode){
  std::cout << "8xy3" << '\t' 
            << "Sets Vx = Vx XOR Vy\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  WriteRegister(x, getRegister(x) ^ getRegister(y));
  pc += 2;
}

void CPU::op_8xy4(uint16_t opcode){
  std::cout << "8xy4" << '\t' 
            << "Sets Vx = Vx + Vy (Carry flag may be set)\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  if(getRegister(x) > 0 && getRegister(y) > UCHAR_MAX - getRegister(x)){
    WriteRegister(x, getRegister(x) + getRegister(y));
    WriteRegister(0x0F, 0x01);
  }
  else{
    WriteRegister(x, getRegister(x) + getRegister(y));
    WriteRegister(0x0F, 0x00);
  }
  pc += 2;
}

void CPU::op_8xy5(uint16_t opcode){
  std::cout << "8xy5" << '\t' 
            << "Sets Vx = Vx - Vy, VF = Not borrow\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  if(getRegister(x) > getRegister(y)){
    WriteRegister(0x0F, 0x01);
  }
  else{
    WriteRegister(0x0F, 0x00);
  }
  WriteRegister(x, getRegister(x) - getRegister(y));
  pc += 2;
}

void CPU::op_8xy6(uint16_t opcode){
  // shift right-1
  std::cout << "8xy6" << '\t' 
            << "Set Vx = Vx SHR 1\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  if((getRegister(x) & 0x01) == 1){
    // underflow condition
    WriteRegister(0x0F, 0x01);
  }
  else{
    WriteRegister(0x0F, 0x00);
  }
  WriteRegister(x, getRegister(x) >> 1);
  pc += 2;
}

void CPU::op_8xy7(uint16_t opcode){
  std::cout << "8xy7" << '\t' 
            << "Set Vx = Vy - Vx, VF = Not borrow 1\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  if(getRegister(x) > getRegister(y)){
    WriteRegister(0x0F, 0x01);
  }
  else{
    WriteRegister(0x0F, 0x01);
  }
  WriteRegister(x, getRegister(x) - getRegister(y));
  pc += 2;
}

void CPU::op_8xyE(uint16_t opcode){
  std::cout << "8xyE" << '\t' 
            << "Set Vx = Vx SHL 1\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  if((getRegister(x) & 0x10) == 1){
    WriteRegister(0x0F, 0x01);
  }
  else{
    WriteRegister(0x0F, 0x00);
  }
  WriteRegister(x, getRegister(x) << 1);
  pc += 2;
}

void CPU::op_9xy0(uint16_t opcode){
  std::cout << "9xy0" << '\t' 
            << "Skip next instruction if Vx != Vy\n";

  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;
  if(getRegister(x) != getRegister(y)){
    pc += 4;
  }
  else{
    pc += 2;
  }
}

void CPU::op_Annn(uint16_t opcode){
  std::cout << "Annn" << '\t' 
            << "Set I = nnn\n";
  uint16_t nnn = opcode & 0x0FFF;
  index = nnn;
  pc += 2;
}

void CPU::op_Bnnn(uint16_t opcode){
  std::cout << "Bnnn" << '\t' 
            << "Jump to location nnn + V0\n";
  uint16_t nnn = opcode & 0x0FFF;
  pc = nnn + getRegister(0x00);
}

void CPU::op_Cxkk(uint16_t opcode){
  std::cout << "Cxkk" << '\t' 
            << "Set Vx = Random Byte and kk\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t byte = random_byte();
  WriteRegister(x , getRegister(x) & byte);
  pc += 2;
}

/* Drawing Events */
void CPU::op_Dxyn(uint16_t opcode){
  std::cout << "Dxyn" << '\t' 
            << "Display n byte sprite starting at memory location I at (Vx, Vy), set VF = collision\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t y = (opcode & 0x00F0) >> 4;;
  uint8_t n =  opcode & 0x000F;
  /*******************************************************/
  std::cout << std::hex << "I = " << index << " x = " << (unsigned)x << " y = " << std::hex << (unsigned)y 
            << " n = " << (unsigned)n << std::endl;
  std::cout << std::dec << "I = " << index << " x = " << (unsigned)x << " y = " << std::hex << (unsigned)y 
            << " n = " << (unsigned)n << std::endl;
  mmu->printASCII();
  /*******************************************************/
  for(unsigned int row = 0; row < n; row++){
    uint8_t sprite_byte = mmu->GetByte(index + row);
    std::cout << (unsigned)sprite_byte << std::endl;
    for(unsigned int col = 0; col < 8; col++){
      uint8_t bit = sprite_byte & (0x80 >> col);
      Pixel& currentPixel = mmu->GetPixel(
          getRegister(x) + col, getRegister(y) + row);
      if(bit){ /* so will be drawn or xored */
        if(currentPixel.on()){
          WriteRegister(0x0F, 0x01);
        }
        currentPixel ^= Pixel{255, 255, 255};
      }
    }
  }
  pc += 2;
}

/* Key Press Events */
void CPU::op_Ex9E(uint16_t opcode){
  uint8_t x = (opcode & 0x0F00) >> 8;
  std::cout << "Ex9E" << '\t' 
            << "Skip next instruction if key with the value of Vx is pressed\n";
  if (mmu->GetKeyState(getRegister(x)) == 1){
    pc += 4;
  }
  else{
    pc += 2;
  }
}

void CPU::op_ExA1(uint16_t opcode){
  uint8_t x = (opcode & 0x0F00) >> 8;
  std::cout << "ExA1" << '\t' 
            << "Skip next instruction if key with the value of Vx is not pressed.\n";
  if (mmu->GetKeyState(getRegister(x)) == 0){
    pc += 4;
  }
  else{
    pc += 2;
  }
}

/*****************************************************/

void CPU::op_Fx07(uint16_t opcode){
  std::cout << "Fx07" << '\t' 
            << "Vx = delay timer value\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  WriteRegister(x, delay);
  pc += 2;
}

/* THIS ONE REQUIRES UNDERSTANDING OF HOW GLFW HANDLES KEY 
 * PRESSES */
void CPU::op_Fx0A(uint16_t opcode){
  std::cout << "Fx0A" << '\t' 
            << "Wait for a key press, store the value of the key in Vx.\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  for(;;){
    if(mmu->GetKeyState(0x00) == 1){
      mmu->KeyPress(0x00);
      WriteRegister(x, 0x00);
      break;
    }
    if(mmu->GetKeyState(0x01) == 1){
      mmu->KeyPress(0x01);
      WriteRegister(x, 0x01);
      break;
    }
    if(mmu->GetKeyState(0x02) == 1){
      mmu->KeyPress(0x02);
      WriteRegister(x, 0x02);
      break;
    }
    if(mmu->GetKeyState(0x03) == 1){
      mmu->KeyPress(0x03);
      WriteRegister(x, 0x03);
      break;
    }
    if(mmu->GetKeyState(0x04) == 1){
      mmu->KeyPress(0x04);
      WriteRegister(x, 0x04);
      break;
    }
    if(mmu->GetKeyState(0x05) == 1){
      mmu->KeyPress(0x05);
      WriteRegister(x, 0x05);
      break;
    }
    if(mmu->GetKeyState(0x06) == 1){
      mmu->KeyPress(0x06);
      WriteRegister(x, 0x06);
      break;
    }
    if(mmu->GetKeyState(0x07) == 1){
      mmu->KeyPress(0x07);
      WriteRegister(x, 0x07);
      break;
    }
    if(mmu->GetKeyState(0x08) == 1){
      mmu->KeyPress(0x08);
      WriteRegister(x, 0x08);
      break;
    }
    if(mmu->GetKeyState(0x09) == 1){
      mmu->KeyPress(0x09);
      WriteRegister(x, 0x09);
      break;
    }
    if(mmu->GetKeyState(0x0A) == 1){
      mmu->KeyPress(0x0A);
      WriteRegister(x, 0x0A);
      break;
    }
    if(mmu->GetKeyState(0x0B) == 1){
      mmu->KeyPress(0x0B);
      WriteRegister(x, 0x0B);
      break;
    }
    if(mmu->GetKeyState(0x0C) == 1){
      mmu->KeyPress(0x0C);
      WriteRegister(x, 0x0C);
      break;
    }
    if(mmu->GetKeyState(0x0D) == 1){
      mmu->KeyPress(0x0D);
      WriteRegister(x, 0x0D);
      break;
    }
    if(mmu->GetKeyState(0x0E) == 1){
      mmu->KeyPress(0x0E);
      WriteRegister(x, 0x0E);
      break;
    }
    if(mmu->GetKeyState(0x0F) == 1){
      mmu->KeyPress(0x0F);
      WriteRegister(x, 0x0F);
      break;
    }
  }
  pc += 2;
}

void CPU::op_Fx15(uint16_t opcode){
  std::cout << "Fx15" << '\t' 
            << "delay timer = Vx\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  delay = getRegister(x);
  pc += 2;
}

void CPU::op_Fx18(uint16_t opcode){
  std::cout << "Fx18" << '\t' 
            << "sound timer = Vx\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  sound_timer = getRegister(x);
  pc += 2;
}

void CPU::op_Fx1E(uint16_t opcode){
  std::cout << "Fx18" << '\t' 
            << "Set I = I + Vx\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  index += getRegister(x);
  pc += 2;
}

void CPU::op_Fx29(uint16_t opcode){
  std::cout << "Fx29" << '\t' 
            << "Set I = location of sprite for digit in Vx\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  const unsigned int BYTES_PER_SPITES = 5;
  index = BYTES_PER_SPITES * getRegister(x);
  pc += 2;
}

void CPU::op_Fx33(uint16_t opcode){
  std::cout << "Fx33" << '\t' 
            << "Store BCD Representation of Vx in memory location I, I+1, I+2\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  uint8_t hundreds =  (getRegister(x) % 1000) / 100;
  uint8_t tens =      (getRegister(x) % 100) / 10;
  uint8_t units =     (getRegister(x) % 10);
  mmu->SetByte(index,   hundreds);
  mmu->SetByte(index+1, tens);
  mmu->SetByte(index+2, units);
  pc += 2;
}

void CPU::op_Fx55(uint16_t opcode){
  std::cout << "Fx55" << '\t' 
            << "Store registers V0 through Vx in memory starting at location I\n";
  uint8_t x = (opcode & 0x0F00) >> 8;
  for(uint8_t i = 0; i <= x; i++){
    mmu->SetByte(index + i, getRegister(i));
  }
  index += x + 1;
  pc += 2;
}

void CPU::op_Fx65(uint16_t opcode){
  std::cout << "Fx65" << '\t' 
            << "Read registers V0 through Vx from memory starting at location I.";
  const uint8_t x = (opcode & 0x0F00) >> 8;
  for(uint8_t i = 0; i <= x; i++){
    WriteRegister(i, index + i);
  }
  index += x + 1;
  pc += 2;
}

/* DEBUGGING */

void CPU::PrintState(std::ostream& ost) const{
  ost << "------------------------------------------------------------------";
  ost << "\nInstruction count: " << std::dec << instruction_counter;

  ost << "\n\n";
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

  ost << "\n\n";
  ost << "stack: ";
  for(auto& i : _stack){
    ost << i << " ";
  }
  ost << '\n';
  ost << "\n------------------------------------------------------------------" <<std::endl;
}
