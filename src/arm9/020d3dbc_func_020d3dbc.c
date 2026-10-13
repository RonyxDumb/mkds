/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020d3dbc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d3dbc: r0 = 0x217b4e4u;
L_20d3dc0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d3dc4: cmp_a = r0; cmp_b = 0x0u;
L_20d3dc8: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 44)); }
L_20d3dcc: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20d3dd0: return r0;
}
