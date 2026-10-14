/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_45(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210cf9c(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_47(unsigned int, unsigned int, unsigned int);
unsigned int func_020d286c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d2870: r4 = r0;
L_20d2874: r0 = GetActiveExecutionContext();
L_20d2878: r0 = ExecutionContext_GetHeapHandle(r0);
L_20d287c: r1 = 0x60u;
L_20d2880: r0 = Mem_AllocateHeap(r0,r1);
L_20d2884: *(unsigned int *)((unsigned char *)r4 + 148) = (unsigned int)r0;
L_20d2888: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d288c: r2 = (r4+0x4u);
L_20d2890: r1 = 0x2u;
L_20d2894: r0 = StructMQRacerEntry_SomeFn_45(r0,r1,r2);
L_20d2898: r0 = 0x217ca6cu;
L_20d289c: r1 = 0x0u;
L_20d28a0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 104));
L_20d28a4: *(unsigned int *)((unsigned char *)r4 + 112) = (unsigned int)r0;
L_20d28a8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d28ac: r0 = func_0210cf9c(r0,r1);
L_20d28b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d28b4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d28b8: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d28bc: if ((cmp_a == cmp_b)) { goto L_20d28cc; }
L_20d28c0: r1 = 0x2u;
L_20d28c4: r2 = 0x1u;
L_20d28c8: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d28cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d28d0: r0 = (r0+0x44u);
L_20d28d8: return r0;
}
