#include "DebugCPU.hpp"

namespace Test{
  namespace MMU{
    bool LoadedROM(const std::string& ROM);
    bool LoadedSprites(const std::string& ROM);

  }
  namespace CPU{
    /* Testing correctness of the opcodes */
    /* 0x00E- */
    bool OP_00E0();   /* Clear display */
    bool OP_00EE();   /* Return from subroutine                 | stack based     */
    ///////////////
    bool OP_1NNN();   /* Jump to nnn | PC = 0xnnn               | register based  */
    bool OP_2NNN();   /* Call subroutine at 0xnnn               | stack based     */
    bool OP_3XKK();   /* Skip next if Vx = 0xkk                 | register based  */
    bool OP_4XKK();   /* Skip next if Vx != 0xkk                | register based  */
    bool OP_5XY0();   /* Skip next if Vx = Vy                   | register based  */
    bool OP_6XKK();   /* Set Vx = 0xkk                          | register based  */
    bool OP_7XKK();   /* Set Vx = Vx + 0xkk                     | register based  */
    /* 0x8- */
    bool OP_8XY0();   /* Set Vx = Vy                            | register based  */
    bool OP_8XY1();   /* Set Vx = Vx OR Vy                      | register based  */
    bool OP_8XY2();   /* Set Vx = Vx AND Vy                     | register based  */
    bool OP_8XY3();   /* Set Vx = Vx XOR Vy                     | register based  */
    bool OP_8XY4();   /* Set Vx = Vx + Vy, VF = carry           | register based  */
    bool OP_8XY5();   /* Set Vx = Vx - Vy, VF = NOT borrow      | register based  */
    bool OP_8XY6();   /* Set Vx = Vx SHR 1, VF = overflow       | register based  */
    bool OP_8XY7();   /* Set Vx = Vy - Vx, VF = NOT borrow      | register based  */
    bool OP_8XYE();   /* Set Vx = Vx SHL 1, VF = underflow      | register based  */
    //////////////
    bool OP_9XY0();   /* Skip next if Vx != Vy                  | register based  */
    bool OP_ANNN();   /* Set I = 0xnnn                          | register based  */
    bool OP_BNNN();   /* Jump to 0xnnn + Vx                     | register based  */
    bool OP_CXKK();   /* Set Vx = random byte AND 0xkk          | register based  */

    bool OP_DXYN();   /* Display n-bite sprite starting at      | Memory          *
                       * memory location I at (Vx, Vy), set     | Drawing based   *
                       * Vf = collision                         |                 */
    /* 0xEX- */
    bool OP_EX9E();   /* Skip next if key with value Vx 
                         pressed                                | key input based */
    bool OP_EXA1();   /* Skip next if key with value Vx
                         not pressed                            | key input based */
    ///////////////
    /* 0xFx- */
    bool OP_FX07();   /* Set Vx = delay timer value             | register based  */
    bool OP_FX0A();   /* Wait for key press, store into Vx      | key input based */
    bool OP_FX15();   /* Set delay timer = Vx                   | register based  */
    bool OP_FX18();   /* Set Sound timer = Vx                   | register based  */
    bool OP_FX1E();   /* Set I = I + Vx                         | register based  */
    bool OP_FX29();   /* Set I = Location of sprite for digit Vx| memory based    */
    bool OP_FX33();   /* Store BCD of Vx in memory[I, ...,I+2]  | memory based    */
    bool OP_FX55();   /* Store registers [V0,...,Vx]            | memory based    *
                       * from memory[I,...,I+x]                 |                 */
    bool OP_FX65();   /* Read into registers [V0,...,Vx] from   | memory based    *
                       * memory[I,...,I+x]                      |                 */
  }
}
