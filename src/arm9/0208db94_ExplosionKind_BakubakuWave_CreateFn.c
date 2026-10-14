/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Animation_SetAt(unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int ExplosionKind_BakubakuWave_CreateFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208db9c: r5 = r0;
L_208dba0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 144));
L_208dba4: r4 = r1;
L_208dba8: r1 = 0x0u;
L_208dbac: r0 = Animation_SetAt(r0,r1);
L_208dbb0: r0 = 0x5800u;
L_208dbb4: *(unsigned int *)((unsigned char *)r5 + 156) = (unsigned int)r0;
L_208dbb8: *(unsigned int *)((unsigned char *)r5 + 160) = (unsigned int)r0;
L_208dbbc: *(unsigned int *)((unsigned char *)r5 + 164) = (unsigned int)r0;
L_208dbc0: r0 = 0x27u;
L_208dbc4: *(unsigned int *)((unsigned char *)r5 + 172) = (unsigned int)r0;
L_208dbc8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 148));
L_208dbcc: r1 = 0x0u;
L_208dbd0: r0 = Animation_SetAt(r0,r1);
L_208dbd4: cmp_a = r4; cmp_b = 0x0u;
L_208dbe0: if ((cmp_a == cmp_b)) { return r0; }
L_208dbe4: r1 = (r5+0x74u);
L_208dbe8: r0 = 0x40u;
L_208dbec: r0 = func_0208b7bc(r0,r1);
L_208dbf0: r1 = (r5+0x74u);
L_208dbf4: r0 = 0x41u;
L_208dbf8: r0 = func_0208b7bc(r0,r1);
L_208dc04: return r0;
}
