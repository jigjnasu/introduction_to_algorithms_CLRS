TARGET = algos
CC = g++
INC = -I../Sorting -I../Common -I../Sorting/QuickSort -I../Introduction_To_Algorithms/Sorting_In_Linear_Time

$(TARGET) : ../Test/main.cpp
	$(CC) -g -c -Wall -fpermissive $(INC) ../Test/main.cpp
	$(CC) -o $(TARGET) main.o

clean:
	rm -rf *.o $(TARGET)
