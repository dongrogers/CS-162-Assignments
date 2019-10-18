CC = g++
exe_file = ass2

$(exe_file): rest.o menu.o pizza.o driver.o
	$(CC) rest.o menu.o pizza.o driver.o -o $(exe_file)
rest.o: rest.cpp
	$(CC) -c rest.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
out:
	./ass2
clean:
	rm -f *.out *.o $(exe_file)
