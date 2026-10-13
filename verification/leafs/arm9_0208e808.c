
unsigned int SetSomeAwardModeProperty(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_208e808: r1 = 0x21759c0u;
L_208e80c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_208e810: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 12));
L_208e814: cmp_a = r1; cmp_b = 0x5u;
L_208e818: if ((cmp_a == cmp_b)) { r1 = 0x21663e8u; }
L_208e81c: if ((cmp_a == cmp_b)) { *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0; }
L_208e820: return r0;
}
