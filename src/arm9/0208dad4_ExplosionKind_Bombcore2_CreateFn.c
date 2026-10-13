/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Animation_SetAt(unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int ExplosionKind_Bombcore2_CreateFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208dadc: r5 = r0;
L_208dae0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 144));
L_208dae4: r4 = r1;
L_208dae8: r1 = 0x0u;
L_208daec: r0 = Animation_SetAt(r0,r1);
L_208daf0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 148));
L_208daf4: r1 = 0x0u;
L_208daf8: r0 = Animation_SetAt(r0,r1);
L_208dafc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 152));
L_208db00: r1 = 0x0u;
L_208db04: r0 = Animation_SetAt(r0,r1);
L_208db08: r0 = 0x1000u;
L_208db0c: *(unsigned int *)((unsigned char *)r5 + 156) = (unsigned int)r0;
L_208db10: *(unsigned int *)((unsigned char *)r5 + 160) = (unsigned int)r0;
L_208db14: cmp_a = r4; cmp_b = 0x0u;
L_208db1c: *(unsigned int *)((unsigned char *)r5 + 164) = (unsigned int)r0;
L_208db24: if ((cmp_a == cmp_b)) { return r0; }
L_208db28: r1 = (r5+0x74u);
L_208db2c: r0 = 0x8u;
L_208db30: r0 = func_0208b7bc(r0,r1);
L_208db34: r1 = (r5+0x74u);
L_208db38: r0 = 0x9u;
L_208db3c: r0 = func_0208b7bc(r0,r1);
L_208db40: r1 = (r5+0x74u);
L_208db44: r0 = 0xau;
L_208db48: r0 = func_0208b7bc(r0,r1);
L_208db54: return r0;
}
