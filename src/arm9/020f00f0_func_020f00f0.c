/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f81c0(unsigned int);
unsigned int func_020f00f0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f00f8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 508));
L_20f00fc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 124));
L_20f0100: r1 = (r1&0x400u); cmp_a = r1; cmp_b = 0;
L_20f010c: if ((cmp_a != cmp_b)) { return r0; }
L_20f0110: r1 = 0x21759c0u;
L_20f0114: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20f0118: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20f011c: cmp_a = r1; cmp_b = 0x5u;
L_20f0128: if ((cmp_a == cmp_b)) { return r0; }
L_20f012c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20f0130: cmp_a = r1; cmp_b = 0x0u;
L_20f013c: if ((cmp_a == cmp_b)) { return r0; }
L_20f0140: r0 = func_020f81c0(r0);
L_20f014c: return r0;
}
