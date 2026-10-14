/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212c9a4(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0212ef00(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212ef08: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 288));
L_212ef0c: cmp_a = r1; cmp_b = 0x0u;
L_212ef18: if ((cmp_a == cmp_b)) { return r0; }
L_212ef1c: r1 = (r1-0x1u);
L_212ef20: *(unsigned int *)((unsigned char *)r0 + 288) = (unsigned int)r1;
L_212ef24: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 288));
L_212ef28: cmp_a = r1; cmp_b = 0x0u;
L_212ef34: if ((cmp_a != cmp_b)) { return r0; }
L_212ef38: r0 = func_0212c9a4(r0,r1,r2,r3);
L_212ef44: return r0;
}
