/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetCurrentSceneId(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int Struct5624_SetXflag2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2043548: r4 = r0;
L_204354c: r0 = GetCurrentSceneId(r0,r1,r2,r3);
L_2043550: cmp_a = r0; cmp_b = 0x2u;
L_2043554: if ((cmp_a != cmp_b)) { goto L_204357c; }
L_2043558: cmp_a = r4; cmp_b = 0x0u;
L_204355c: if ((cmp_a == cmp_b)) { goto L_204357c; }
L_2043560: r0 = 0x2175624u;
L_2043564: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2043568: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 4));
L_204356c: r0 = (r0|0x2u);
L_2043570: *(unsigned short *)((unsigned char *)r1 + 4) = (unsigned short)r0;
L_2043578: return r0;
L_204357c: r0 = 0x2175624u;
L_2043580: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2043584: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 4));
L_2043588: r0 = (r0&~(0x2u));
L_204358c: *(unsigned short *)((unsigned char *)r1 + 4) = (unsigned short)r0;
L_2043594: return r0;
}
