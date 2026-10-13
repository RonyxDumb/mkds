/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_CpuFill8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0204a978(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_204a97c: r4 = r0;
L_204a980: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_204a984: cmp_a = r0; cmp_b = 0x0u;
L_204a98c: if ((cmp_a == cmp_b)) { return r0; }
L_204a990: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 12));
L_204a994: cmp_a = r1; cmp_b = 0x0u;
L_204a998: if ((cmp_a != cmp_b)) { goto L_204a9b8; }
L_204a99c: cmp_a = r0; cmp_b = 0x0u;
L_204a9a0: if ((cmp_a == cmp_b)) { goto L_204a9b0; }
L_204a9a4: r2 = 0xdccu;
L_204a9a8: r1 = 0x0u;
L_204a9ac: r0 = Mem_CpuFill8(r0,r1,r2,r3);
L_204a9b0: r0 = 0x1u;
L_204a9b4: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r0;
L_204a9b8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_204a9bc: r1 = 0x0u;
L_204a9c0: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_204a9c4: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r1;
L_204a9c8: *(unsigned short *)((unsigned char *)r4 + 4) = (unsigned short)r1;
L_204a9cc: *(unsigned short *)((unsigned char *)r4 + 6) = (unsigned short)r1;
L_204a9d0: r0 = 0x1u;
L_204a9d4: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r0;
L_204a9dc: return r0;
}
