/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020ab058(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ab058: r1 = 0x217b278u;
L_20ab05a: *(unsigned int *)((unsigned char *)r1 + 80) = (unsigned int)r0;
L_20ab05c: return r0;
}
