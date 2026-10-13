
unsigned int Util_PrintContext_ApppendChar(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_200db20: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_200db24: cmp_a = r2; cmp_b = 0x0u;
L_200db28: if ((cmp_a != cmp_b)) { r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4)); }
L_200db2c: if ((cmp_a != cmp_b)) { *(unsigned char *)((unsigned char *)r2 + 0) = (unsigned char)r1; }
L_200db30: if ((cmp_a != cmp_b)) { r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0)); }
L_200db34: if ((cmp_a != cmp_b)) { r1 = (r1-0x1u); }
L_200db38: if ((cmp_a != cmp_b)) { *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1; }
L_200db3c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_200db40: r1 = (r1+0x1u);
L_200db44: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_200db48: return r0;
}
