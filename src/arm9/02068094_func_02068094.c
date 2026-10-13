/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0206b020(unsigned int, unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02068094(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2068098: r1 = r2;
L_206809c: r4 = r0;
L_20680a0: r0 = func_0206b020(r0,r1);
L_20680a4: cmp_a = r0; cmp_b = 0x0u;
L_20680ac: if ((cmp_a == cmp_b)) { return r0; }
L_20680b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_20680b4: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_20680b8: if ((cmp_a == cmp_b)) { goto L_20680cc; }
L_20680bc: r0 = GetGlobalRK();
L_20680c0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_20680c4: r1 = (r1+0x1u);
L_20680c8: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_20680cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_20680d0: r0 = (r0|0x20000u);
L_20680d4: *(unsigned int *)((unsigned char *)r4 + 72) = (unsigned int)r0;
L_20680dc: return r0;
}
