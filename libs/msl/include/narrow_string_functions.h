#pragma once

#include "types.h"

char *strstr(const char *haystack, const char *needle);
char *strchr(const char *string, int chr);
int strncmp(const char *left, const char *right, u32 count);
int strcmp(const char *left, const char *right);
char *strcat(char *dst, const char *src);
char *SomeStrncpy_0(char *dst, const char *src, u32 count);
char *strcpy(char *dst, const char *src);
u32 strlen(const char *string);
double atof(const char *string);
