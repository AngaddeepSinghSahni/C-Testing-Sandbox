CC = gcc
CFLAGS = -Wall -Wextra -O2

all: triangle_classifier test_runner

triangle_classifier: triangle_classifier.c triangle_classifier.h
	$(CC) $(CFLAGS) -o triangle_classifier triangle_classifier.c

test_runner: triangle_classifier.c test_triangle_classifier.c triangle_classifier.h
	$(CC) $(CFLAGS) -DTESTING -o test_runner triangle_classifier.c test_triangle_classifier.c

clean:
	rm -f triangle_classifier test_runner
