/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020533a0(void);
extern unsigned int func_02053fa8(void);
unsigned int func_02051364(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205136c: r1 = 0x217aa00u;
L_2051370: r2 = 0x0u;
L_2051374: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2051378: *(unsigned int *)((unsigned char *)r1 + 16) = (unsigned int)r2;
L_205137c: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_2051380: cmp_a = r0; cmp_b = 0x0u;
L_2051384: if ((cmp_a == cmp_b)) { goto L_2051398; }
L_2051388: r0 = func_020533a0();
L_2051394: return r0;
L_2051398: r0 = func_02053fa8();
L_20513a4: return r0;
}
