/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d233c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_021053e4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_21053e8: r4 = r0;
L_21053ec: r0 = func_020d233c(r0,r1,r2,r3);
L_21053f0: r3 = 0x1fu;
L_21053f4: *(unsigned short *)((unsigned char *)r4 + 102) = (unsigned short)r3;
L_21053f8: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_21053fc: r1 = 0x0u;
L_2105400: r0 = 0x80u;
L_2105404: r2 = (r2&~(0x2u));
L_2105408: *(unsigned short *)((unsigned char *)r4 + 2) = (unsigned short)r2;
L_210540c: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_2105410: r2 = (r2&~(0x8u));
L_2105414: *(unsigned short *)((unsigned char *)r4 + 2) = (unsigned short)r2;
L_2105418: *(unsigned short *)((unsigned char *)r4 + 102) = (unsigned short)r3;
L_210541c: *(unsigned int *)((unsigned char *)r4 + 28) = (unsigned int)r1;
L_2105420: *(unsigned int *)((unsigned char *)r4 + 32) = (unsigned int)r1;
L_2105424: *(unsigned int *)((unsigned char *)r4 + 36) = (unsigned int)r1;
L_2105428: *(unsigned short *)((unsigned char *)r4 + 160) = (unsigned short)r1;
L_210542c: *(unsigned short *)((unsigned char *)r4 + 162) = (unsigned short)r1;
L_2105430: *(unsigned short *)((unsigned char *)r4 + 164) = (unsigned short)r0;
L_2105438: return r0;
}
