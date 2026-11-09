#ifndef TRIANGLE_CLASSIFIER_H
#define TRIANGLE_CLASSIFIER_H

enum {Equilateral, Isosceles, Right, Scalene, Flat, Impossible, Illegal};

int convert(const char length[]);
int triangle(int a, int b, int c);
void print(int type);

#endif
