/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0201e494(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_201e494: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_201e498: cmp_a = r2; cmp_b = 0x0u;
L_201e49c: if ((cmp_a != cmp_b)) { goto L_201e4bc; }
L_201e4a0: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_201e4a4: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r1;
L_201e4a8: r2 = 0x0u;
L_201e4ac: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_201e4b0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_201e4b4: *(unsigned int *)((unsigned char *)r1 + 4) = (unsigned int)r2;
L_201e4b8: goto L_201e4d4;
L_201e4bc: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_201e4c0: r2 = 0x0u;
L_201e4c4: *(unsigned int *)((unsigned char *)r1 + 4) = (unsigned int)r2;
L_201e4c8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_201e4cc: *(unsigned int *)((unsigned char *)r2 + 4) = (unsigned int)r1;
L_201e4d0: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_201e4d4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_201e4d8: r1 = (r1+0x1u);
L_201e4dc: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_201e4e0: return r0;
}
