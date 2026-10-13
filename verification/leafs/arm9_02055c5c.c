
unsigned int func_02055c5c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2055c5c: r0 = 0x217aa04u;
L_2055c60: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2055c64: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2055c68: cmp_a = r0; cmp_b = 0x2u;
L_2055c6c: if ((cmp_a == cmp_b)) { r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 8)); }
L_2055c70: if ((cmp_a == cmp_b)) { r0 = (r0&~(0x2u)); }
L_2055c74: if ((cmp_a == cmp_b)) { *(unsigned short *)((unsigned char *)r1 + 8) = (unsigned short)r0; }
L_2055c78: return r0;
}
