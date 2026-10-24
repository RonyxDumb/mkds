#include "00/code_021a4480.h"

void func_ov000_021a4480(unsigned int p0, unsigned int p1, unsigned int p2) {
    unsigned int v1;
    unsigned int v2;
    unsigned int v4;
    unsigned int v6;
    unsigned int v8;
    unsigned int v10;
    unsigned int v11;
    *(unsigned char *) ((p0) + (0)) = (unsigned char) (p1);
    v1 = ((p0) + (0x1u));
    v2 = ((unsigned int) *(unsigned char *) ((p2) + (0)));
    *(unsigned char *) ((p0) + (1)) = (unsigned char) (v2);
    v4 = ((unsigned int) *(unsigned char *) ((p2) + (1)));
    *(unsigned char *) ((v1) + (1)) = (unsigned char) (v4);
    v6 = ((unsigned int) *(unsigned char *) ((p2) + (2)));
    *(unsigned char *) ((v1) + (2)) = (unsigned char) (v6);
    v8 = ((unsigned int) *(unsigned char *) ((p2) + (3)));
    *(unsigned char *) ((v1) + (3)) = (unsigned char) (v8);
    v10 = 0x5u;
    v11 = 0x800u;
    *(unsigned int *) ((p0) + (0 + (v11))) = (unsigned int) (v10);
}
