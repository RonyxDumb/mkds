
unsigned int func_020edad8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20edad8: r1 = 0xau;
L_20edadc: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)r1;
L_20edae0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 368));
L_20edae4: cmp_a = r1; cmp_b = 0x0u;
L_20edae8: if ((cmp_a != cmp_b)) { r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12)); }
L_20edaec: if ((cmp_a != cmp_b)) { r2 = 0x13u; }
L_20edaf0: if ((cmp_a != cmp_b)) { *(unsigned int *)((unsigned char *)r1 + 20) = (unsigned int)r2; }
L_20edaf4: if ((cmp_a != cmp_b)) { r1 = 0x0u; }
L_20edaf8: if ((cmp_a != cmp_b)) { *(unsigned int *)((unsigned char *)r0 + 368) = (unsigned int)r1; }
L_20edafc: return r0;
}
