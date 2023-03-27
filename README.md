# Chip8-Emulator

An experimental emulator used to learn more about low level details of computer hardware and graphics rendering using the mature API OpenGL. Also learnt to use the Cmake build system for creating C++ binaries.

# Key Mapping

Original keys for the CHIP8 system:

|1st column| 2nd column | 3rd column | 4th column |
|---|---|---|---|
| 1 | 2 | 3 | c |
| 4 | 5 | 6 | D |
| 7 | 8 | 9 | E |
| A | 0 | B | F |

Reconfigured keymapping for my system (Laptop with no numpad):

|1st column| 2nd column | 3rd column | 4th column |
|---|---|---|---|
| 1 | 2 | 3 | 4 |
| q | w | e | r |
| a | s | d | f |
| z | x | c | v |

# Building Binaries

To build the binaries use the following commands at the src directory:

```
$ mkdir build && cd build
$ cmake .. .
$ make
```

To start the system:

```
$ ./CHIP8
```

So far the emulator only supports the Pong.ch8 ROM. It runs at 300fps on my Thinkpad T530 machine.

# Resources I used

I do not have a rigorous CS background or degree. Thus I had to self teach myself aspects of Computer Graphics and Computer Architecture using websites 
and textbooks.

Rendering with OpenGL - https://learnopengl.com/.

Computer Architecture - https://www.taylorfrancis.com/books/mono/10.1201/9781315226262/essentials-computer-architecture-douglas-comer.

CHIP8 Opcodes and Specs - http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.0.

Cmake build system - https://cliutils.gitlab.io/modern-cmake/.

TDD - https://alexott.net/en/cpp/CppTestingIntro.html

CPPcon Chandler Micro Profiling Presentation - https://www.youtube.com/watch?v=nXaxk27zwlk


