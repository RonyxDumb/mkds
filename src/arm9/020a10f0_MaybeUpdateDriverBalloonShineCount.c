/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020a1b6c(unsigned int);
extern unsigned int func_020a19f8(unsigned int);
unsigned int MaybeUpdateDriverBalloonShineCount(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20a10f8: r2 = 0x70u;
L_20a10fc: r3 = (r0*r2);
L_20a1100: r2 = 0x217b1fcu;
L_20a1104: cmp_a = r1; cmp_b = 0x0u;
L_20a1108: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20a110c: ip = (r2+0x4cu);
L_20a1110: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + (0 + r3)));
L_20a1114: r2 = (r2+r1);
L_20a1118: *(unsigned int *)((unsigned char *)ip + (0 + r3)) = (unsigned int)r2;
L_20a111c: if (((int)cmp_a <= (int)cmp_b)) { goto L_20a1130; }
L_20a1120: r0 = func_020a1b6c(r0);
L_20a112c: return r0;
L_20a1130: cmp_a = r1; cmp_b = 0x0u;
L_20a113c: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20a1140: r0 = func_020a19f8(r0);
L_20a114c: return r0;
}
