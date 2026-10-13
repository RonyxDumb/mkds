/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int func_020f73a4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f73ac: r0 = GetActiveExecutionContext();
L_20f73b0: r0 = ExecutionContext_GetHeapHandle(r0);
L_20f73b4: r1 = 0xcu;
L_20f73b8: r0 = Mem_AllocateHeap(r0,r1);
L_20f73bc: r1 = 0x217bc4cu;
L_20f73c0: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_20f73cc: return r0;
}
