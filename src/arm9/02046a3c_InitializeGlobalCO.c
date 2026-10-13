/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int InitializeGlobalRE(unsigned int);
extern unsigned int InitializeGlobalLU(unsigned int);
unsigned int InitializeGlobalCO(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2046a40: r1 = 0x400u;
L_2046a44: r4 = r0;
L_2046a48: r0 = Mem_AllocateHeap(r0,r1);
L_2046a4c: r2 = 0x21759c0u;
L_2046a50: r1 = 0x21u;
L_2046a54: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2046a58: r0 = r4;
L_2046a5c: r0 = Mem_AllocateHeap(r0,r1);
L_2046a60: r1 = 0x21759c0u;
L_2046a64: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2046a68: *(unsigned int *)((unsigned char *)r1 + 988) = (unsigned int)r0;
L_2046a6c: r0 = r4;
L_2046a70: r0 = InitializeGlobalRE(r0);
L_2046a74: r0 = r4;
L_2046a78: r0 = InitializeGlobalLU(r0);
L_2046a80: return r0;
}
