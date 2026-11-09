#ifndef GRADE_CHECKER_H
#define GRADE_CHECKER_H

enum {G1, G21, G22, G3, Fail, Invalid};

int convert(int n, const char mark[]);
int grade(int m);
void print(int grade);

#endif
