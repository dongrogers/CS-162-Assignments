CC = gcc
exe_file = ass

ass = test_list.o list.o
	$(CC) -o ass list.o test_list.o

list.o: list.c 
	$(CC) -c list.c 
test_list.o : test_list.c
	$(CC) -c test_list.c 
out:
	a.out
clean:
	rm -f *.out *.o $(exe_file)
