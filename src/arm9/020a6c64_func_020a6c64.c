/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d2398(unsigned int);
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_45(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210bae8(unsigned int);
unsigned int func_020a6c64(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20a6c68: r4 = r0;
L_20a6c6c: r0 = func_020d2398(r0);
L_20a6c70: r0 = GetActiveExecutionContext();
L_20a6c74: r0 = ExecutionContext_GetHeapHandle(r0);
L_20a6c78: r1 = 0x44u;
L_20a6c7c: r0 = Mem_AllocateHeap(r0,r1);
L_20a6c80: *(unsigned int *)((unsigned char *)r4 + 148) = (unsigned int)r0;
L_20a6c84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20a6c88: r2 = (r4+0x4u);
L_20a6c8c: r1 = 0xbu;
L_20a6c90: r0 = StructMQRacerEntry_SomeFn_45(r0,r1,r2);
L_20a6c94: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20a6c98: r0 = func_0210bae8(r0);
L_20a6c9c: r0 = 0x217ca6cu;
L_20a6ca0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 428));
L_20a6ca4: *(unsigned int *)((unsigned char *)r4 + 112) = (unsigned int)r0;
L_20a6cac: return r0;
}
