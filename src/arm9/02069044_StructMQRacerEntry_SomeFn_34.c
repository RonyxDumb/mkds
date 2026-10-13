/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_35(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_34(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2069048: r4 = r0;
L_206904c: r1 = 0x1u;
L_2069050: r0 = StructMQRacerEntry_SomeFn_35(r0,r1,r2,r3);
L_2069054: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_2069058: r0 = (r0|0x800000u);
L_206905c: *(unsigned int *)((unsigned char *)r4 + 124) = (unsigned int)r0;
L_2069064: return r0;
}
