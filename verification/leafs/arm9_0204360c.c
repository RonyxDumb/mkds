
unsigned int func_0204360c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_204360c: r2 = 0x5cu;
L_2043610: r3 = (r0*r2);
L_2043614: r0 = 0x2175664u;
L_2043618: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + r3)));
L_204361c: cmp_a = r0; cmp_b = 0x3u;
L_2043620: if ((cmp_a == cmp_b)) { goto L_204362c; }
L_2043624: cmp_a = r0; cmp_b = 0x7u;
L_2043628: if ((cmp_a != cmp_b)) { return r0; }
L_204362c: r2 = 0x2175668u;
L_2043630: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r2 + (0 + r3)));
L_2043634: r0 = (r0|r1);
L_2043638: *(unsigned short *)((unsigned char *)r2 + (0 + r3)) = (unsigned short)r0;
L_204363c: return r0;
}
