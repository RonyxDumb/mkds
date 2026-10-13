
unsigned int func_020dd1f4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20dd1f4: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_20dd1f8: cmp_a = r1; cmp_b = 0x1u;
L_20dd1fc: if ((cmp_a != cmp_b)) { goto L_20dd228; }
L_20dd200: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 142));
L_20dd204: cmp_a = r1; cmp_b = 0x2u;
L_20dd208: if ((cmp_a != cmp_b)) { goto L_20dd218; }
L_20dd20c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_20dd210: cmp_a = r1; cmp_b = 0x4000u;
L_20dd214: if (((int)cmp_a >= (int)cmp_b)) { goto L_20dd228; }
L_20dd218: r1 = 0x2u;
L_20dd21c: *(unsigned short *)((unsigned char *)r0 + 144) = (unsigned short)r1;
L_20dd220: r1 = 0x1u;
L_20dd224: *(unsigned short *)((unsigned char *)r0 + 146) = (unsigned short)r1;
L_20dd228: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r3 + 0));
L_20dd22c: return r0;
}
