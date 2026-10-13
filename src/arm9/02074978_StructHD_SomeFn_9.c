/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructHD_SomeFn_11(unsigned int, unsigned int);
extern unsigned int StructHD_SomeFn_8(unsigned int);
extern unsigned int StructHD_SomeFn_10(unsigned int);
unsigned int StructHD_SomeFn_9(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_207497c: r4 = r0;
L_2074980: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 536));
L_2074984: r1 = (unsigned int)(*(short *)((unsigned char *)r1 + 66));
L_2074988: r0 = StructHD_SomeFn_11(r0,r1);
L_207498c: r0 = r4;
L_2074990: r0 = StructHD_SomeFn_8(r0);
L_2074994: r0 = r4;
L_2074998: r0 = StructHD_SomeFn_10(r0);
L_20749a0: return r0;
}
