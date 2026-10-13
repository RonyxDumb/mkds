/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_FindTopParentHeapHeadList(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int IntrusiveListWrapper_RemoveItem(unsigned int, unsigned int);
unsigned int Mem_FinalizeHeapHead(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_201756c: r4 = r0;
L_2017570: r0 = Mem_FindTopParentHeapHeadList(r0,r1,r2,r3);
L_2017574: r1 = r4;
L_2017578: r0 = IntrusiveListWrapper_RemoveItem(r0,r1);
L_2017580: return r0;
}
