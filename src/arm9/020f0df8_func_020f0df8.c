/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ed718(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ed79c(unsigned int, unsigned int);
unsigned int func_020f0df8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f0e00: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 36));
L_20f0e04: cmp_a = r2; cmp_b = 0x0u;
L_20f0e08: if ((cmp_a == cmp_b)) { goto L_20f0e1c; }
L_20f0e0c: r0 = func_020ed718(r0,r1,r2);
L_20f0e18: return r0;
L_20f0e1c: r0 = func_020ed79c(r0,r1);
L_20f0e28: return r0;
}
