
all: postfix_eval test_deque

postfix_eval: postfix_eval.o
	g++ -o postfix_eval postfix_eval.o

postfix_eval.o: postfix_eval.cc stack.h
	g++ -c postfix_eval.cc

test_deque: test_deque.o deque.h
	g++ -o test_deque test_deque.o -lgtest -lgtest_main -pthread

test_deque.o: test_deque.cc deque.h
	g++ -c test_deque.cc

clean:
	rm -f postfix_eval test_deque *.o

