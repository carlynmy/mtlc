CXX=g++
CXX_FLAGS=-Wall -Werror -Wextra
GCOV_FLAGS= --coverage
GCOV_LIBS= -lgcov

DEBUG_BUILD_TYPE=-DCMAKE_BUILD_TYPE=Debug
GCOV_REPORT_FLAGS=-DMATRIX_COVERAGE_FLAGS:STRING="$(GCOV_FLAGS)"
GCOV_REPORT_LIBS=-DMATRIX_COVERAGE_LIBS:STRING="$(GCOV_LIBS)"
RELEASE_BUILD_TYPE=-DCMAKE_BUILD_TYPE=Release
GCOV_NO_REPORT_FLAGS=-DMATRIX_COVERAGE_FLAGS:STRING=""
GCOV_NO_REPORT_LIBS=-DMATRIX_COVERAGE_LIBS:STRING=""


REPORT_BUILD= $(DEBUG_BUILD_TYPE) $(GCOV_REPORT_FLAGS) $(GCOV_REPORT_LIBS)
STANDART_BUILD= $(DEBUG_BUILD_TYPE) $(GCOV_NO_REPORT_FLAGS) $(GCOV_NO_REPORT_LIBS)

PATH_BUILD=build
PATH_REPORT=report

.PHONY: all clean rebuild test gcov_report valgrind leaks

all: test

clean:
	rm -rf $(PATH_BUILD)
	rm -rf $(PATH_REPORT)

rebuild: clean all

test:
	cmake -B $(PATH_BUILD) $(STANDART_BUILD) 
	cmake --build $(PATH_BUILD) --target matrix_tests
	./$(PATH_BUILD)/matrix_tests

gcov_report: 
	rm -rf $(PATH_REPORT)
	cmake -B $(PATH_BUILD) $(REPORT_BUILD) 
	cmake --build $(PATH_BUILD) --target matrix_tests
	./$(PATH_BUILD)/matrix_tests
	mkdir $(PATH_REPORT)	
	gcovr --html-details -o $(PATH_REPORT)/index.html
	open $(PATH_REPORT)/index.html

valgrind:
	cmake -B $(PATH_BUILD) $(STANDART_BUILD)
	cmake --build $(PATH_BUILD) --target matrix_tests
	valgrind $(PATH_BUILD)/matrix_tests

leaks:
	cmake -B $(PATH_BUILD) 
	cmake --build $(PATH_BUILD) --target matrix_tests
	leaks -atExit -- $(PATH_BUILD)/matrix_tests
