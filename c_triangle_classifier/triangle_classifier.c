#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "triangle_classifier.h"

int convert(const char length[]) {
    if (strlen(length) == 0) return -1;
    if (length[0] == '0') return -1;
    
    long long val = 0;
    for (int i = 0; length[i] != '\0'; i++) {
        if (!isdigit((unsigned char)length[i])) return -1;
        val = val * 10 + (length[i] - '0');
    }

    if (val < 0 || val > INT_MAX) return -1;
    return (int)val;
}

int triangle(int a, int b, int c) {
    long long x = a;
    long long y = b;
    long long z = c;

    if (x <= 0 || y <= 0 || z <= 0) return Illegal;
    if (x + y < z || y + z < x || x + z < y) return Impossible;
    if (x + y == z || x + z == y || y + z == x) return Flat;
    if (x == y && y == z) return Equilateral;
    if (x == y || y == z || x == z) return Isosceles;
    if ((x*x + y*y == z*z) || (x*x + z*z == y*y) || (y*y + z*z == x*x)) return Right;
    return Scalene;
}

void print(int type) {
    switch (type) {
        case Equilateral: printf("Equilateral\n"); break;
        case Isosceles: printf("Isosceles\n"); break;
        case Right: printf("Right\n"); break;
        case Scalene: printf("Scalene\n"); break;
        case Flat: printf("Flat\n"); break;
        case Impossible: printf("Impossible\n"); break;
        case Illegal: printf("Illegal\n"); break;
    }
}

#ifndef TESTING
int main(int n, char *args[]) {
    setbuf(stdout, NULL);
    if (n == 4) {
        int a = convert(args[1]), b = convert(args[2]), c = convert(args[3]);
        print(triangle(a, b, c));
    } else {
        fprintf(stderr, "Usage: ./triangle_classifier a b c\n");
        return 1;
    }
    return 0;
}
#endif
