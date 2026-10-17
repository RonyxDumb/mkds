/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207e564(unsigned int);
extern unsigned int func_0207d7e4(unsigned int, unsigned int);
unsigned int func_0208bde0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_208bd24: r4 = r0;
L_208bd28: r0 = func_0207e564(r0);
L_208bd2c: r1 = r4;
L_208bd30: r0 = (r4+0xe8u);
L_208bd34: r0 = func_0207d7e4(r0,r1);
L_208bd3c: return r0;
}
