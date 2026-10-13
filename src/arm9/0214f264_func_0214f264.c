/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0214f2a8(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0214eed8(void);
unsigned int func_0214f264(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214f26c: r1 = 0x214eef0u;
L_214f270: r2 = 0x0u;
L_214f274: r0 = func_0214f2a8(r0,r1,r2);
L_214f278: r1 = 0x2180414u;
L_214f27c: cmp_a = r0; cmp_b = 0x0u;
L_214f280: *(unsigned int *)((unsigned char *)r1 + 12) = (unsigned int)r0;
L_214f284: if ((cmp_a != cmp_b)) { goto L_214f28c; }
L_214f288: r0 = func_0214eed8();
L_214f28c: r0 = 0x2180414u;
L_214f290: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_214f29c: return r0;
}
