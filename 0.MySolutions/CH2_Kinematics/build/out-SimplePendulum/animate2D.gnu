# Usage: In order to animate data in file.dat do the following:
# gnuplot> file  = "file.dat"
# gnuplot> t0    = 0
# gnuplot> tf    = 10
# gnuplot> dt    = 0.01
# gnuplot> set xrange [-10:10];set yrange [-10:10]
# gnuplot> load "animate2D.gnu"


set macros
set size square
# -----------------------------

t0 = t0 + dt 

command1 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file1."|tail -n 1"
x1 = `@command1`
command1 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file1."|tail -n 1"
y1 = `@command1`
set arrow 1 from 0,0 to x1,y1 lw 1 lc rgb '#90EE90'
set arrow 11 from (x1-0.005),(y1-0.005) to x1,y1 lw 3 lc rgb '#000000'
plot file1 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command2 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file2."|tail -n 1"
x2 = `@command2`
command2 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file2."|tail -n 1"
y2 = `@command2`
set arrow 2 from 0,0 to x2,y2 lw 1 lc rgb '#90EE90'
set arrow 12 from (x2-0.005),(y2-0.005) to x2,y2 lw 3 lc rgb '#000000'
plot file2 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command3 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file3."|tail -n 1"
x3 = `@command3`
command3 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file3."|tail -n 1"
y3 = `@command3`
set arrow 3 from 0,0 to x3,y3 lw 1 lc rgb '#90EE90'
set arrow 13 from (x3-0.005),(y3-0.005) to x3,y3 lw 3 lc rgb '#000000'
plot file3 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command4 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file4."|tail -n 1"
x4 = `@command4`
command4 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file4."|tail -n 1"
y4 = `@command4`
set arrow 4 from 0,0 to x4,y4 lw 1 lc rgb '#90EE90'
set arrow 14 from (x4-0.005),(y4-0.005) to x4,y4 lw 3 lc rgb '#000000'
plot file4 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command5 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file5."|tail -n 1"
x5 = `@command5`
command5 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file5."|tail -n 1"
y5 = `@command5`
set arrow 5 from 0,0 to x5,y5 lw 1 lc rgb '#90EE90'
set arrow 15 from (x5-0.005),(y5-0.005) to x5,y5 lw 3 lc rgb '#000000'
plot file5 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command6 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file6."|tail -n 1"
x6 = `@command6`
command6 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file6."|tail -n 1"
y6 = `@command6`
set arrow 6 from 0,0 to x6,y6 lw 1 lc rgb '#90EE90'
set arrow 16 from (x6-0.005),(y6-0.005) to x6,y6 lw 3 lc rgb '#000000'
plot file6 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command7 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file7."|tail -n 1"
x7 = `@command7`
command7 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file7."|tail -n 1"
y7 = `@command7`
set arrow 7 from 0,0 to x7,y7 lw 1 lc rgb '#90EE90'
set arrow 17 from (x7-0.005),(y7-0.005) to x7,y7 lw 3 lc rgb '#000000'
plot file7 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command8 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file8."|tail -n 1"
x8 = `@command8`
command8 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file8."|tail -n 1"
y8 = `@command8`
set arrow 8 from 0,0 to x8,y8 lw 1 lc rgb '#90EE90'
set arrow 18 from (x8-0.005),(y8-0.005) to x8,y8 lw 3 lc rgb '#000000'
plot file8 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command9 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file9."|tail -n 1"
x9 = `@command9`
command9 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file9."|tail -n 1"
y9 = `@command9`
set arrow 9 from 0,0 to x9,y9 lw 1 lc rgb '#90EE90'
set arrow 19 from (x9-0.005),(y9-0.005) to x9,y9 lw 3 lc rgb '#000000'
plot file9 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle

command10 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $2}' ".file10."|tail -n 1"
x10 = `@command10`
command10 = "awk -v t=".sprintf("%f",t0)." '$1<t{print $3}' ".file10."|tail -n 1"
y10 = `@command10`
set arrow 20 from 0,0 to x10,y10 lw 1 lc rgb '#90EE90'
set arrow 21 from (x10-0.005),(y10-0.005) to x10,y10 lw 3 lc rgb '#000000'
plot file10 \
 using 2:($1<= t0 ? $3: 1/0) with lines lw 0 lc rgb '#ffff00' notitle












if(t0<tf) reread





#  ---------------------------------------------------------------------
#  Copyright by Konstantinos N. Anagnostopoulos (2004-2014)
#  Physics Dept., National Technical University,
#  konstant@mail.ntua.gr, www.physics.ntua.gr/~konstant
#  
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, version 3 of the License.
#  
#  This program is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#  
#  You should have received a copy of the GNU General Public Liense along
#  with this program.  If not, see <http://www.gnu.org/licenses/>.
#  -----------------------------------------------------------------------
