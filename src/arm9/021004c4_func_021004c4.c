/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020fecdc(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020fe8ac(unsigned int);
unsigned int func_021004c4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_21004cc: r5 = r1;
L_21004d0: r4 = r2;
L_21004d4: r0 = func_020fecdc(r0,r1,r2);
L_21004d8: cmp_a = r5; cmp_b = 0x0u;
L_21004e4: if ((cmp_a == cmp_b)) { return r0; }
L_21004e8: cmp_a = r4; cmp_b = 0x0u;
L_21004f4: if ((cmp_a == cmp_b)) { return r0; }
L_21004f8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 68));
L_21004fc: r0 = func_020fe8ac(r0);
L_2100508: return r0;
}
