/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0209bf48(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020e6f50(unsigned int);
unsigned int func_0209828c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2098294: r0 = 0x209886cu;
L_2098298: r1 = 0x20983c4u;
L_209829c: r2 = 0x0u;
L_20982a0: r0 = func_0209bf48(r0,r1,r2);
L_20982a4: r1 = 0x217b0fcu;
L_20982a8: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_20982ac: r0 = r1;
L_20982b0: r0 = func_020e6f50(r0);
L_20982b4: r0 = 0x217b0fcu;
L_20982b8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20982c4: return r0;
}
