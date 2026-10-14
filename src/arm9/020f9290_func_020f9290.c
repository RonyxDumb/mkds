/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int VecFx32_CrossProduct_0(unsigned int, unsigned int);
extern unsigned int func_020f6fc4(unsigned int, unsigned int);
unsigned int func_020f9290(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f9294: r4 = r0;
L_20f9298: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f929c: r0 = (r0&0x2000000u); cmp_a = r0; cmp_b = 0;
L_20f92a0: if ((cmp_a == cmp_b)) { goto L_20f92dc; }
L_20f92a4: r0 = r1;
L_20f92a8: r1 = (r4+0x108u);
L_20f92ac: r0 = VecFx32_CrossProduct_0(r0,r1);
L_20f92b0: cmp_a = r0; cmp_b = 0x0u;
L_20f92b4: if (((int)cmp_a >= (int)cmp_b)) { goto L_20f92dc; }
L_20f92b8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f92bc: r0 = (r0&0x8u); cmp_a = r0; cmp_b = 0;
L_20f92c0: if ((cmp_a != cmp_b)) { goto L_20f92dc; }
L_20f92c4: r0 = r4;
L_20f92c8: r1 = 0x1u;
L_20f92cc: r0 = func_020f6fc4(r0,r1);
L_20f92d0: r0 = 0x1u;
L_20f92d8: return r0;
L_20f92dc: r0 = 0x0u;
L_20f92e4: return r0;
}
