/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateSomeObject_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020a9224(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_20a922c: r1 = 0x0u;
L_20a9230: r3 = 0x1u;
L_20a9234: r0 = 0x20a9de4u;
L_20a9238: r2 = r1;
L_20a923c: stack_0 = r3;
L_20a9240: r0 = CreateAllocateSomeObject_from_thumb(r0,r1,r2,r3,stack_0);
L_20a9244: r2 = 0x190000u;
L_20a9248: r1 = 0x1f4000u;
L_20a924c: *(unsigned int *)((unsigned char *)r0 + 56) = (unsigned int)r2;
L_20a9250: r1 = (0x0u-r1);
L_20a9254: *(unsigned int *)((unsigned char *)r0 + 60) = (unsigned int)r1;
L_20a9260: return r0;
}
