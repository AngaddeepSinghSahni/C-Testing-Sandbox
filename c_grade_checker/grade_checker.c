#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "grade_checker.h"

int convert(int n, const char mark[]) {
    if (n <= 0 || n > 3) return -1;
    if (mark[0] == '0' && n > 1) return -1;

    int val = 0;
    for (int i = 0; i < n; i++) {
        if (!isdigit((unsigned char)mark[i])) return -1;
        val = val * 10 + (mark[i] - '0');
    }
    
    if (val < 0 || val > 100) return -1;
    return val;
}

int grade(int m) {
    if (m < 0 || m > 100) return Invalid;
    if (m >= 70) return G1;
    if (m >= 60) return G21;
    if (m >= 50) return G22;
    if (m >= 40) return G3;
    return Fail;
}

void print(int grade) {
    if (grade == G1) printf("First\n");
    else if (grade == G21) printf("Upper second\n");
    else if (grade == G22) printf("Lower second\n");
    else if (grade == G3) printf("Third\n");
    else if (grade == Fail) printf("Fail\n");
    else if (grade == Invalid) printf("Invalid mark\n");
}

#ifndef TESTING
int main(int n, char *args[]) {
    setbuf(stdout, NULL);
    if (n == 2) {
        print(grade(convert(strlen(args[1]), args[1])));
    } else {
        fprintf(stderr, "Usage: ./grade_checker m\nwhere m is a mark from 0 to 100\n");
        return 1;
    }
    return 0;
}
#endif
