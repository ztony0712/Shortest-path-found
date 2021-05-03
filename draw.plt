set xtic 0.005
set ytic 0.001

set xrange [-1.565:-1.54]
set yrange [53.801:53.812]

plot "data/map_nodes.txt" with linespoints linecolor 3 linewidth 2 pointtype 7 pointsize 0.5,\
"data/shortest.txt" with linespoints linecolor 5 linewidth 2 pointtype 5 pointsize 0.5