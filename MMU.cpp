#include "MMU.hpp"
#include <memory>
#include <vector>

MMU::MMU(){
  LoadSprites();
  pbo = std::make_unique<PixelBuffer>(
      MMU::FRAME_WIDTH, MMU::FRAME_HEIGHT
      );
}

MMU::MMU(const std::string& ROM_name){
  LoadSprites();
  LoadROM(ROM_name);
  //pbo = std::make_unique<PixelBuffer>(MMU::FRAME_WIDTH, MMU::FRAME_HEIGHT);
  pbo = std::make_unique<PixelBuffer>(MMU::FRAME_WIDTH, MMU::FRAME_HEIGHT);
}

uint8_t MMU::GetByte(uint16_t Address){
  return RAM[Address];
}

void MMU::SetByte(uint16_t Address, uint8_t Value){
  RAM[Address] = Value;
}

void MMU::LoadROM(const std::string& ROM_name){
  std::ifstream input(ROM_name, std::ios::binary);
  std::vector<unsigned char> buffer(
      std::istreambuf_iterator<char>(input), {});
  for(unsigned int i = 0; i < buffer.size(); i++){
    RAM[i + ROM_START_ADDRESS] = buffer[i];
  }
  SetRomSize(buffer.size());
}

const void MMU::PrintROM(std::ostream& ost) const{
  for(unsigned int i = ROM_START_ADDRESS; 
      i < ROM_START_ADDRESS + ROM_SIZE; i++){
    ost << std::hex << i << '\t' << (unsigned)RAM[i] << '\n';
  }
}

void MMU::LoadSprites(){
  for(unsigned int i = 0; i < Fontset.size(); i++){
    RAM[i] = Fontset[i];
  }
  SetFontSize();
}

const void MMU::PrintSprites(std::ostream& ost) const{
  for(unsigned int i = 0; i < FONT_SIZE; i++){
    ost << std::hex << (unsigned)RAM[i] << '\n';
  }
}

void MMU::SetRomSize(const unsigned int val){
  ROM_SIZE = val;
}

const unsigned int MMU::GetRomSize(){
  return ROM_SIZE;
}

void MMU::SetFontSize(){
  FONT_SIZE = Fontset.size();
}

const unsigned int MMU::GetFontSize(){
  return FONT_SIZE;
}

/* Pixel buffer members */
Pixel& MMU::GetPixel(const unsigned int x, const unsigned int y){
  return this->pbo->GetPixel(x, y);
}

void MMU::SetPixel(const unsigned int x, const unsigned int y, const Pixel& px){
  this->pbo->SetPixel(x, y, px);
}

void MMU::TurnOn(){
  this->pbo->TurnOn();
}

void MMU::TurnOff(){
  this->pbo->TurnOff();
}

const bool MMU::PixelOn(const unsigned int x, const unsigned int y) const{
  return this->pbo->PixelOn(x, y);
}

const bool MMU::PixelOff(const unsigned int x, const unsigned int y) const{
  return this->pbo->PixelOff(x, y);
}

void MMU::print() const{
 pbo->print(std::cout); 
}

void MMU::printASCII() const{
  this->pbo->printASCII();
  //print();
}

void MMU::printRawData(){
  std::vector<unsigned char> raw_data = RawFrame();
  for(int k = 0; k < raw_data.size(); k+=3){
    std::cout << k/3 << '\t' 
              << (unsigned)raw_data[k] << ' '
              << (unsigned)raw_data[k+1] << ' '
              << (unsigned)raw_data[k+2] << std::endl;
  }
}

const unsigned char* MMU::GetRawFrameData() const{
  return this->pbo->data();
}

std::vector<unsigned char> MMU::RawFrame(){
  return this->pbo->cpPixels();
}

/* Key state functions */

const bool MMU::GetKeyState(const uint8_t key) const{
  if(key > 0x0F){
    std::cout << "ERROR::key_with_value_" << key << "_not_found::returning_0" 
              << std::endl;
    return 0;
  }

  else{
    return keystates[key];
  }
}

void MMU::KeyPress(const uint8_t key){
  if(key > 0x0F){
    std::cout << "ERROR::key_with_value_" << key << "_not_found" 
              << std::endl;
  }

  else{
    keystates[key] = 1;
  }
}

void MMU::KeyUnpress(const uint8_t key){
  if(key > 0x0F){
    std::cout << "ERROR::key_with_value_" << key << "_not_found" 
              << std::endl;
  }
  else{
    keystates[key] = 0;
  }
}

void MMU::PrintKeyState() const{
  std::cout << "------------------------------------------------";
  std::cout << "\n\nKeystates: ";
  for(auto& i: keystates){
    std::cout<< i <<  ' ';
  }
  std::cout<<"\n\n";
  std::cout << "------------------------------------------------" << std::endl;
}
