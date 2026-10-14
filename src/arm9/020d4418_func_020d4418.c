/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020dff88(unsigned int);
extern unsigned int func_020e435c(unsigned int);
extern unsigned int func_020e3b28(unsigned int);
unsigned int func_020d4418(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d441c: r1 = 0x217b4f0u;
L_20d4420: r4 = (r0+0x30u);
L_20d4424: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20d4428: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 380));
L_20d442c: cmp_a = r0; cmp_b = 0x0u;
L_20d4430: if ((cmp_a == cmp_b)) { goto L_20d443c; }
L_20d4434: r0 = r4;
L_20d4438: r0 = func_020dff88(r0);
L_20d443c: r0 = 0x217b4f0u;
L_20d4440: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d4444: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 384));
L_20d4448: cmp_a = r0; cmp_b = 0x0u;
L_20d444c: if ((cmp_a == cmp_b)) { goto L_20d4458; }
L_20d4450: r0 = r4;
L_20d4454: r0 = func_020e435c(r0);
L_20d4458: r0 = 0x217b4f0u;
L_20d445c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d4460: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 388));
L_20d4464: cmp_a = r0; cmp_b = 0x0u;
L_20d446c: if ((cmp_a == cmp_b)) { return r0; }
L_20d4470: r0 = r4;
L_20d4474: r0 = func_020e3b28(r0);
L_20d447c: return r0;
}
