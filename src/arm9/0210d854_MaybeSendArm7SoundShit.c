/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212f730(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int MaybeSendArm7SoundShit(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210d858: r1 = 0x217d06cu;
L_210d85c: r4 = r0;
L_210d860: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_210d864: r2 = r4;
L_210d868: r0 = (r0+0x1fu);
L_210d86c: r0 = (r0&~(0x1fu));
L_210d870: r1 = 0x1000u;
L_210d874: r0 = func_0212f730(r0,r1,r2,r3);
L_210d878: r0 = 0x216cb24u;
L_210d87c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r4;
L_210d884: return r0;
}
