/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020f40a0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20f40a0: r2 = 0x217bc48u;
L_20f40a4: r3 = 0x27e00ccu;
L_20f40a8: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20f40ac: r2 = 0x1cu;
L_20f40b0: r2 = (r0*r2+ip);
L_20f40b4: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 8));
L_20f40b8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_20f40bc: r0 = 0x44u;
L_20f40c0: r2 = (ip*r0+r2);
L_20f40c4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 28));
L_20f40c8: r0 = (r0-r1);
L_20f40cc: *(unsigned int *)((unsigned char *)r2 + 28) = (unsigned int)r0;
L_20f40d0: return r0;
}
