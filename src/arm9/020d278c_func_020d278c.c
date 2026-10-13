/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_45(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210cf9c(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_47(unsigned int, unsigned int, unsigned int);
unsigned int func_020d278c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d2790: r4 = r0;
L_20d2794: r0 = GetActiveExecutionContext();
L_20d2798: r0 = ExecutionContext_GetHeapHandle(r0);
L_20d279c: r1 = 0x44u;
L_20d27a0: r0 = Mem_AllocateHeap(r0,r1);
L_20d27a4: *(unsigned int *)((unsigned char *)r4 + 148) = (unsigned int)r0;
L_20d27a8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d27ac: r2 = (r4+0x4u);
L_20d27b0: r1 = 0x4u;
L_20d27b4: r0 = StructMQRacerEntry_SomeFn_45(r0,r1,r2);
L_20d27b8: r0 = 0x217ca6cu;
L_20d27bc: r1 = 0x0u;
L_20d27c0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 176));
L_20d27c4: *(unsigned int *)((unsigned char *)r4 + 112) = (unsigned int)r0;
L_20d27c8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d27cc: r0 = func_0210cf9c(r0,r1);
L_20d27d0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d27d4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d27d8: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d27e0: if ((cmp_a == cmp_b)) { return r0; }
L_20d27e4: r1 = 0x2u;
L_20d27e8: r2 = 0x1u;
L_20d27ec: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d27f4: return r0;
}
