/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int AllocateInputRecord(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_204aa08: r4 = r0;
L_204aa0c: r0 = r1;
L_204aa10: r1 = 0xdccu;
L_204aa14: r0 = Mem_AllocateHeap(r0,r1,r2,r3);
L_204aa18: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_204aa20: return r0;
}
