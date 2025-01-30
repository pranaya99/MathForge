CXX = g++

all: postfix_eval test_deque

postfix_eval: postfix_eval.o
	$(CXX) -o postfix_eval postfix_eval.o

postfix_eval.o: postfix_eval.cc stack.h
	$(CXX) -c postfix_eval.cc

test_deque: test_deque.o deque.h
	$(CXX) -o test_deque test_deque.o -lgtest -lgtest_main -pthread

test_deque.o: test_deque.cc deque.h
	$(CXX) -c test_deque.cc

clean:
	rm -f postfix_eval test_deque *.o

lint:
	/home/cs36cjp/public/cpplint/cpplint postfix_eval.cc
