
unsigned int GetMQRacerVector444(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2063b50: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 288));
L_2063b54: r3 = (r0+0x120u);
L_2063b58: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_2063b5c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 4));
L_2063b60: *(unsigned int *)((unsigned char *)r1 + 4) = (unsigned int)r0;
L_2063b64: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 8));
L_2063b68: *(unsigned int *)((unsigned char *)r1 + 8) = (unsigned int)r0;
L_2063b6c: return r0;
}
