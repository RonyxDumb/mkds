
unsigned int Os_InitializeIrqThreadQueue(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_200cd04: r0 = 0x27e0000u;
L_200cd08: r1 = 0x0u;
L_200cd0c: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_200cd10: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_200cd14: return r0;
}
