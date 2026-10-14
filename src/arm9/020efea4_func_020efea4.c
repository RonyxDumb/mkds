/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020edad8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020efea4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20efeac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 508));
L_20efeb0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 668));
L_20efeb4: r1 = (r1-0x2u);
L_20efeb8: cmp_a = r1; cmp_b = 0x1u;
L_20efec4: if ((cmp_a <= cmp_b)) { return r0; }
L_20efec8: r1 = 0x21759c0u;
L_20efecc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20efed0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20efed4: cmp_a = r1; cmp_b = 0x5u;
L_20efee0: if ((cmp_a == cmp_b)) { return r0; }
L_20efee4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 88));
L_20efee8: cmp_a = r1; cmp_b = 0xfu;
L_20efef4: if ((cmp_a == cmp_b)) { return r0; }
L_20efef8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 124));
L_20efefc: cmp_a = r1; cmp_b = 0x0u;
L_20eff08: if ((cmp_a != cmp_b)) { return r0; }
L_20eff0c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 96));
L_20eff10: cmp_a = r1; cmp_b = 0x1u;
L_20eff14: if ((cmp_a == cmp_b)) { goto L_20eff28; }
L_20eff18: cmp_a = r1; cmp_b = 0x2u;
L_20eff24: if ((cmp_a != cmp_b)) { return r0; }
L_20eff28: r0 = (r0+0x58u);
L_20eff2c: r0 = func_020edad8(r0,r1,r2,r3);
L_20eff38: return r0;
}
