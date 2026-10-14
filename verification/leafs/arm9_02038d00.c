
unsigned int DisplayEngineConfig_SetBg2Config2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b;
L_2038d00: *(unsigned short *)((unsigned char *)r0 + 36) = (unsigned short)r1;
L_2038d04: *(unsigned short *)((unsigned char *)r0 + 38) = (unsigned short)r2;
L_2038d08: r1 = a4;
L_2038d0c: *(unsigned short *)((unsigned char *)r0 + 40) = (unsigned short)r3;
L_2038d10: r2 = a5;
L_2038d14: *(unsigned short *)((unsigned char *)r0 + 42) = (unsigned short)r1;
L_2038d18: r1 = a6;
L_2038d1c: *(unsigned short *)((unsigned char *)r0 + 44) = (unsigned short)r2;
L_2038d20: *(unsigned short *)((unsigned char *)r0 + 46) = (unsigned short)r1;
L_2038d24: return r0;
}
