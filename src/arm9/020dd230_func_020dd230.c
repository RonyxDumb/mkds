/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d26f8(unsigned int, unsigned int);
unsigned int func_020dd230(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20dd234: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_20dd238: r4 = r3;
L_20dd23c: cmp_a = r2; cmp_b = 0x1u;
L_20dd240: if ((cmp_a != cmp_b)) { goto L_20dd270; }
L_20dd244: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 142));
L_20dd248: cmp_a = r2; cmp_b = 0x2u;
L_20dd24c: if ((cmp_a != cmp_b)) { goto L_20dd25c; }
L_20dd250: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_20dd254: cmp_a = r2; cmp_b = 0x4000u;
L_20dd258: if (((int)cmp_a >= (int)cmp_b)) { goto L_20dd270; }
L_20dd25c: r2 = 0x2u;
L_20dd260: *(unsigned short *)((unsigned char *)r0 + 144) = (unsigned short)r2;
L_20dd264: r2 = 0x1u;
L_20dd268: *(unsigned short *)((unsigned char *)r0 + 146) = (unsigned short)r2;
L_20dd26c: r0 = func_020d26f8(r0,r1);
L_20dd270: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20dd278: return r0;
}
