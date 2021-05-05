set xtic 0.005
set ytic 0.001

set xrange [-1.565:-1.54]
set yrange [53.801:53.812]

plot "src/data/map_nodes.txt" using 1:2:3 with labels hypertext point pointtype 7 pointsize 0.5, \
"src/data/map_nodes.txt" using 1:2 with linespoints linecolor 3 linewidth 1.5 pointtype 7 pointsize 0.5, \
"src/data/shortest.txt" with linespoints linecolor 4 linewidth 1.5 pointtype 8 pointsize 0.5