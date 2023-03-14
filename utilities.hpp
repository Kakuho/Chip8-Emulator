//#include "Chip8.hpp"
#include <cstdint>
#include <random>

uint8_t random_byte(){
  std::random_device seed;
  std::mt19937 mt(seed());
  uint8_t rbyte = mt() % 255;
  return rbyte; 
}

uint32_t doubleDabble(uint8_t val){
  // double dabble algorithm performed on 8bits, returns the scratch space stored in the 32bit val
  uint32_t scratch = 0 | val;
  for(int i = 0; i < 8; i++){
    if(((scratch & 0xF00) >> 8u) > 5)
      scratch += 0x300;
    if(((scratch & 0xF000) >> 12u) > 5)
      scratch += 0x3000;
    if(((scratch & 0xF0000) >> 16u)> 5)
      scratch += 0x30000;
    scratch <<= 1;
  }
  return scratch;
}
