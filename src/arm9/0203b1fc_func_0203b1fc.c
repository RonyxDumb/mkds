/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0204f240(unsigned int, unsigned int);
extern unsigned int func_020445f8(void);
unsigned int func_0203b1fc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203b204: r1 = 0x27ffc40u;
L_203b208: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_203b20c: cmp_a = r1; cmp_b = 0x2u;
L_203b210: if ((cmp_a != cmp_b)) { goto L_203b21c; }
L_203b214: r1 = 0x1u;
L_203b218: r0 = func_0204f240(r0,r1);
L_203b21c: r0 = func_020445f8();
L_203b228: return r0;
}
