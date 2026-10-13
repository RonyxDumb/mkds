/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Animation_SetAt(unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int ExplosionKind_MissionSplash_CreateFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_208dc54: r1 = 0x3d9au;
L_208dc58: r4 = r0;
L_208dc5c: *(unsigned int *)((unsigned char *)r4 + 156) = (unsigned int)r1;
L_208dc60: *(unsigned int *)((unsigned char *)r4 + 160) = (unsigned int)r1;
L_208dc64: *(unsigned int *)((unsigned char *)r4 + 164) = (unsigned int)r1;
L_208dc68: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 144));
L_208dc6c: r1 = 0x0u;
L_208dc70: r0 = Animation_SetAt(r0,r1);
L_208dc74: r0 = 0x20u;
L_208dc78: *(unsigned int *)((unsigned char *)r4 + 172) = (unsigned int)r0;
L_208dc7c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_208dc80: cmp_a = r0; cmp_b = 0x0u;
L_208dc84: if ((cmp_a == cmp_b)) { goto L_208dc90; }
L_208dc88: r1 = 0x0u;
L_208dc8c: r0 = Animation_SetAt(r0,r1);
L_208dc90: r0 = 0x424u;
L_208dc94: r1 = (r4+0x74u);
L_208dc98: r0 = func_0208b7bc(r0,r1);
L_208dc9c: r0 = 0x422u;
L_208dca0: r1 = (r4+0x74u);
L_208dca4: r0 = func_0208b7bc(r0,r1);
L_208dcac: return r0;
}
