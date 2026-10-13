/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210d7dc(unsigned int, unsigned int, unsigned int);
unsigned int func_0210d614(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210d61c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 11));
L_210d620: cmp_a = r2; cmp_b = 0x0u;
L_210d624: if ((cmp_a == cmp_b)) { r2 = 0x217d07cu; }
L_210d628: cmp_a = r0; cmp_b = 0xffu;
L_210d634: if ((cmp_a == cmp_b)) { return r0; }
L_210d638: r3 = 0x216cb28u;
L_210d63c: r0 = r1;
L_210d640: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_210d644: r0 = func_0210d7dc(r0,r1,r2);
L_210d650: return r0;
}
