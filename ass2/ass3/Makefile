CC = g++
exe_file = ass3

$(exe_file): prop.o house.o apt.o comp.o driver.o
	$(CC) prop.o house.o apt.o comp.o driver.o -o $(exe_file)
prop.o: prop.cpp
	$(CC) -c prop.cpp
house.o: house.cpp
	$(CC) -c house.cpp
apt.o: apt.cpp
	$(CC) -c apt.cpp
comp.o: comp.cpp
	$(CC) -c comp.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
out:
	./ass3
clean:
	rm -f *.out *.o $(exe_file)
