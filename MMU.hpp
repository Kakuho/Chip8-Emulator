#ifndef MMU_HPP
#define MMU_HPP

#include <vector>
#include <string>
#include <memory>
#include <array>
#include <cstdint>
#include "PixelBuffer.hpp"

class MMU{
  public:
    MMU();
    MMU(const std::string& ROM_name);
    //~MMU();
    /* Static Variables */
    static constexpr unsigned int FRAME_WIDTH = 64;
    static constexpr unsigned int FRAME_HEIGHT = 32;
    // memory setter and getters // 
    uint8_t GetByte(uint16_t Address);
    void SetByte(uint16_t Address, uint8_t Value);
    // Loading and printing memory //
    void LoadROM(const std::string& ROM_name);
    const void PrintROM(std::ostream& ost) const;
    void LoadSprites() ;
    const void PrintSprites(std::ostream& ost) const;
    // useful for debugging
    void SetRomSize(const unsigned int val);
    const unsigned int GetRomSize();
    void SetFontSize();
    const unsigned int GetFontSize();
    /* pixelBuffer */
    Pixel& GetPixel(const unsigned int x, const unsigned int y) ;
    void SetPixel(const unsigned int x, const unsigned int y, const Pixel& px);
    void TurnOff();
    void TurnOn();
    const bool PixelOn(const unsigned int x, const unsigned int y) const;
    const bool PixelOff(const unsigned int x, const unsigned int y) const;
    void print() const;
    void printASCII() const;
    void printRawData();
    const unsigned char* GetRawFrameData() const;
    std::vector<unsigned char> RawFrame();
    /* Key state inputs */
    const bool GetKeyState(const uint8_t key) const;
    void KeyPress(const uint8_t key);
    void KeyUnpress(const uint8_t key);
    void PrintKeyState() const;

  private:
    std::array<uint8_t, 4096> RAM;
    std::array<bool, 16> keystates; 
    static constexpr int SPRITE_START_ADDRESS = 0x000;
    static constexpr int ROM_START_ADDRESS = 0x200;
    unsigned int ROM_SIZE;
    unsigned int FONT_SIZE;
    // sprite data
    std::array<uint8_t, 5*16> Fontset{
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };
    // screen buffer data
    std::unique_ptr<PixelBuffer> pbo;
};

#endif
