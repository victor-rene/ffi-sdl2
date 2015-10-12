bash pp_clang.sh "./SDL/SDL.h" > _tmp1
python functions.py _tmp1 > _tmp2
python compare.py "SDL_Functions.txt" _tmp2 > "SDL_Functions_Diff.txt"
rm _tmp*
