/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0204f240(unsigned int, unsigned int);
extern unsigned int func_020594d4(void);
unsigned int func_0203b1c8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203b1d0: r1 = 0x27ffc40u;
L_203b1d4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_203b1d8: cmp_a = r1; cmp_b = 0x2u;
L_203b1dc: if ((cmp_a != cmp_b)) { goto L_203b1e8; }
L_203b1e0: r1 = 0x1u;
L_203b1e4: r0 = func_0204f240(r0,r1);
L_203b1e8: r0 = func_020594d4();
L_203b1f4: return r0;
}
