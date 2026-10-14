/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020e6a18(unsigned int);
unsigned int StructMapObject_SomeFn_9(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209bbd8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 12));
L_209bbdc: cmp_a = r0; cmp_b = 0x0u;
L_209bbe8: if ((cmp_a == cmp_b)) { return r0; }
L_209bbec: r0 = func_020e6a18(r0);
L_209bbf8: return r0;
}
