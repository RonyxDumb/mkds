/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_18(unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_17(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208383c: r4 = r0;
L_2083840: r0 = 0x217ae84u;
L_2083844: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2083848: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_208384c: r0 = 0x58u;
L_2083850: r5 = (r1*r0+r2);
L_2083854: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_2083858: cmp_a = r0; cmp_b = 0x0u;
L_208385c: if ((cmp_a == cmp_b)) { goto L_2083874; }
L_2083860: r0 = func_0208b710(r0);
L_2083864: r0 = 0x0u;
L_2083868: *(unsigned int *)((unsigned char *)r5 + 12) = (unsigned int)r0;
L_208386c: r0 = ~(0x0u);
L_2083870: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r0;
L_2083874: r0 = r4;
L_2083878: r1 = 0x1u;
L_208387c: r0 = StructMQRacerEntry_SomeFn_18(r0,r1);
L_2083880: r0 = 0x217ae84u;
L_2083884: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2083888: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_208388c: r0 = 0x58u;
L_2083890: r4 = (r1*r0+r2);
L_2083894: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 32));
L_2083898: cmp_a = r0; cmp_b = 0x0u;
L_208389c: if ((cmp_a == cmp_b)) { goto L_20838ac; }
L_20838a0: r0 = func_0208b710(r0);
L_20838a4: r0 = 0x0u;
L_20838a8: *(unsigned int *)((unsigned char *)r4 + 32) = (unsigned int)r0;
L_20838ac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 36));
L_20838b0: cmp_a = r0; cmp_b = 0x0u;
L_20838bc: if ((cmp_a == cmp_b)) { return r0; }
L_20838c0: r0 = func_0208b710(r0);
L_20838c4: r0 = 0x0u;
L_20838c8: *(unsigned int *)((unsigned char *)r4 + 36) = (unsigned int)r0;
L_20838d4: return r0;
}
