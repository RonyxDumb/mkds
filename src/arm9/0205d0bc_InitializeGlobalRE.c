/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int InitializeGlobalRE(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205d0c4: r1 = 0xau;
L_205d0c8: r0 = Mem_AllocateHeap(r0,r1);
L_205d0cc: r1 = 0x217aa18u;
L_205d0d0: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_205d0d4: r0 = 0xau;
L_205d0e0: return r0;
}
