/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int func_02081224(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208122c: r1 = 0x217ae84u;
L_2081230: r4 = r0;
L_2081234: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2081238: r0 = 0x58u;
L_208123c: r5 = (r4*r0+r1);
L_2081240: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 48));
L_2081244: cmp_a = r0; cmp_b = 0x0u;
L_2081248: if ((cmp_a == cmp_b)) { goto L_2081250; }
L_208124c: r0 = func_0208b710(r0);
L_2081250: r1 = 0x2155a14u;
L_2081254: r0 = 0x5eu;
L_2081258: r0 = func_0208b7bc(r0,r1);
L_208125c: *(unsigned int *)((unsigned char *)r5 + 48) = (unsigned int)r0;
L_2081260: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 48));
L_2081264: r0 = 0x0u;
L_2081268: *(unsigned char *)((unsigned char *)r1 + 154) = (unsigned char)r0;
L_208126c: r0 = 0x78u;
L_2081270: *(unsigned char *)((unsigned char *)r1 + 153) = (unsigned char)r0;
L_2081274: r0 = 0x2081120u;
L_2081278: *(unsigned char *)((unsigned char *)r1 + 155) = (unsigned char)r4;
L_208127c: *(unsigned int *)((unsigned char *)r1 + 144) = (unsigned int)r0;
L_2081288: return r0;
}
