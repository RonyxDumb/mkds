/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020815dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20815dc: r2 = 0x217ae84u;
L_20815e0: r1 = 0x58u;
L_20815e4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20815e8: r3 = (r0*r1+r2);
L_20815ec: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 44));
L_20815f0: cmp_a = r2; cmp_b = 0x0u;
L_20815f4: if ((cmp_a == cmp_b)) { return r0; }
L_20815f8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 36));
L_20815fc: r0 = 0x0u;
L_2081600: r1 = (r1&~(0x1u));
L_2081604: r1 = (r1|0x1u);
L_2081608: *(unsigned int *)((unsigned char *)r2 + 36) = (unsigned int)r1;
L_208160c: *(unsigned int *)((unsigned char *)r3 + 44) = (unsigned int)r0;
L_2081610: return r0;
}
