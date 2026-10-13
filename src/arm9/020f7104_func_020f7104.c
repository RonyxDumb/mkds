/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f7184(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020fe7a0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f7104(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20f710c: r5 = r0;
L_20f7110: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 116));
L_20f7114: r4 = r1;
L_20f7118: r1 = (r2&0x8000000u); cmp_a = r1; cmp_b = 0;
L_20f711c: if ((cmp_a != cmp_b)) { goto L_20f7138; }
L_20f7120: r1 = 0x0u;
L_20f7124: r2 = r1;
L_20f7128: r0 = func_020f7184(r0,r1,r2);
L_20f7134: return r0;
L_20f7138: r1 = 0x0u;
L_20f713c: r2 = r1;
L_20f7140: r0 = func_020f7184(r0,r1,r2);
L_20f7144: cmp_a = r0; cmp_b = 0x0u;
L_20f7150: if ((cmp_a != cmp_b)) { return r0; }
L_20f7154: cmp_a = r4; cmp_b = 0x0u;
L_20f7160: if ((cmp_a == cmp_b)) { return r0; }
L_20f7164: r3 = (unsigned int)(*(short *)((unsigned char *)r5 + 78));
L_20f7168: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 68));
L_20f716c: r1 = 0x0u;
L_20f7170: r2 = 0x8u;
L_20f7174: r0 = func_020fe7a0(r0,r1,r2,r3);
L_20f7180: return r0;
}
