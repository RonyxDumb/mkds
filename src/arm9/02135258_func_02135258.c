/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02134eb8(unsigned int, unsigned int, unsigned int);
unsigned int func_02135258(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2135260: r4 = r0;
L_2135264: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 8));
L_2135268: r5 = r2;
L_213526c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_2135270: r0 = (r3+r5);
L_2135274: cmp_a = r0; cmp_b = r2;
L_2135278: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_213527c: if ((cmp_a > cmp_b)) { r5 = (r2-r3); }
L_2135280: r2 = r5;
L_2135284: r0 = (r0+r3);
L_2135288: r0 = func_02134eb8(r0,r1,r2);
L_213528c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 8));
L_2135290: r0 = 0x1u;
L_2135294: r1 = (r1+r5);
L_2135298: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r1;
L_21352a4: return r0;
}
