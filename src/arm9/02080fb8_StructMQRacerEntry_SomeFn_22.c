/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_22(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2080fbc: r4 = r0;
L_2080fc0: r0 = 0x217ae94u;
L_2080fc4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2080fc8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2080fcc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + (r1 << 2))));
L_2080fd0: cmp_a = r0; cmp_b = 0x0u;
L_2080fd8: if ((cmp_a == cmp_b)) { return r0; }
L_2080fdc: r0 = func_0208b710(r0,r1,r2,r3);
L_2080fe0: r0 = 0x217ae94u;
L_2080fe4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2080fe8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2080fec: r2 = 0x0u;
L_2080ff0: *(unsigned int *)((unsigned char *)r0 + (0 + (r1 << 2))) = (unsigned int)r2;
L_2080ff8: return r0;
}
