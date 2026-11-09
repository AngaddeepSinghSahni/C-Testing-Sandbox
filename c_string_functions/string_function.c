#include "string_function.h"

int length(const char s[]) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count++;
    }
    return count;
}

void copy(char t[], const char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        t[i] = s[i];
    }
    t[i] = '\0';
}

int compare(const char s[], const char t[]) {
    int i;
    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0' && t[i] == '\0') return 0;
    }
    return (s[i] - t[i]);
}

void append(char t[], const char s[]) {
    int i;
    int j;
    for (i = 0; t[i] != '\0'; i++);
    for (j = 0; s[j] != '\0'; j++) {
        t[i + j] = s[j];    
    }
    t[i + j] = '\0';
}

int find(const char t[], const char s[]) {
    int i;
    int j;
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == s[0]) {
            for (j = 0; s[j] != '\0' && s[j] == t[i + j]; j++);
            if (s[j] == '\0') return i;
            j = 0;
        }
    }
    return -1;      
}
