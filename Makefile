CC = g++ 
CFLAGS = -I ../../bdd/src/cudd-3.0.0/mtr/ -I ../../bdd/src/cudd-3.0.0/cudd/ -I ../../bdd/src/cudd-3.0.0/epd/  -I ../../bdd/src/cudd-3.0.0/st/ -I ../../bdd/src/cudd-3.0.0/util/ -I ../../bdd/src/cudd-3.0.0/  -I /usr/local/include -std=gnu++11 
LFLAGS = -L /usr/local/lib -l cudd  


test_ruby: test_ruby.cc operations.cc output.cc 
	$(CC) -g $(CFLAGS) test_ruby.cc operations.cc output.cc $(LFLAGS) -o test_ruby 

clean:
	rm test_ruby 
