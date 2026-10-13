
unsigned int StructE8_SomeFnHandle6(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c5df0: r0 = 0x217b3f4u;
L_20c5df4: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c5df8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 4));
L_20c5dfc: r1 = (r2+0x1u);
L_20c5e00: *(unsigned int *)((unsigned char *)r3 + 4) = (unsigned int)r1;
L_20c5e04: cmp_a = r2; cmp_b = 0x3cu;
L_20c5e08: if (((int)cmp_a < (int)cmp_b)) { return r0; }
L_20c5e0c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c5e10: r3 = 0x20c5dd8u;
L_20c5e14: r1 = 0x0u;
L_20c5e18: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r3;
L_20c5e1c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c5e20: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_20c5e24: return r0;
}
