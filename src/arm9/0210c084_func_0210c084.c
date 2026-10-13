/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212c6f0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0210c084(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210c088: r4 = r0;
L_210c08c: r0 = func_0212c6f0(r0,r1,r2,r3);
L_210c090: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 25));
L_210c094: r0 = (r0&~(0x4u));
L_210c098: *(unsigned char *)((unsigned char *)r4 + 25) = (unsigned char)r0;
L_210c09c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 25));
L_210c0a0: r0 = (r0&~(0x8u));
L_210c0a4: *(unsigned char *)((unsigned char *)r4 + 25) = (unsigned char)r0;
L_210c0a8: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 25));
L_210c0ac: r0 = (r0&~(0x2u));
L_210c0b0: *(unsigned char *)((unsigned char *)r4 + 25) = (unsigned char)r0;
L_210c0b8: return r0;
}
