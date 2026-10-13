
unsigned int func_021277ac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21277ac: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_21277ae: r1 = 0x217d3f4u;
L_21277b0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_21277b2: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 4));
L_21277b4: cmp_a = r1; cmp_b = 0x0u;
L_21277b6: if ((cmp_a != cmp_b)) { goto L_21277c0; }
L_21277b8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 36));
L_21277ba: cmp_a = r1; cmp_b = 0x0u;
L_21277bc: if ((cmp_a != cmp_b)) { goto L_21277c0; }
L_21277be: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_21277c0: return r0;
}
