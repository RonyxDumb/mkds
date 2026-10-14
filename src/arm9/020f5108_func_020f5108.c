/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ff1b8(unsigned int, unsigned int);
extern unsigned int func_020fecdc(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ff1a0(unsigned int, unsigned int);
extern unsigned int func_020fe8ac(unsigned int);
unsigned int func_020f5108(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20f510c: r6 = r1; cmp_a = r6; cmp_b = 0;
L_20f5110: r4 = r0;
L_20f5114: r5 = r2;
L_20f5118: if ((cmp_a == cmp_b)) { goto L_20f5130; }
L_20f511c: cmp_a = r5; cmp_b = 0x0u;
L_20f5120: if ((cmp_a == cmp_b)) { goto L_20f5130; }
L_20f5124: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 304));
L_20f5128: r1 = (r6+0x60u);
L_20f512c: r0 = func_020ff1b8(r0,r1);
L_20f5130: r0 = r4;
L_20f5134: r1 = r6;
L_20f5138: r2 = r5;
L_20f513c: r0 = func_020fecdc(r0,r1,r2);
L_20f5140: r4 = r0;
L_20f5144: cmp_a = r6; cmp_b = 0x0u;
L_20f5148: if ((cmp_a == cmp_b)) { goto L_20f5160; }
L_20f514c: cmp_a = r5; cmp_b = 0x0u;
L_20f5150: if ((cmp_a != cmp_b)) { goto L_20f5160; }
L_20f5154: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 96));
L_20f5158: r1 = (r6+0x130u);
L_20f515c: r0 = func_020ff1a0(r0,r1);
L_20f5160: cmp_a = r6; cmp_b = 0x0u;
L_20f5164: if ((cmp_a == cmp_b)) { goto L_20f5180; }
L_20f5168: cmp_a = r5; cmp_b = 0x0u;
L_20f516c: if ((cmp_a == cmp_b)) { goto L_20f5180; }
L_20f5170: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 68));
L_20f5174: r0 = func_020fe8ac(r0);
L_20f517c: return r0;
L_20f5180: r0 = r4;
L_20f5188: return r0;
}
