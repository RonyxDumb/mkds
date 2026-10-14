/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0209bf8c(void);
unsigned int func_020a6d40(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a6d48: r0 = 0x21759c0u;
L_20a6d4c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20a6d50: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20a6d54: cmp_a = r0; cmp_b = 0x2u;
L_20a6d58: if ((cmp_a != cmp_b)) { goto L_20a6d78; }
L_20a6d5c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 24));
L_20a6d60: cmp_a = r0; cmp_b = 0x1u;
L_20a6d64: if ((cmp_a != cmp_b)) { goto L_20a6d78; }
L_20a6d68: r0 = func_0209bf8c();
L_20a6d74: return r0;
L_20a6d78: r0 = 0x0u;
L_20a6d84: return r0;
}
