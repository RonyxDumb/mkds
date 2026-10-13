/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_55(unsigned int);
extern unsigned int func_020f4754(unsigned int, unsigned int);
extern unsigned int func_020fe958(unsigned int);
unsigned int func_020f6264(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f6268: r4 = r1;
L_20f626c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_20f6270: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 508));
L_20f6274: r0 = StructMQRacerEntry_SomeFn_55(r0);
L_20f6278: r0 = r4;
L_20f627c: r1 = 0x1u;
L_20f6280: r0 = func_020f4754(r0,r1);
L_20f6284: r0 = 0x21759c0u;
L_20f6288: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20f628c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20f6290: cmp_a = r0; cmp_b = 0x5u;
L_20f6298: if ((cmp_a != cmp_b)) { return r0; }
L_20f629c: r0 = 0x4u;
L_20f62a0: r0 = func_020fe958(r0);
L_20f62a8: return r0;
}
