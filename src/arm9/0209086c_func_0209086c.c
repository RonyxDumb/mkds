/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetDriverEntry(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_0207ffa4(unsigned int, unsigned int, unsigned int);
extern unsigned int DriverContext_ApplyDriftBoost(unsigned int);
unsigned int func_0209086c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2090870: r6 = r1;
L_2090874: r4 = r0;
L_2090878: r0 = r6;
L_209087c: r0 = GetDriverEntry(r0,r1,r2,r3);
L_2090880: r1 = 0x27e00c8u;
L_2090884: *(unsigned short *)((unsigned char *)r4 + 36) = (unsigned short)r6;
L_2090888: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_209088c: r1 = 0x210u;
L_2090890: r1 = (r6*r1+r2);
L_2090894: r5 = r0;
L_2090898: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 496));
L_209089c: r0 = r4;
L_20908a0: r1 = r6;
L_20908a4: r0 = func_0207ffa4(r0,r1,r2);
L_20908a8: r2 = 0x0u;
L_20908ac: *(unsigned short *)((unsigned char *)r4 + 38) = (unsigned short)r2;
L_20908b0: r0 = r5;
L_20908b4: *(unsigned short *)((unsigned char *)r4 + 40) = (unsigned short)r2;
L_20908b8: r1 = (r5+0x300u);
L_20908bc: *(unsigned short *)((unsigned char *)r1 + 136) = (unsigned short)r2;
L_20908c0: r0 = DriverContext_ApplyDriftBoost(r0);
L_20908c8: return r0;
}
