/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_DmaCopy32(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int Mem_CpuCopy32(unsigned int, unsigned int, unsigned int);
unsigned int CopyToOamA(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,lr,r4;
L_214bfd0: r3 = 0x216f074u;
L_214bfd4: r4 = r0;
L_214bfd8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_214bfdc: ip = ~(0x0u);
L_214bfe0: lr = r1;
L_214bfe4: r3 = r2;
L_214bfe8: cmp_a = r0; cmp_b = ip;
L_214bfec: if ((cmp_a == cmp_b)) { goto L_214c00c; }
L_214bff0: cmp_a = r3; cmp_b = 0x30u;
L_214bff4: if ((cmp_a <= cmp_b)) { goto L_214c00c; }
L_214bff8: r1 = r4;
L_214bffc: r2 = (lr+0x7000000u);
L_214c000: r0 = MI_DmaCopy32(r0,r1,r2,r3);
L_214c008: return r0;
L_214c00c: r0 = r4;
L_214c010: r2 = r3;
L_214c014: r1 = (lr+0x7000000u);
L_214c018: r0 = Mem_CpuCopy32(r0,r1,r2);
L_214c020: return r0;
}
