/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_45(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210cf9c(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_47(unsigned int, unsigned int, unsigned int);
unsigned int func_020d27fc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d2800: r4 = r0;
L_20d2804: r0 = GetActiveExecutionContext();
L_20d2808: r0 = ExecutionContext_GetHeapHandle(r0);
L_20d280c: r1 = 0x44u;
L_20d2810: r0 = Mem_AllocateHeap(r0,r1);
L_20d2814: *(unsigned int *)((unsigned char *)r4 + 148) = (unsigned int)r0;
L_20d2818: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d281c: r2 = (r4+0x4u);
L_20d2820: r1 = 0x3u;
L_20d2824: r0 = StructMQRacerEntry_SomeFn_45(r0,r1,r2);
L_20d2828: r0 = 0x217ca6cu;
L_20d282c: r1 = 0x0u;
L_20d2830: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 140));
L_20d2834: *(unsigned int *)((unsigned char *)r4 + 112) = (unsigned int)r0;
L_20d2838: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d283c: r0 = func_0210cf9c(r0,r1);
L_20d2840: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20d2844: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d2848: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d2850: if ((cmp_a == cmp_b)) { return r0; }
L_20d2854: r1 = 0x2u;
L_20d2858: r2 = 0x1u;
L_20d285c: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d2864: return r0;
}
