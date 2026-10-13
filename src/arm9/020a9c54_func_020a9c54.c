/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020e53ac(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020a9c54(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20a9c5c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 300));
L_20a9c60: cmp_a = r0; cmp_b = 0x0u;
L_20a9c6c: if ((cmp_a == cmp_b)) { return r0; }
L_20a9c70: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 120));
L_20a9c74: r0 = 0xf4240u;
L_20a9c78: ip = (ip&~(0xc000001fu));
L_20a9c7c: cmp_a = ip; cmp_b = r0;
L_20a9c88: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20a9c8c: r0 = (r1+0x100u);
L_20a9c90: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 24));
L_20a9c94: cmp_a = r0; cmp_b = 0x0u;
L_20a9ca0: if ((cmp_a == cmp_b)) { return r0; }
L_20a9ca4: cmp_a = r0; cmp_b = 0x1cu;
L_20a9cb0: if ((cmp_a > cmp_b)) { return r0; }
L_20a9cb4: r0 = (r1+0xe8u);
L_20a9cb8: r1 = 0x0u;
L_20a9cbc: r0 = func_020e53ac(r0,r1,r2,r3);
L_20a9cc8: return r0;
}
