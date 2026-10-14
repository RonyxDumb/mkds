/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ffcb58(unsigned int);
extern unsigned int func_020636f8(unsigned int);
extern unsigned int func_020641f0(unsigned int);
unsigned int DriverContext_Fn4_NetNot3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2063884: r4 = r0;
L_2063888: r0 = func_01ffcb58(r0);
L_206388c: r0 = 0x217aa14u;
L_2063890: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2063894: r0 = (r0+0x700u);
L_2063898: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 92));
L_206389c: r0 = (r0&0x2u); cmp_a = r0; cmp_b = 0;
L_20638a0: if ((cmp_a == cmp_b)) { goto L_20638ac; }
L_20638a4: r0 = r4;
L_20638a8: r0 = func_020636f8(r0);
L_20638ac: r0 = r4;
L_20638b0: r0 = func_020641f0(r0);
L_20638b8: return r0;
}
