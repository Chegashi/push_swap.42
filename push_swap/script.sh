#!/bin/bash
echo "_________________________________________"
arg="42"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"
echo "_________________________________________"

arg="0 1 2 3"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"
echo "_________________________________________"

arg="0 1 2 3 4 5 6 7 8 9"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"
echo "_________________________________________"

arg="2 1 0"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[3] calculate : `wc -l cmd`"
echo "_________________________________________"

arg="1 5 2 4 3"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[12] calculate : `wc -l cmd`"
echo "_________________________________________"

arg=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')" 2> /dev/null)
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[12] calculate :  `wc -l cmd`"
echo "_________________________________________"

arg=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')" 2> /dev/null)
	echo "100 random values"
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected [700=>5, 900=>4, 1100=>3, 1300=>2, 1500=>1] calculate : `wc -l cmd`"
echo "_________________________________________"

arg=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')" 2> /dev/null)
	echo "500 random values"
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[5500=>5, 7000=>4, 8500=>3, 10000=>2, 15000=>1] calculate : `wc -l cmd`"
echo "_________________________________________"
