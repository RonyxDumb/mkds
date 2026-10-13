
unsigned int Mem_GetExpHeapTotalFreeSize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2017748: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 36));
L_201774c: r0 = 0x0u;
L_2017750: cmp_a = r2; cmp_b = 0x0u;
L_2017754: if ((cmp_a == cmp_b)) { return r0; }
L_2017758: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 4));
L_201775c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 12));
L_2017760: r0 = (r0+r1);
L_2017764: cmp_a = r2; cmp_b = 0x0u;
L_2017768: if ((cmp_a != cmp_b)) { goto L_2017758; }
L_201776c: return r0;
}
