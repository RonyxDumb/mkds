/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Animation_SetAt(unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int ExplosionKind_Bombcore_CreateFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208dd74: r5 = r0;
L_208dd78: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 144));
L_208dd7c: r4 = r1;
L_208dd80: r1 = 0x0u;
L_208dd84: r0 = Animation_SetAt(r0,r1);
L_208dd88: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 148));
L_208dd8c: r1 = 0x0u;
L_208dd90: r0 = Animation_SetAt(r0,r1);
L_208dd94: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 152));
L_208dd98: r1 = 0x0u;
L_208dd9c: r0 = Animation_SetAt(r0,r1);
L_208dda0: r0 = 0xab8u;
L_208dda4: cmp_a = r4; cmp_b = 0x0u;
L_208dda8: *(unsigned int *)((unsigned char *)r5 + 156) = (unsigned int)r0;
L_208ddac: *(unsigned int *)((unsigned char *)r5 + 160) = (unsigned int)r0;
L_208ddb4: *(unsigned int *)((unsigned char *)r5 + 164) = (unsigned int)r0;
L_208ddbc: if ((cmp_a == cmp_b)) { return r0; }
L_208ddc0: r1 = (r5+0x74u);
L_208ddc4: r0 = 0x22u;
L_208ddc8: r0 = func_0208b7bc(r0,r1);
L_208ddcc: r1 = (r5+0x74u);
L_208ddd0: r0 = 0x1u;
L_208ddd4: r0 = func_0208b7bc(r0,r1);
L_208ddd8: r1 = (r5+0x74u);
L_208dddc: r0 = 0x2u;
L_208dde0: r0 = func_0208b7bc(r0,r1);
L_208ddec: return r0;
}
