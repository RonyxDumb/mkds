/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int SomeAlloc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cffa8: r0 = GetActiveExecutionContext();
L_20cffac: r0 = ExecutionContext_GetHeapHandle(r0);
L_20cffb0: r1 = 0x38u;
L_20cffb4: r0 = Mem_AllocateHeap(r0,r1);
L_20cffb8: r1 = 0x217b490u;
L_20cffbc: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_20cffc8: return r0;
}
