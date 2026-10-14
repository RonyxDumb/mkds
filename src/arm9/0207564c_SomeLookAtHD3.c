/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructHD_SomeFn_0(unsigned int);
extern unsigned int StructHD_SomeLookAt(unsigned int);
unsigned int SomeLookAtHD3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2075654: r0 = 0x217acb8u;
L_2075658: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_207565c: r0 = StructHD_SomeFn_0(r0);
L_2075660: r0 = 0x217acb8u;
L_2075664: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2075668: r0 = StructHD_SomeLookAt(r0);
L_207566c: r1 = 0x217acb8u;
L_2075670: r0 = 0x217acb4u;
L_2075674: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2075678: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_207567c: r0 = (r1+0x30u);
L_2075688: return r0;
}
