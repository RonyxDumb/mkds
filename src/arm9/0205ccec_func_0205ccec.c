/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0205ccec(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205ccec: r0 = 0x217aa14u;
L_205ccf0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_205ccf4: cmp_a = r1; cmp_b = 0x0u;
L_205ccf8: if ((cmp_a == cmp_b)) { return r0; }
L_205ccfc: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 14));
L_205cd00: cmp_a = r0; cmp_b = 0x4u;
L_205cd04: if ((cmp_a == cmp_b)) { goto L_205cd10; }
L_205cd08: cmp_a = r0; cmp_b = 0x5u;
L_205cd0c: if ((cmp_a != cmp_b)) { return r0; }
L_205cd10: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 1832));
L_205cd14: r0 = (r0+0x1u);
L_205cd18: *(unsigned int *)((unsigned char *)r1 + 1832) = (unsigned int)r0;
L_205cd1c: return r0;
}
