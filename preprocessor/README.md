Setup
-----
Install Mingw32-w64, then update pacman and download each package (pacman -S).

* Mingw32-w64
* clang/gcc
* SDL2 headers
* python 2.7.10

General
-------
Each script expect as input a path to "SDL.h".

    path="/c/msys32/mingw32/include/SDL2/SDL.h"

Run preprocessor
----------------

    pp_clang.sh $path  or  pp_gcc.sh $path
    
Extract functions
-----------------

    pp_clang.sh $path | python functions.py > ffi_functions.h
    
Extract all symbols
-------------------

    pp_clang.sh $path | python extract.py > ffi_sdl.h
    or
    extract.sh $path > ffi_sdl.h
    
Compare dynamic symbols
-----------------------
Create "SDL_Functions.txt" by using a tool like depends22x86 on "SDL2.dll".
You can probably use nm or objdump on Linux.

    compare.sh $path "SDL_Functions.txt" > "SDL_Functions_Diff.txt"
