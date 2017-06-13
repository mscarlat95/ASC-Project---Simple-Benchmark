#!/bin/bash

function get_name() {
	if [ $1 == 1 ]; then
		echo "Bitwise Operations Test";
	elif [ $1 -eq 2 ]; then
		echo "Integer Operations Test";
	elif [ $1 -eq 3 ]; then
		echo "Floating Operations Test";
	elif [ $1 -eq 4 ]; then
		echo "Cache Operations Test";
	fi
}

function display_info() {
	echo -e "*******\t"  $(get_name $1) " using $2 cores\t*******"
}

function display_CPU_time() {
	time ./benchmark $1 $2
}

function display_performance() {
	perf stat -B -e cache-references,cache-misses,branches,branch-misses,context-switches ./benchmark $1 $2
}

function clean() {
	cnt=`ls *.out | wc -l`
	echo "Do you want to remove all output files ? [$cnt files]"
	echo "Answer with y/n, please !"
	read answer

	if [ "$answer" == "y" ]; then
		rm *.out
	fi
}

function collect_info() {
	# display test info (name and available cores)
	{ display_info $1 $2 ; } 2> file$1$2.out

	# display execution time for the current test
	{ display_CPU_time $1 $2 ; } 2>> file$1$2.out
	
	# display cache-misses[%], branch-misses[%], context-switch etc.
	{ display_performance $1 $2 ; } 2>> file$1$2.out
}

function execute() {
	for i in $lst1
	do
		for j in $lst2
		do
			collect_info $i $j 
			cat file$i$j.out
			echo -e "\n"
		done
		echo -e "\n"
	done
}

make build

# check number of arguments
if [ $# -eq 0 ]; then
	lst1="1 2 3 4"
	lst2="1 2 4 8"
	execute ;
elif [ $# -eq 1 ]; then
	lst1="$1"
	lst2="1 2 4 8"
	execute ;
elif [ $# -eq 2 ]; then
	lst1="$1"
	lst2="$2"
	execute ;
fi

# obtain CPU info
lscpu > CPUinfo.out

# create archive
zip -r benchmark_results.zip *.out

# delete output files 
clean
make clean

