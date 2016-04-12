TARGET = algos
CC = g++
INC = -I../Sorting -I../Common

$(TARGET) : ../Test/main.cpp
	$(CC) -g -c -Wall -fpermissive $(INC) ../Test/main.cpp
	$(CC) -o $(TARGET) main.o

clean:
	rm -rf *.o $(TARGET)
