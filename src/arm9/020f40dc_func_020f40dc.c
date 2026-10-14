/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0206c14c(unsigned int);
unsigned int func_020f40dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20f40e4: r5 = r0;
L_20f40e8: r4 = r1;
L_20f40ec: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r4;
L_20f40f0: *(unsigned int *)((unsigned char *)r5 + 8) = (unsigned int)r2;
L_20f40f4: r0 = 0x0u;
L_20f40f8: *(unsigned int *)((unsigned char *)r5 + 32) = (unsigned int)r0;
L_20f40fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 4));
L_20f4100: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 508));
L_20f4104: r0 = func_0206c14c(r0);
L_20f4108: r1 = 0x217bc48u;
L_20f410c: r0 = 0x1cu;
L_20f4110: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20f4114: r1 = 0x0u;
L_20f4118: r0 = (r4*r0+r2);
L_20f411c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 16));
L_20f4120: *(unsigned int *)((unsigned char *)r5 + 12) = (unsigned int)r0;
L_20f4124: *(unsigned short *)((unsigned char *)r5 + 16) = (unsigned short)r1;
L_20f4128: *(unsigned short *)((unsigned char *)r5 + 18) = (unsigned short)r1;
L_20f4134: return r0;
}
