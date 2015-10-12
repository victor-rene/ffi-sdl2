bash pp_clang.sh $1 > _tmp1
python functions.py _tmp1 > _tmp2
python compare.py $2 _tmp2
rm _tmp*
