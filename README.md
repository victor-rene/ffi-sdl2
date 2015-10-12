ffi-SDL2
========
I created this project to work more easily with the SDL2 library without being
reliant on other people's implementation of the interface. There are other
projects that might interest you like:

* Python: PySDL2 (https://pysdl2.readthedocs.org/en/latest/)
* Lua
  * https://github.com/Tangent128/luasdl2
  * https://github.com/torch/sdl2-ffi
* Nim: https://github.com/nim-lang/sdl2
* C#: https://github.com/flibitijibibo/SDL2-CS

Problems with those solutions are package managers, naming conventions,
managed code, etc... I think that each project / game is different and that you
should build your own basic tools for each task, not only to reduce overhead
but to keep things simple as well.

Now, if you like to do things your own way (like me) and use the bare bones API,
then read on. The key to interface SDL2 with a scripting language is to automate
the generation of the "glue" code you need.

From my research, I would say luajit-ffi is the best option:

* simplicity
* flexibility
* performance
