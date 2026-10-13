/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int SomeAlloc2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d12b8: r0 = GetActiveExecutionContext();
L_20d12bc: r0 = ExecutionContext_GetHeapHandle(r0);
L_20d12c0: r1 = 0x4u;
L_20d12c4: r0 = Mem_AllocateHeap(r0,r1);
L_20d12c8: r1 = 0x217b4a8u;
L_20d12cc: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_20d12d8: return r0;
}
