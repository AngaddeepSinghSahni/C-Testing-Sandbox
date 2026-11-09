#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H

// Find the length of a string, assuming it has a null terminator (like strlen).
int length(const char s[]);

// Copy string s into the character array t (like strcpy).
void copy(char t[], const char s[]);

// Compare two strings, returning negative, zero or positive (like strcmp).
int compare(const char s[], const char t[]);

// Join string s to the end of string t (like strcat).
void append(char t[], const char s[]);

// Find the (first) position of s in t, or return -1 (like strstr).
int find(const char t[], const char s[]);

#endif