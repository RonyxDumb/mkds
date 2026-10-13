
unsigned int Os_FindReadyThread(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_200df3c: r0 = 0x216ff5cu;
L_200df40: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_200df44: goto L_200df4c;
L_200df48: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 104));
L_200df4c: cmp_a = r0; cmp_b = 0x0u;
L_200df50: if ((cmp_a == cmp_b)) { return r0; }
L_200df54: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 100));
L_200df58: cmp_a = r1; cmp_b = 0x1u;
L_200df5c: if ((cmp_a != cmp_b)) { goto L_200df48; }
L_200df60: return r0;
}
