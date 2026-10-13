/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateSomeObject_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0209c198(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_209c1a0: r0 = 0x209c9fcu;
L_209c1a4: r3 = 0x1u;
L_209c1a8: r1 = 0x209c964u;
L_209c1ac: r2 = 0x209c8b0u;
L_209c1b0: stack_0 = r3;
L_209c1b4: r0 = CreateAllocateSomeObject_from_thumb(r0,r1,r2,r3,stack_0);
L_209c1b8: r1 = 0x156u;
L_209c1bc: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r1;
L_209c1c8: return r0;
}
