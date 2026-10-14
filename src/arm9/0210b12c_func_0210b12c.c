/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_6(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0210b12c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_210b134: r3 = 0x217c814u;
L_210b138: r2 = (r1+0xc1u);
L_210b13c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_210b140: cmp_a = r1; cmp_b = 0x78u;
L_210b14c: if ((cmp_a < cmp_b)) { return r0; }
L_210b150: r1 = 0x0u;
L_210b154: r3 = 0x7fu;
L_210b158: stack_0 = r1;
L_210b15c: r0 = StructMQRacerEntry_SomeFn_6(r0,r1,r2,r3,stack_0);
L_210b160: cmp_a = r0; cmp_b = 0x0u;
L_210b16c: if ((cmp_a == cmp_b)) { return r0; }
L_210b170: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 25));
L_210b174: r1 = (r1|0x20u);
L_210b178: *(unsigned char *)((unsigned char *)r0 + 25) = (unsigned char)r1;
L_210b17c: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 25));
L_210b180: r1 = (r1|0x40u);
L_210b184: *(unsigned char *)((unsigned char *)r0 + 25) = (unsigned char)r1;
L_210b190: return r0;
}
