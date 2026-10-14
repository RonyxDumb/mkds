/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetActiveExecutionContext(void);
extern unsigned int ExecutionContext_GetHeapHandle(unsigned int);
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
unsigned int func_020bb530(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,lr;
L_20bb538: r0 = GetActiveExecutionContext();
L_20bb53c: r0 = ExecutionContext_GetHeapHandle(r0);
L_20bb540: r1 = 0x2cu;
L_20bb544: r0 = Mem_AllocateHeap(r0,r1);
L_20bb548: r1 = 0x217b3ccu;
L_20bb54c: lr = 0x0u;
L_20bb550: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_20bb554: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)lr;
L_20bb558: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb55c: r2 = 0x13u;
L_20bb560: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)lr;
L_20bb564: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb568: ip = 0x1000u;
L_20bb56c: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r2;
L_20bb570: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb574: r3 = 0xfffff99au;
L_20bb578: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r2;
L_20bb57c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb580: r2 = 0x800u;
L_20bb584: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)lr;
L_20bb588: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb58c: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)lr;
L_20bb590: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb594: *(unsigned int *)((unsigned char *)r0 + 24) = (unsigned int)lr;
L_20bb598: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb59c: *(unsigned int *)((unsigned char *)r0 + 28) = (unsigned int)ip;
L_20bb5a0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb5a4: *(unsigned int *)((unsigned char *)r0 + 32) = (unsigned int)ip;
L_20bb5a8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb5ac: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)r3;
L_20bb5b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20bb5b4: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r2;
L_20bb5c0: return r0;
}
