/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02088d34(unsigned int);
extern unsigned int func_0207e668(unsigned int);
extern unsigned int func_02089494(unsigned int);
extern unsigned int func_02088e44(unsigned int);
extern unsigned int func_02088a0c(unsigned int);
unsigned int func_020896e0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20896e4: r4 = r0;
L_20896e8: r0 = func_02088d34(r0);
L_20896ec: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 196));
L_20896f0: cmp_a = r0; cmp_b = 0x0u;
L_20896f4: if ((cmp_a != cmp_b)) { goto L_2089700; }
L_20896f8: r0 = r4;
L_20896fc: r0 = func_0207e668(r0);
L_2089700: r0 = r4;
L_2089704: r0 = func_02089494(r0);
L_2089708: r0 = 0x21759c0u;
L_208970c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2089710: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 24));
L_2089714: cmp_a = r0; cmp_b = 0x0u;
L_2089718: if ((cmp_a != cmp_b)) { goto L_208972c; }
L_208971c: r0 = r4;
L_2089720: r0 = func_02088e44(r0);
L_2089728: return r0;
L_208972c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 208));
L_2089730: cmp_a = r0; cmp_b = 0x0u;
L_2089734: if ((cmp_a == cmp_b)) { goto L_2089740; }
L_2089738: r0 = r4;
L_208973c: r0 = func_02088e44(r0);
L_2089740: r0 = r4;
L_2089744: r0 = func_02088a0c(r0);
L_208974c: return r0;
}
