/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DriverContext_ApplyShroomBoost(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_020f4754(unsigned int, unsigned int);
extern unsigned int func_020fe958(unsigned int);
unsigned int func_020f504c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20f5054: r4 = r1;
L_20f5058: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_20f505c: r5 = r0;
L_20f5060: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 508));
L_20f5064: r0 = DriverContext_ApplyShroomBoost(r0,r1,r2,r3);
L_20f5068: r0 = r4;
L_20f506c: r1 = 0x1u;
L_20f5070: r0 = func_020f4754(r0,r1);
L_20f5074: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_20f5078: r2 = 0x1u;
L_20f507c: r0 = 0x21759c0u;
L_20f5080: *(unsigned int *)((unsigned char *)r1 + 516) = (unsigned int)r2;
L_20f5084: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20f5088: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20f508c: cmp_a = r0; cmp_b = 0x5u;
L_20f5098: if ((cmp_a != cmp_b)) { return r0; }
L_20f509c: r0 = 0x3u;
L_20f50a0: r0 = func_020fe958(r0);
L_20f50ac: return r0;
}
