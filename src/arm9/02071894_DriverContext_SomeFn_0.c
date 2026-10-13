/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_5(unsigned int, unsigned int, unsigned int);
unsigned int DriverContext_SomeFn_0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_207189c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 72));
L_20718a0: r1 = (r1&0x840u); cmp_a = r1; cmp_b = 0;
L_20718ac: if ((cmp_a != cmp_b)) { return r0; }
L_20718b0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 972));
L_20718b4: r2 = 0x7u;
L_20718b8: r0 = StructMQRacerEntry_SomeFn_5(r0,r1,r2);
L_20718c4: return r0;
}
