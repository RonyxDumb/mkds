/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_75(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_70(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210a540: r4 = r0;
L_210a544: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 1160));
L_210a548: r1 = 0xffffu;
L_210a54c: cmp_a = r2; cmp_b = r1;
L_210a554: if ((cmp_a == cmp_b)) { return r0; }
L_210a558: r1 = 0x0u;
L_210a55c: r3 = r1;
L_210a560: r0 = StructMQRacerEntry_SomeFn_75(r0,r1,r2,r3);
L_210a564: r0 = 0xffffu;
L_210a568: *(unsigned int *)((unsigned char *)r4 + 1160) = (unsigned int)r0;
L_210a570: return r0;
}
