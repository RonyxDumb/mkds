/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f1150(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f5cc4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f5cc8: r4 = r0;
L_20f5ccc: r3 = (unsigned int)(*(short *)((unsigned char *)r4 + 218));
L_20f5cd0: r2 = ~(0x0u);
L_20f5cd4: cmp_a = r3; cmp_b = r2;
L_20f5cdc: if ((cmp_a == cmp_b)) { return r0; }
L_20f5ce0: r0 = func_020f1150(r0,r1,r2,r3);
L_20f5ce4: r0 = (r4+0x200u);
L_20f5ce8: r1 = 0x4u;
L_20f5cec: *(unsigned short *)((unsigned char *)r0 + 76) = (unsigned short)r1;
L_20f5cf0: r1 = 0x1u;
L_20f5cf4: *(unsigned short *)((unsigned char *)r0 + 78) = (unsigned short)r1;
L_20f5cfc: return r0;
}
