/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateSomeObject_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0209c1dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_209c1e4: r0 = 0x209c9fcu;
L_209c1e8: r3 = 0x1u;
L_209c1ec: r1 = 0x209c964u;
L_209c1f0: r2 = 0x209c8b0u;
L_209c1f4: stack_0 = r3;
L_209c1f8: r0 = CreateAllocateSomeObject_from_thumb(r0,r1,r2,r3,stack_0);
L_209c1fc: r1 = 0x1cfu;
L_209c200: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r1;
L_209c20c: return r0;
}
