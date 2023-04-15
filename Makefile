CC= g++ -Wall -Werror -Wextra
LIBS= -lgtest -lpthread
GFLAGS= -fprofile-arcs -ftest-coverage
SOURSE = src/**/*.inl rc/**/*.h src/containers.h

ifeq ($(shell uname -s), Linux) 
	OPEN = x-www-browser
else
	OPEN = open
endif

all: containers.a

containers.o:
	$(CC) -c src/containers.h -o containers.o

containers.a: containers.o
	ar rcs containers.a containers.o
	ranlib containers.a

test: clean
	$(CC) $(GFLAGS) -o test tests/test.cc $(LIBS)
	./test

gcov_report:
	lcov --no-external -t test -c -d . -o coverage.info
	genhtml coverage.info -o coverage
	$(OPEN) ./coverage/index.html

check:
	cp linters/.clang-format ./
	clang-format -n $(SOURSE)
	cppcheck --std=c++17 --language=c++ --enable=all --suppress=missingInclude --suppress=unusedFunction --suppress=uselessAssignmentArg --suppress=unreadVariable $(SOURSE)
	rm .clang-format

valgrind:
	valgrind --leak-check=summary -s ./test

leaks: test
	CK_FORK=no leaks -atExit -- ./test

clean:
	rm -rf *.o *.a test coverage *.info *.gcda *.gcno
