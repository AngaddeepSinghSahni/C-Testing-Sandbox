CC = gcc
CFLAGS = -Wall -Wextra -O2

all: grade_checker test_runner

grade_checker: grade_checker.c grade_checker.h
	$(CC) $(CFLAGS) -o grade_checker grade_checker.c

test_runner: grade_checker.c test_grade_checker.c grade_checker.h
	$(CC) $(CFLAGS) -DTESTING -o test_runner grade_checker.c test_grade_checker.c

clean:
	rm -f grade_checker test_runner
