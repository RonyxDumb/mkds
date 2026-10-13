/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_Frame_SomeFn4(unsigned int);
extern unsigned int Mem_FindGlobalTopParentHeapHead(unsigned int);
extern unsigned int Mem_ResizeExpHeap(unsigned int, unsigned int, unsigned int);
unsigned int func_02036820(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2036828: r5 = r0;
L_203682c: r0 = Mem_Frame_SomeFn4(r0);
L_2036830: r4 = r0;
L_2036834: r0 = r5;
L_2036838: r0 = Mem_FindGlobalTopParentHeapHead(r0);
L_203683c: r1 = r5;
L_2036840: r2 = r4;
L_2036844: r0 = Mem_ResizeExpHeap(r0,r1,r2);
L_2036850: return r0;
}
