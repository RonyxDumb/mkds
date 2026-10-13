/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int StateDualHandler_Create(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020ec884(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20ec888: r4 = r0;
L_20ec88c: r1 = 0x216c414u;
L_20ec890: r3 = r4;
L_20ec894: r0 = (r4+0x80u);
L_20ec898: r2 = 0x3u;
L_20ec89c: r0 = StateDualHandler_Create(r0,r1,r2,r3);
L_20ec8a0: r0 = 0x0u;
L_20ec8a4: *(unsigned short *)((unsigned char *)r4 + 144) = (unsigned short)r0;
L_20ec8a8: r0 = 0x1u;
L_20ec8ac: *(unsigned short *)((unsigned char *)r4 + 146) = (unsigned short)r0;
L_20ec8b4: return r0;
}
