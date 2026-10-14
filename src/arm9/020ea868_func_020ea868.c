/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207aec8(unsigned int, unsigned int, unsigned int);
unsigned int func_020ea868(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20ea870: r5 = r0;
L_20ea874: r4 = (unsigned int)(*(unsigned short *)((unsigned char *)r5 + 110));
L_20ea878: cmp_a = r3; cmp_b = r4;
L_20ea87c: if ((cmp_a >= cmp_b)) { goto L_20ea898; }
L_20ea880: *(unsigned short *)((unsigned char *)r5 + 110) = (unsigned short)r3;
L_20ea884: r0 = func_0207aec8(r0,r1,r2);
L_20ea88c: *(unsigned short *)((unsigned char *)r5 + 110) = (unsigned short)r4;
L_20ea894: return r0;
L_20ea898: r0 = func_0207aec8(r0,r1,r2);
L_20ea8a4: return r0;
}
