/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_23(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2080ea0: r4 = r0;
L_2080ea4: r0 = 0x217ae74u;
L_2080ea8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2080eac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2080eb0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + (r1 << 2))));
L_2080eb4: cmp_a = r0; cmp_b = 0x0u;
L_2080ebc: if ((cmp_a == cmp_b)) { return r0; }
L_2080ec0: r0 = func_0208b710(r0,r1,r2,r3);
L_2080ec4: r0 = 0x217ae74u;
L_2080ec8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2080ecc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2080ed0: r2 = 0x0u;
L_2080ed4: *(unsigned int *)((unsigned char *)r0 + (0 + (r1 << 2))) = (unsigned int)r2;
L_2080edc: return r0;
}
