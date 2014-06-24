#	GNUPLOT SCRIPT - TRC SIMULATORS
# 	Created by Diogo Monteiro - 24/06/2014
#
#	Plots for TEST 1: Normal Climb Engine Operating(1.c1)
#
#

#Altitude/Rate of Climb comparison
#Absolute
set term wxt 0
reset
plot 'DATA_TESTE_1.txt' using 1:3 with lines lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 'DATA_TESTE_1_REF.txt' using 1:2 with lines lt 0 lw 3 lc rgb "black" title 'Reference Data'
	 
set xrange [0:180]
set xlabel "Time [s]"
set yrange [2000:4000]
set ylabel "Pressure Altitude [feet]"
set key right bottom Left
set timestamp
set title 'Test 1: Normal Climb Engine Operating(1.c1) [ABSOLUTE]'
replot
	 
#Mean
set term wxt 1
reset
f(x) = a*x+b
fit f(x) 'DATA_TESTE_1.txt' using 1:3 via a, b
plot f(x) lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 'DATA_TESTE_1_REF.txt' using ($1-8):(2000+($1-8)*(718-100)/60) with lines lt 0 lw 3 lc rgb "black" title 'Reference Data (±100 feet/min)', \
	 'DATA_TESTE_1_REF.txt' using ($1-8):(2000+($1-8)*(718+100)/60) with lines lt 0 lw 3 lc rgb "black" title ''
	 
set xrange [0:180]
set xlabel "Time [s]"
set yrange [2000:4000]
set ylabel "Pressure Altitude [feet]"
set key right bottom Left
set timestamp
set title 'Test 1: Normal Climb Engine Operating(1.c1) [MEAN]'
replot

#set term png
#set output "out1.png"
#replot
#set output

#Indicated Airspeed Comparison
#Absolute
set term wxt 2
reset
plot 'DATA_TESTE_1.txt' using 1:2 with lines lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 'DATA_TESTE_1_REF.txt' using 1:3 with lines lt 0 lw 3 lc rgb "black" title 'Reference Data'	 
set xrange [0:180]
set xlabel "Time [s]"
set yrange [0:150]
set ylabel "Indicated Airspeed [kts]"
set key right bottom Left
set timestamp
set title 'Test 1: Normal Climb Engine Operating(1.c1) [ABSOLUTE]'
replot	 
	 
#Mean
set term wxt 3
reset
f(x) = a
fit f(x) 'DATA_TESTE_1.txt' using 1:2 via a
plot f(x) lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 (80.1+3) lt 0 lw 3 lc rgb "black" title 'Reference Data (±3 kts)', \
	 (80.1-3) lt 0 lw 3 lc rgb "black" title ''
set xrange [0:180]
set xlabel "Time [s]"
set yrange [0:150]
set ylabel "Indicated Airspeed [kts]"
set key right bottom Left
set timestamp
set title 'Test 1: Normal Climb Engine Operating(1.c1) [MEAN]'
replot	

#set term png
#set output "out2.png"
#replot
#set output