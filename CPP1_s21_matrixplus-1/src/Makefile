OS=MAC;
USERNAME:=$(shell uname -s)
CC = clang++ -std=c++17 -fprofile-arcs -ftest-coverage
FLAGS = -Wall -Werror -Wextra
ALL_CPP_FILES = s21_*.cpp
ALL_O_FILES = s21_*.o
TEST_FLAGS = -pthread -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main 
LIBRARY = s21_matrix_oop.a
TEST_LIBRARY = test
GCOVFLAGS = -fprofile-arcs -ftest-coverage
TEST_SOURCES = ./tests/*.cpp
TEST_EXECUTABLE = test

all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) $(FLAGS) -c $(ALL_CPP_FILES)
	ar rcs $(LIBRARY) $(ALL_O_FILES)
	rm -rf *.o
build_test: clean s21_matrix_oop.a
	$(CC) $(TEST_SOURCES) -L.  -I. $(LIBRARY) -o $(TEST_EXECUTABLE) $(TEST_FLAGS) $(ADD_LIB)
test: build_test
	./test
gcov_report: clean s21_matrix_oop.a
	lcov -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html
format:
	cp ../materials/linters/.clang-format .
	find . -type f \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} \; -exec clang-format -n {} \;
clean: 
	rm -rf $(LIBRARY) $(TEST_LIBRARY) report *.o *.a *.gcda *.gcno *.gcov *.html *.css *.info *.profraw
rebuild: clean all
