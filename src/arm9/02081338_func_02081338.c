/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
unsigned int func_02081338(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_208133c: r2 = 0x217ae84u;
L_2081340: r1 = 0x58u;
L_2081344: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2081348: r4 = (r0*r1+r2);
L_208134c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 40));
L_2081350: cmp_a = r0; cmp_b = 0x0u;
L_2081358: if ((cmp_a == cmp_b)) { return r0; }
L_208135c: r0 = func_0208b710(r0);
L_2081360: r0 = 0x0u;
L_2081364: *(unsigned int *)((unsigned char *)r4 + 40) = (unsigned int)r0;
L_208136c: return r0;
}
