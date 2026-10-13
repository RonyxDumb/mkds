
unsigned int func_0202728c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_202728c: r1 = 0x27ffc40u;
L_202728e: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_2027290: cmp_a = r1; cmp_b = 0x2u;
L_2027292: if ((cmp_a == cmp_b)) { goto L_20272b0; }
L_2027294: r1 = 0x2174e14u;
L_2027296: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2027298: r1 = 0x128u;
L_202729a: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_202729c: cmp_a = r1; cmp_b = 0x0u;
L_202729e: if ((cmp_a != cmp_b)) { goto L_20272b0; }
L_20272a0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 24));
L_20272a2: r1 = (r1+0x44u); cmp_a = r1; cmp_b = 0;
L_20272a4: *(unsigned short *)((unsigned char *)r1 + 0) = (unsigned short)r0;
L_20272a6: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 24));
L_20272a8: r0 = 0x44u; cmp_a = r0; cmp_b = 0;
L_20272aa: r0 = (unsigned int)(*(short *)((unsigned char *)r1 + (0 + r0)));
L_20272ac: r1 = (r1+0x84u); cmp_a = r1; cmp_b = 0;
L_20272ae: *(unsigned short *)((unsigned char *)r1 + 0) = (unsigned short)r0;
L_20272b0: return r0;
}
