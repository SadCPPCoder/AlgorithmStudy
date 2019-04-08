# Makefile for all the programs

all: BubbleSort SelectSort InsertSort ShellSort MergeSortTop QuickSort

BubbleSort:
	g++ -o BubbleSort BubbleSort.cpp -std=c++11

SelectSort:
	g++ -o SelectSort SelectSort.cpp -std=c++11

InsertSort:
	g++ -o InsertSort InsertSort.cpp -std=c++11

ShellSort:
	g++ -o ShellSort ShellSort.cpp -std=c++11

MergeSortTop:
	g++ -o MergeSortTop MergeSortTop.cpp -std=c++11

QuickSort: TimeCounter
	g++ -o QuickSort QuickSort.cpp TimeCounter.o -std=c++11

test: TimeCounterTest

TimeCounterTest: TimeCounter
	g++ -o TimeCounterTest TimeCounterTest.cpp TimeCounter.o -std=c++11

TimeCounter:
	g++ -c TimeCounter.cpp -std=c++11

clean:
	rm BubbleSort SelectSort InsertSort ShellSort MergeSortTop QuickSort
	rm TimeCounterTest
	rm *.o