/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0204f240(unsigned int, unsigned int);
extern unsigned int func_0205949c(void);
unsigned int func_0203b194(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203b19c: r1 = 0x27ffc40u;
L_203b1a0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_203b1a4: cmp_a = r1; cmp_b = 0x2u;
L_203b1a8: if ((cmp_a != cmp_b)) { goto L_203b1b4; }
L_203b1ac: r1 = 0x1u;
L_203b1b0: r0 = func_0204f240(r0,r1);
L_203b1b4: r0 = func_0205949c();
L_203b1c0: return r0;
}
