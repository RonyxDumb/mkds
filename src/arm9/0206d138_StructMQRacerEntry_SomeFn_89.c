/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_5(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_7(unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_89(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_206d13c: r4 = r0;
L_206d140: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_206d144: r1 = (r1&0x840u); cmp_a = r1; cmp_b = 0;
L_206d148: if ((cmp_a != cmp_b)) { goto L_206d158; }
L_206d14c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 972));
L_206d150: r2 = 0x8u;
L_206d154: r0 = StructMQRacerEntry_SomeFn_5(r0,r1,r2);
L_206d158: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_206d15c: r0 = (r1&0x10u); cmp_a = r0; cmp_b = 0;
L_206d164: if ((cmp_a == cmp_b)) { return r0; }
L_206d168: r0 = (r1&0x30000u); cmp_a = r0; cmp_b = 0;
L_206d170: if ((cmp_a != cmp_b)) { return r0; }
L_206d174: r0 = r4;
L_206d178: r1 = 0x2u;
L_206d17c: r2 = 0x0u;
L_206d180: r0 = StructMQRacerEntry_SomeFn_7(r0,r1,r2);
L_206d188: return r0;
}
