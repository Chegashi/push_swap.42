#!/bin/bash

arg="42"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[0]`wc -l cmd`"

arg="0 1 2 3"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[0]`wc -l cmd`"

arg="0 1 2 3 4 5 6 7 8 9"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[0]`wc -l cmd`"

arg="2 1 0"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[3]`wc -l cmd`"

arg="1 5 2 4 3"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[12]`wc -l cmd`"

arg=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')")
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[12]`wc -l cmd`"

arg=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
	echo "<100 random values>"
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[100=>5, 900=>4, 1100=>3, 1300=>2, 1500=>1]`wc -l cmd`"

arg=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
	echo "<500 random values>"
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "[5500=>5, 7000=>4, 8500=>3, 10000=>2, 15000=>1]`wc -l cmd`"