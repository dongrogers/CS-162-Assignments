CC = g++
exe_file = mult_div
$(exe_file):
	g++ mult_div.cpp prog.cpp -o $(exe_file)
mult_div.o: mult_div.cpp
	$(CC) -c mult_div.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
out:
	./mult_div 5 5
clean:
	rm -f *.out *.o $(exe_file)
