/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_FindTopParentHeapHead(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int Mem_FindTopParentHeapHeadList(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2017618: r4 = 0x2173268u;
L_201761c: r1 = r0;
L_2017620: r0 = r4;
L_2017624: r0 = Mem_FindTopParentHeapHead(r0,r1,r2,r3);
L_2017628: cmp_a = r0; cmp_b = 0x0u;
L_201762c: if ((cmp_a != cmp_b)) { r4 = (r0+0xcu); }
L_2017630: r0 = r4;
L_2017638: return r0;
}
