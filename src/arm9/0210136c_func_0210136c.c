/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0210136c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210136c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 592));
L_2101370: r1 = ~(0x0u);
L_2101374: cmp_a = r2; cmp_b = r1;
L_2101378: if ((cmp_a == cmp_b)) { return r0; }
L_210137c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 588));
L_2101380: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 304));
L_2101384: cmp_a = r1; cmp_b = 0x0u;
L_2101388: if ((cmp_a != cmp_b)) { goto L_2101394; }
L_210138c: cmp_a = r2; cmp_b = 0x28u;
L_2101390: if (((int)cmp_a < (int)cmp_b)) { return r0; }
L_2101394: r1 = (r2-0x28u);
L_2101398: *(unsigned int *)((unsigned char *)r0 + 616) = (unsigned int)r1;
L_210139c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 592));
L_21013a0: r1 = (r0+0x100u);
L_21013a4: *(unsigned int *)((unsigned char *)r0 + 320) = (unsigned int)r2;
L_21013a8: r0 = 0x2u;
L_21013ac: *(unsigned short *)((unsigned char *)r1 + 60) = (unsigned short)r0;
L_21013b0: r0 = 0x1u;
L_21013b4: *(unsigned short *)((unsigned char *)r1 + 62) = (unsigned short)r0;
L_21013b8: return r0;
}
