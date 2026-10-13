
unsigned int func_020ab5bc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ab5bc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_20ab5be: r1 = (r1+0x1u); cmp_a = r1; cmp_b = 0;
L_20ab5c0: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_20ab5c2: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_20ab5c4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20ab5c6: cmp_a = r2; cmp_b = r1;
L_20ab5c8: if ((cmp_a == cmp_b)) { goto L_20ab5d0; }
L_20ab5ca: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 4));
L_20ab5cc: cmp_a = r2; cmp_b = r1;
L_20ab5ce: if ((cmp_a != cmp_b)) { goto L_20ab5d4; }
L_20ab5d0: r1 = 0x1u; cmp_a = r1; cmp_b = 0;
L_20ab5d2: *(unsigned short *)((unsigned char *)r0 + 6) = (unsigned short)r1;
L_20ab5d4: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_20ab5d6: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 4));
L_20ab5d8: cmp_a = r2; cmp_b = r1;
L_20ab5da: if ((cmp_a <= cmp_b)) { goto L_20ab5e2; }
L_20ab5dc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20ab5de: r1 = (r1+0x1u); cmp_a = r1; cmp_b = 0;
L_20ab5e0: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_20ab5e2: return r0;
}
