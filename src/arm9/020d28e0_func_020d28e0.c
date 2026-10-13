/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_45(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210cf9c(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_47(unsigned int, unsigned int, unsigned int);
unsigned int func_020d28e0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d28e4: r4 = r0;
L_20d28e8: r0 = GetActiveExecutionContext();
L_20d28ec: r0 = ExecutionContext_GetHeapHandle(r0);
L_20d28f0: r1 = 0x44u;
L_20d28f4: r0 = Mem_AllocateHeap(r0,r1);
L_20d28f8: *(unsigned int *)((unsigned char *)r4 + 148) = (unsigned int)r0;
L_20d28fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d2900: r2 = (r4+0x4u);
L_20d2904: r1 = 0x2u;
L_20d2908: r0 = StructMQRacerEntry_SomeFn_45(r0,r1,r2);
L_20d290c: r0 = 0x217ca6cu;
L_20d2910: r1 = 0x0u;
L_20d2914: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 104));
L_20d2918: *(unsigned int *)((unsigned char *)r4 + 112) = (unsigned int)r0;
L_20d291c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d2920: r0 = func_0210cf9c(r0,r1);
L_20d2924: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d2928: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d292c: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d2934: if ((cmp_a == cmp_b)) { return r0; }
L_20d2938: r1 = 0x2u;
L_20d293c: r2 = 0x1u;
L_20d2940: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d2948: return r0;
}
