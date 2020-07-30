all:	simulator_Q1	simulator_Q2

simulator_Q2:	main2.o	simulator2.o	priorityQueue2.o	maxHeap2.o	Patient2.o
	g++	main2.o	simulator2.o	priorityQueue2.o	maxHeap2.o	Patient2.o -o simulator_Q2	-std=c++11

main2.o:	main2.cpp
	g++	-c	main2.cpp	-std=c++11

simulator2.o: simulator2.cpp simulator2.h
	g++	-c	simulator2.cpp	-std=c++11

priorityQueue2.o: priorityQueue2.cpp priorityQueue2.h
	g++	-c	priorityQueue2.cpp	-std=c++11

maxHeap2.o:	maxHeap2.cpp maxHeap2.h
	g++	-c	maxHeap2.cpp	-std=c++11

Patient2.o:	Patient2.cpp	Patient2.h
	g++	-c	Patient2.cpp	-std=c++11

simulator_Q1:	main1.o	simulator1.o	priorityQueue1.o	maxHeap1.o	Patient1.o
	g++	main1.o	simulator1.o	priorityQueue1.o	maxHeap1.o	Patient1.o -o simulator_Q1	-std=c++11

main1.o:	main1.cpp
	g++	-c	main1.cpp	-std=c++11

simulator1.o: simulator1.cpp simulator1.h
	g++	-c	simulator1.cpp	-std=c++11

priorityQueue1.o: priorityQueue1.cpp priorityQueue1.h
	g++	-c	priorityQueue1.cpp	-std=c++11

maxHeap1.o:	maxHeap1.cpp maxHeap1.h
	g++	-c	maxHeap1.cpp	-std=c++11

Patient1.o:	Patient1.cpp	Patient1.h
	g++	-c	Patient1.cpp	-std=c++11

