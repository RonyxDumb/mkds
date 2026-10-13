/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MaybeKillDriverDirect(unsigned int);
extern unsigned int func_020a1790(void);
unsigned int func_020a16d0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a16d8: r1 = 0x217b1fcu;
L_20a16dc: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20a16e0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 948));
L_20a16e4: cmp_a = r1; cmp_b = 0x0u;
L_20a16f0: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20a16f4: r1 = 0x70u;
L_20a16f8: r1 = (r0*r1+r2);
L_20a16fc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20a1700: cmp_a = r1; cmp_b = 0x0u;
L_20a170c: if ((cmp_a != cmp_b)) { return r0; }
L_20a1710: r0 = MaybeKillDriverDirect(r0);
L_20a1714: r0 = func_020a1790();
L_20a1720: return r0;
}
