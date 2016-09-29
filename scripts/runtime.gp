reset

set xlabel 'N'
set ylabel 'Time (sec)'
set key left top
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][0:1] 'clz_iterative.txt' using 1:2 title 'iterative', \
'clz_recursive.txt' using 1:2 title 'recursive', \
'clz_byte_shift.txt' using 1:2  title 'byte\_shift', \
'clz_binary_search.txt' using 1:2  title 'binary\_search', \
'clz_Harley.txt' using 1:2 title 'Harley'
