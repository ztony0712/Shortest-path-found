set xtic 0.005
set ytic 0.001
set xlabel "lat"
set ylabel "lon"
set xrange [-1.564000:-1.543100]
set yrange [53.801600:53.811000]

plot "data/map_nodes.txt" with linespoints linecolor 3 linewidth 2 pointtype 7 pointsize 0.5,\
"data/shortest.txt" with linespoints linecolor 5 linewidth 2 pointtype 5 pointsize 0.5