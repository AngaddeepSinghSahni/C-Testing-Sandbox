#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "triangle_classifier.h"

void custom_assert(int line, bool b) {
    if (b) return;
    printf("The test on line %d fails.\n", line);
    exit(1);
}

void checkConstants() {
    custom_assert(__LINE__, Equilateral==0 && Isosceles==1 && Right==2 && Scalene==3);
    custom_assert(__LINE__, Flat==4 && Impossible==5 && Illegal==6);
}

void testEquilateral() {
    custom_assert(__LINE__, triangle(8, 8, 8) == Equilateral);
    custom_assert(__LINE__, triangle(1073, 1073, 1073) == Equilateral);
}

void testIsosceles() {
    custom_assert(__LINE__, triangle(25, 25, 27) == Isosceles);
    custom_assert(__LINE__, triangle(25, 27, 25) == Isosceles);
    custom_assert(__LINE__, triangle(27, 25, 25) == Isosceles);
}

void testRight() {
    custom_assert(__LINE__, triangle(3, 4, 5) == Right);
    custom_assert(__LINE__, triangle(3, 5, 4) == Right);
    custom_assert(__LINE__, triangle(5, 3, 4) == Right);
    custom_assert(__LINE__, triangle(5, 12, 13) == Right);
    custom_assert(__LINE__, triangle(5, 13, 12) == Right);
    custom_assert(__LINE__, triangle(12, 5, 13) == Right);
    custom_assert(__LINE__, triangle(12, 13, 5) == Right);
    custom_assert(__LINE__, triangle(13, 5, 12) == Right);
    custom_assert(__LINE__, triangle(13, 12, 5) == Right);
}

void testScalene() {
    custom_assert(__LINE__, triangle(12, 14, 15) == Scalene);
    custom_assert(__LINE__, triangle(12, 15, 14) == Scalene);
    custom_assert(__LINE__, triangle(14, 12, 15) == Scalene);
    custom_assert(__LINE__, triangle(14, 15, 12) == Scalene);
    custom_assert(__LINE__, triangle(15, 12, 14) == Scalene);
    custom_assert(__LINE__, triangle(15, 14, 12) == Scalene);
}

void testFlat() {
    custom_assert(__LINE__, triangle(7, 9, 16) == Flat);
    custom_assert(__LINE__, triangle(7, 16, 9) == Flat);
    custom_assert(__LINE__, triangle(9, 16, 7) == Flat);
    custom_assert(__LINE__, triangle(16, 7, 9) == Flat);
    custom_assert(__LINE__, triangle(16, 9, 7) == Flat);
}

void testImpossible() {
    custom_assert(__LINE__, triangle(2, 3, 13) == Impossible);
    custom_assert(__LINE__, triangle(2, 13, 3) == Impossible);
    custom_assert(__LINE__, triangle(3, 2, 13) == Impossible);
    custom_assert(__LINE__, triangle(3, 13, 2) == Impossible);
    custom_assert(__LINE__, triangle(13, 2, 3) == Impossible);
    custom_assert(__LINE__, triangle(13, 3, 2) == Impossible);
}

void testConvert() {
    custom_assert(__LINE__, convert("1") == 1);
    custom_assert(__LINE__, convert("12345678") == 12345678);
    custom_assert(__LINE__, convert("2147483647") == 2147483647);
    custom_assert(__LINE__, convert("2147483648") == -1);
    custom_assert(__LINE__, convert("2147483649") == -1);
    custom_assert(__LINE__, convert("0") == -1);
    custom_assert(__LINE__, convert("-1") == -1);
    custom_assert(__LINE__, convert("-2") == -1);
    custom_assert(__LINE__, convert("-2147483648") == -1);
    custom_assert(__LINE__, convert("x") == -1);
    custom_assert(__LINE__, convert("4y") == -1);
    custom_assert(__LINE__, convert("13.4") == -1);
    custom_assert(__LINE__, convert("03") == -1);
}

void testOverflow() {
    custom_assert(__LINE__, triangle(2147483647,2147483647,2147483646) == Isosceles);
    custom_assert(__LINE__, triangle(2147483645,2147483646,2147483647) == Scalene);
    custom_assert(__LINE__, triangle(2147483647,2147483647,2147483647) == Equilateral);
    custom_assert(__LINE__, triangle(1100000000,1705032704,1805032704) == Scalene);
    custom_assert(__LINE__, triangle(2000000001,2000000002,2000000003) == Scalene);
    custom_assert(__LINE__, triangle(150000002,666666671,683333338) == Scalene);
}

int main() {
    checkConstants();
    testEquilateral();
    testIsosceles();
    testRight();
    testScalene();
    testFlat();
    testImpossible();
    testConvert();
    testOverflow();
    printf("All Triangle Classifier tests passed successfully (50+ assertions)!\n");
    return 0;
}
