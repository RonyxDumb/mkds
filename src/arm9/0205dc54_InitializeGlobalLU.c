/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int InitializeGlobalLU(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205dc5c: r1 = 0x168u;
L_205dc60: r0 = Mem_AllocateHeap(r0,r1);
L_205dc64: r1 = 0x217aa1cu;
L_205dc68: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_205dc74: return r0;
}
