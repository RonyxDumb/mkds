/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateSomeObject_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0209c154(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_209c15c: r0 = 0x209c9fcu;
L_209c160: r3 = 0x1u;
L_209c164: r1 = 0x209c964u;
L_209c168: r2 = 0x209c8b0u;
L_209c16c: stack_0 = r3;
L_209c170: r0 = CreateAllocateSomeObject_from_thumb(r0,r1,r2,r3,stack_0);
L_209c174: r1 = 0x155u;
L_209c178: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r1;
L_209c184: return r0;
}
