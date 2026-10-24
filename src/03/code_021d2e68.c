#include "03/code_021d2e68.h"

void func_ov003_021d2e90(unsigned int p0) {
    unsigned int v1 = ((p0) + (0x0u));
    unsigned int v3 = func_0200ca9c((unsigned int) (0x1u));
    unsigned int v4 = ((unsigned int) *(unsigned int *) ((v1) + (4)));
    unsigned int v5 = ((unsigned int) *(unsigned int *) ((v1) + (0)));
    unsigned int v7;
    unsigned int v8;
    unsigned int v12;
    unsigned int v14;
    *(unsigned int *) ((v5) + (4)) = (unsigned int) (v4);
    v7 = ((unsigned int) *(unsigned int *) ((v1) + (0)));
    v8 = ((unsigned int) *(unsigned int *) ((v1) + (4)));
    *(unsigned int *) ((v8) + (0)) = (unsigned int) (v7);
    *(unsigned int *) ((v1) + (4)) = (unsigned int) (0x0u);
    v12 = ((unsigned int) *(unsigned int *) ((v1) + (4)));
    *(unsigned int *) ((v1) + (0)) = (unsigned int) (v12);
    v14 = func_0200cae4((unsigned int) (v3));
}

void func_ov003_021d2e68(unsigned int p0, unsigned int p1) {
    unsigned int v2 = ((p0) + (0x0u));
    unsigned int v3 = ((p1) + (0x0u));
    unsigned int v5 = func_0200ca9c((unsigned int) (0x1u));
    unsigned int v6 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v8;
    unsigned int v12;
    *(unsigned int *) ((v6) + (4)) = (unsigned int) (v3);
    v8 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    *(unsigned int *) ((v3) + (0)) = (unsigned int) (v8);
    *(unsigned int *) ((v3) + (4)) = (unsigned int) (v2);
    *(unsigned int *) ((v2) + (0)) = (unsigned int) (v3);
    v12 = func_0200cae4((unsigned int) (v5));
}
