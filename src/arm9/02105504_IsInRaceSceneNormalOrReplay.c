/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int GetCurrentSceneId(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int IsInRaceSceneNormalOrReplay(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2105508: r4 = 0x0u;
L_210550c: r0 = GetCurrentSceneId(r0,r1,r2,r3);
L_2105510: cmp_a = r0; cmp_b = 0x2u;
L_2105514: if ((cmp_a != cmp_b)) { goto L_2105540; }
L_2105518: r0 = 0x21759c0u;
L_210551c: r1 = 0x1u;
L_2105520: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2105524: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_2105528: cmp_a = r0; cmp_b = 0x0u;
L_210552c: if ((cmp_a == cmp_b)) { goto L_2105538; }
L_2105530: cmp_a = r0; cmp_b = 0x2u;
L_2105534: if ((cmp_a != cmp_b)) { r1 = r4; }
L_2105538: cmp_a = r1; cmp_b = 0x0u;
L_210553c: if ((cmp_a != cmp_b)) { r4 = 0x1u; }
L_2105540: r0 = r4;
L_2105548: return r0;
}
