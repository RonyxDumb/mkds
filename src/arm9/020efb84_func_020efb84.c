/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f0ea0(unsigned int, unsigned int);
extern unsigned int func_020efd1c(unsigned int, unsigned int);
unsigned int func_020efb84(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,r4,r5;
L_20efb8c: r2 = 0x27e00ccu;
L_20efb90: r4 = r1;
L_20efb94: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20efb98: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_20efb9c: r2 = 0x44u;
L_20efba0: r5 = r0;
L_20efba4: r0 = (r3*r2+ip);
L_20efba8: r0 = func_020f0ea0(r0,r1);
L_20efbac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_20efbb0: r1 = r4;
L_20efbb4: r0 = func_020efd1c(r0,r1);
L_20efbb8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20efbbc: r0 = (r0&~(0x1000u));
L_20efbc0: *(unsigned int *)((unsigned char *)r4 + 116) = (unsigned int)r0;
L_20efbcc: return r0;
}
