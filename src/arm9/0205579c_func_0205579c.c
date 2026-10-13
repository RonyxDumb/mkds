/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0204e1a8(unsigned int);
extern unsigned int func_02055808(unsigned int);
unsigned int func_0205579c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20557a4: cmp_a = r0; cmp_b = 0x0u;
L_20557a8: if ((cmp_a == cmp_b)) { goto L_20557d4; }
L_20557ac: cmp_a = r1; cmp_b = 0x0u;
L_20557b0: if ((cmp_a == cmp_b)) { goto L_20557c4; }
L_20557b4: r0 = func_0204e1a8(r0);
L_20557c0: return r0;
L_20557c4: r0 = func_02055808(r0);
L_20557d0: return r0;
L_20557d4: r1 = 0x27ffc40u;
L_20557d8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_20557dc: cmp_a = r1; cmp_b = 0x2u;
L_20557e0: if ((cmp_a != cmp_b)) { goto L_20557f4; }
L_20557e4: r0 = func_0204e1a8(r0);
L_20557f0: return r0;
L_20557f4: r0 = func_02055808(r0);
L_2055800: return r0;
}
