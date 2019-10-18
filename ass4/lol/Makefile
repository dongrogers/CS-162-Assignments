CC = g++
exe_file = ass4

$(exe_file): board.o test.o insect.o area.o bee.o wall.o throw.o body.o lthrow.o sthrow.o harv.o fire.o ninja.o driver.o
	$(CC) board.o test.o insect.o area.o bee.o wall.o throw.o body.o lthrow.o sthrow.o harv.o fire.o ninja.o driver.o -o $(exe_file)
board.o: board.cpp
	$(CC) -c board.cpp
insect.o: insect.cpp
	$(CC) -c insect.cpp
area.o: area.cpp
	$(CC) -c area.cpp
bee.o: bee.cpp
	$(CC) -c bee.cpp
wall.o: wall.cpp
	$(CC) -c wall.cpp
throw.o: throw.cpp
	$(CC) -c throw.cpp
body.o: body.cpp
	$(CC) -c body.cpp
lthrow.o: lthrow.cpp
	$(CC) -c lthrow.cpp
sthrow.o: sthrow.cpp
	$(CC) -c sthrow.cpp
harv.o: harv.cpp
	$(CC) -c harv.cpp
fire.o: fire.cpp
	$(CC) -c fire.cpp
ninja.o: ninja.cpp
	$(CC) -c ninja.cpp
test.o: test.cpp
	$(CC) -c test.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
out:
	./ass4
clean:
	rm -f *.out *.o $(exe_file)
