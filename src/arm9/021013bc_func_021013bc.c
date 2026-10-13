/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02101f7c(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_020fe694(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_021013bc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_21013c0: r4 = r0;
L_21013c4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 588));
L_21013c8: cmp_a = r1; cmp_b = 0x0u;
L_21013d0: if ((cmp_a == cmp_b)) { return r0; }
L_21013d4: r1 = ~(0x0u);
L_21013d8: r0 = func_02101f7c(r0,r1,r2,r3);
L_21013dc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 320));
L_21013e0: r1 = (unsigned int)(*(short *)((unsigned char *)r4 + 78));
L_21013e4: r3 = (r0&0xffu);
L_21013e8: r0 = 0xbu;
L_21013ec: r2 = 0x0u;
L_21013f0: r0 = func_020fe694(r0,r1,r2,r3);
L_21013f4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 320));
L_21013f8: r0 = 0x0u;
L_21013fc: *(unsigned int *)((unsigned char *)r4 + 592) = (unsigned int)r1;
L_2101400: *(unsigned int *)((unsigned char *)r4 + 588) = (unsigned int)r0;
L_2101408: return r0;
}
