Archived on: 30/07/2024. 

See below for the archive note, where I detail where I made errors and how I would improve the project.

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
  
I do not have a rigorous CS background or degree. Thus I had to self teach myself aspects of Computer Graphics and Computer Architecture using websites and textbooks.  
  
Rendering with OpenGL - https://learnopengl.com/.  
  
Computer Architecture - https://www.taylorfrancis.com/books/mono/10.1201/9781315226262/essentials-computer-architecture-douglas-comer.  
  
CHIP8 Opcodes and Specs - http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.0.  
  
Cmake build system - https://cliutils.gitlab.io/modern-cmake/.  
  
TDD - https://alexott.net/en/cpp/CppTestingIntro.html  
  
CPPcon Chandler Micro Profiling Presentation - https://www.youtube.com/watch?v=nXaxk27zwlk

# Archive Note:

### Mistakes

This project was one of the first relatively non trivial projects I've made, and thus contains many beginner C++ mistakes.

* There is an obvious lack of structure in the project. I nowadays prefer a `./src` directory which contains all the source files in the project, and a `./external` directory which contains third party library if I include them in the project.
* There are no testing infrastructure in place, as the emulator was mainly tested against test .ch8 ROMs.
* Returning by const value does not make much sense for some functions, as if a programmer requires a value to be computed and that this value remain immutable, they can just `const T t{GetValue()};`. 
* Fixed size integral types should be qualified with the `std` namespace.
* Simple method functions which performs one or two statements should be written inline in the class definition.
* In C++, avoid using C style casts. If converting between integral types, prefer `static_cast` over C-style casts.
* Function members should be grouped together where they logically make sense.
* Do not pollute the global namespace, and contain all code inside a common namespace for this project.
*  C++ has the class template `std::numeric_limits<T>`  in the `<limits>` header file, which should be preferred for querying maximum value in primitive types rather than using the C style macros in `<limits.h>`. In general, prefer C++ constructs over using the C Preprocessor.
*  Prefer making initialisation syntax more consistent. I used in body initialisation for the `CPU` class, whilst I used member list initialisation syntax for the `PixelBuffer` class.
* There isn't really a use for giving the `Pixel` class a virtual method, and removing virtual qualifier can potentially save memory as it may avoid the generation of a vtable.

### Thoughts for Improvements: 
* Perhaps instead of using shared ownership of `MMU` between the `CPU`, `GraphicsManager` and `System` types, `System` can claim unique ownership of `MMU` and provides a read only pointer to `CPU` and `GraphicsManager`
* Operator overload of `operator[]` can be suitably applied to model system RAM.
* Making a quick CLI would help make the client's experience better.
* I generally prefer marking default generated destructors and constructors explicit now using the `default` keyword since I like verbosity.
* It may make more sense to move the `std::string` in `System`'s only constructor as a way to save the file name, rather than reading from reference as it does now.
