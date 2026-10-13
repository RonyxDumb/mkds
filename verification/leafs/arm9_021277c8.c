
unsigned int func_021277c8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21277c8: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_21277ca: r1 = 0x217d3f4u;
L_21277cc: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_21277ce: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 4));
L_21277d0: cmp_a = r1; cmp_b = 0x1u;
L_21277d2: if ((cmp_a != cmp_b)) { goto L_21277dc; }
L_21277d4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 40));
L_21277d6: cmp_a = r1; cmp_b = 0x0u;
L_21277d8: if ((cmp_a != cmp_b)) { goto L_21277dc; }
L_21277da: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_21277dc: return r0;
}
