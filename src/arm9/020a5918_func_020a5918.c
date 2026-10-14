/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateSomeObject_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020a5918(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_20a5920: r1 = 0x0u;
L_20a5924: r0 = 0x20a6ae4u;
L_20a5928: r2 = r1;
L_20a592c: r3 = 0x1u;
L_20a5930: stack_0 = r1;
L_20a5934: r0 = CreateAllocateSomeObject_from_thumb(r0,r1,r2,r3,stack_0);
L_20a5938: r1 = 0x190000u;
L_20a593c: *(unsigned int *)((unsigned char *)r0 + 56) = (unsigned int)r1;
L_20a5940: r1 = (0x0u-r1);
L_20a5944: *(unsigned int *)((unsigned char *)r0 + 60) = (unsigned int)r1;
L_20a5950: return r0;
}
