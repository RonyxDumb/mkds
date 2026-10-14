/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int VecFx32_AddScale1(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_01ffc064(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,lr,r4;
L_1ffc068: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 464));
L_1ffc06c: r4 = r0;
L_1ffc070: lr = r1;
L_1ffc074: r0 = (ip+r2);
L_1ffc078: r1 = (r3+0x12cu);
L_1ffc07c: r2 = lr;
L_1ffc080: r3 = r4;
L_1ffc084: r0 = VecFx32_AddScale1(r0,r1,r2,r3);
L_1ffc08c: return r0;
}
