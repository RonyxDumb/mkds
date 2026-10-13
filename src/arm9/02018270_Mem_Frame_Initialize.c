/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_InitializeHeapHead(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int Mem_Frame_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,stack_0;
L_2018278: r5 = r0;
L_201827c: r3 = r1;
L_2018280: r4 = (r5+0x24u);
L_2018284: stack_0 = r2;
L_2018288: r1 = 0x46524d48u;
L_201828c: r2 = (r4+0xcu);
L_2018290: r0 = Mem_InitializeHeapHead(r0,r1,r2,r3,stack_0);
L_2018294: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 24));
L_2018298: r1 = 0x0u;
L_201829c: *(unsigned int *)((unsigned char *)r5 + 36) = (unsigned int)r0;
L_20182a0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 28));
L_20182a4: r0 = r5;
L_20182a8: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r2;
L_20182ac: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r1;
L_20182b8: return r0;
}
