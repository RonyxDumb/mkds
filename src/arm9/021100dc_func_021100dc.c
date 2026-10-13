/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_021100dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_21100dc: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_21100e0: r0 = 0x0u;
L_21100e4: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)ip + 58));
L_21100e8: cmp_a = r3; cmp_b = r2;
L_21100ec: if ((cmp_a != cmp_b)) { return r0; }
L_21100f0: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)ip + 56));
L_21100f4: cmp_a = r2; cmp_b = r1;
L_21100f8: if ((cmp_a == cmp_b)) { r0 = 0x1u; }
L_21100fc: return r0;
}
