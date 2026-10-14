/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int InitializeBalloonHardware(void);
unsigned int CreateGlobal59C4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_204710c: r1 = 0x40u;
L_2047110: r0 = Mem_AllocateHeap(r0,r1);
L_2047114: r1 = 0x21759c4u;
L_2047118: r2 = 0x0u;
L_204711c: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2047120: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 48));
L_2047124: r3 = (r3&~(0x1u));
L_2047128: *(unsigned int *)((unsigned char *)r0 + 48) = (unsigned int)r3;
L_204712c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2047130: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 48));
L_2047134: r0 = (r0&~(0x2u));
L_2047138: *(unsigned int *)((unsigned char *)r3 + 48) = (unsigned int)r0;
L_204713c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2047140: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 48));
L_2047144: r0 = (r0&~(0x4u));
L_2047148: *(unsigned int *)((unsigned char *)r3 + 48) = (unsigned int)r0;
L_204714c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2047150: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 48));
L_2047154: r0 = (r0&~(0x8u));
L_2047158: *(unsigned int *)((unsigned char *)r3 + 48) = (unsigned int)r0;
L_204715c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2047160: *(unsigned int *)((unsigned char *)r0 + 60) = (unsigned int)r2;
L_2047164: r0 = InitializeBalloonHardware();
L_2047170: return r0;
}
