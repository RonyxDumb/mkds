/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int AllocateNewDriverSub208(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e0654: r4 = r0;
L_20e0658: r0 = GetActiveExecutionContext();
L_20e065c: r0 = ExecutionContext_GetHeapHandle(r0);
L_20e0660: r1 = 0x1cu;
L_20e0664: r0 = Mem_AllocateHeap(r0,r1);
L_20e0668: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20e066c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20e0670: r1 = 0x0u;
L_20e0674: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20e067c: return r0;
}
