/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_021112fc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21112fc: r1 = 0x217d32cu;
L_2111300: *(unsigned int *)((unsigned char *)r1 + 12) = (unsigned int)r0;
L_2111304: return r0;
}
