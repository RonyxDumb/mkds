/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ff9048(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ea5b0(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ea670(unsigned int, unsigned int);
extern unsigned int func_020ea7cc(unsigned int, unsigned int);
extern unsigned int func_020ea618(unsigned int, unsigned int);
unsigned int DrawObject2DBB(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_209ba90: r4 = r2;
L_209ba94: r5 = r1;
L_209ba98: r0 = 0x1bu;
L_209ba9c: r2 = 0x3u;
L_209baa0: r0 = func_01ff9048(r0,r1,r2);
L_209baa4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_209baa8: cmp_a = r0; cmp_b = 0x0u;
L_209baac: if ((cmp_a == cmp_b)) { goto L_209babc; }
L_209bab0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bab4: r2 = (r4+0x4u);
L_209bab8: r0 = func_020ea5b0(r0,r1,r2);
L_209babc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 16));
L_209bac0: cmp_a = r0; cmp_b = 0x0u;
L_209bac4: if ((cmp_a != cmp_b)) { goto L_209badc; }
L_209bac8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209bacc: cmp_a = r1; cmp_b = 0x0u;
L_209bad8: if ((cmp_a == cmp_b)) { return r0; }
L_209badc: cmp_a = r0; cmp_b = 0x0u;
L_209bae0: if ((cmp_a == cmp_b)) { goto L_209bb04; }
L_209bae4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 36));
L_209bae8: cmp_a = r1; cmp_b = 0x0u;
L_209baec: if ((cmp_a == cmp_b)) { goto L_209bafc; }
L_209baf0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209baf4: r0 = func_020ea670(r0,r1);
L_209baf8: goto L_209bb04;
L_209bafc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bb00: r0 = func_020ea7cc(r0,r1);
L_209bb04: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209bb08: cmp_a = r0; cmp_b = 0x0u;
L_209bb14: if ((cmp_a == cmp_b)) { return r0; }
L_209bb18: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bb1c: r0 = func_020ea618(r0,r1);
L_209bb28: return r0;
}
