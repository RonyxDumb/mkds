
unsigned int func_0203b680(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203b680: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 6));
L_203b684: r2 = (r2-0x1u);
L_203b688: r1 = (r1-0x1u);
L_203b68c: r2 = (r1*r3+r2);
L_203b690: r0 = (r0+r2);
L_203b694: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 8));
L_203b698: return r0;
}
