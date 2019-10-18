CC = g++
exe_file = ass3

$(exe_file): shape.o circle.o rect.o driver.o
	$(CC) shape.o circle.o rect.o driver.o -o $(exe_file)
shape.o: shape.cpp
	$(CC) -c shape.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
rect.o: rect.cpp
	$(CC) -c rect.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
out:
	./ass3
clean:
	rm -f *.out *.o $(exe_file)
