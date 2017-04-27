all: task1 task2

task1: hardware.o hardwareManagement.o
	g++ hardware.o hardwareManagement.o -o task1

task2: task2main.o sorting.o text2bin.o
	g++ task2main.o sorting.o text2bin.o -o task2

hardware.o: hardware.cpp
	g++ -c hardware.cpp

hardwareManagement.o: hardwareManagement.cpp
	g++ -c hardwareManagement.cpp

task2main.o: task2main.cpp
	g++ -c task2main.cpp

sorting.o: sorting.cpp
	g++ -c sorting.cpp

text2bin.o: text2bin.cpp
	g++ -c text2bin.cpp

clean:
	rm *.o