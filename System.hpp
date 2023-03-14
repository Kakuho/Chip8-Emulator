// general run time system. Houses the Chip8 emulator logic and the render logic separately.
#include <algorithm>
#include <memory>

#include "CPU.hpp"
#include "MMU.hpp"
#include "GraphicsManager.hpp"

class System{
  public:
  // constructor
  System(const std::string& ROM_name);

  void Run();
  private:
  std::unique_ptr<CPU> cpu_;
  std::shared_ptr<MMU> mmu_;
  std::unique_ptr<GraphicsManager> graphicsManager_;
};
