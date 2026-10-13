/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02093eac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2093eac: cmp_a = r0; cmp_b = 0x0u;
L_2093eb0: if ((cmp_a == cmp_b)) { return r0; }
L_2093eb4: r3 = 0x0u;
L_2093eb8: r2 = r3;
L_2093ebc: goto L_2093ec8;
L_2093ec0: *(unsigned int *)((unsigned char *)r1 + 160) = (unsigned int)r2;
L_2093ec4: r3 = (r3+0x1u);
L_2093ec8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 4));
L_2093ecc: cmp_a = r3; cmp_b = r1;
L_2093ed0: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_2093ed4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2093ed8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + (0 + (r3 << 2))));
L_2093edc: cmp_a = r1; cmp_b = 0x0u;
L_2093ee0: if ((cmp_a != cmp_b)) { goto L_2093ec0; }
L_2093ee4: return r0;
}
