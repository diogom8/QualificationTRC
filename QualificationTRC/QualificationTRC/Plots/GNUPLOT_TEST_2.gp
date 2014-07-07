#	GNUPLOT SCRIPT - TRC SIMULATORS
# 	Created by Diogo Monteiro and Suhas- 07/07/2014
#
#	Plots for TEST 2: Normal Climb Engine Operating(1.c1)
#
#

#Altitude/Rate of Climb comparison
#Absolute
set term wxt 0
reset
plot 'C:\Users\Diogo\Desktop\outro.projBETA\DATA_TEST_2.txt' using 1:3 with lines lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 	 
set xrange [0:30]
set xlabel "Time [s]"
set yrange [3000:3800]
set ylabel "Pressure Altitude [feet]"
set key right bottom Left
set timestamp
set title 'Test 2: Engine Acceleration'
replot
	 
set term wxt 1
reset
plot 'C:\Users\Diogo\Desktop\outro.projBETA\DATA_TEST_2.txt' using 1:5 with lines lt -1 lw 1 lc rgb "blue" title 'Simulation Data', \
	 #'DATA_TESTE_1_REF.txt' using ($1-8):2 with lines lt 0 lw 3 lc rgb "black" title 'Reference Data'
	 
set xrange [0:30]
set xlabel "Time [s]"
set yrange [0:70]
set ylabel "Fuel Flow [gallons per hour]"
set key right bottom Left
set timestamp
set title 'Test 2: Engine Acceleration'
replot