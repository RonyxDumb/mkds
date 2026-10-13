
unsigned int DisplayEngineConfig_SetBg0Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b;
L_2038d58: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_2038d5c: r1 = a4;
L_2038d60: *(unsigned short *)((unsigned char *)r0 + 4) = (unsigned short)r3;
L_2038d64: *(unsigned short *)((unsigned char *)r0 + 6) = (unsigned short)r1;
L_2038d68: r1 = a5;
L_2038d6c: *(unsigned short *)((unsigned char *)r0 + 2) = (unsigned short)r2;
L_2038d70: r2 = a6;
L_2038d74: *(unsigned short *)((unsigned char *)r0 + 8) = (unsigned short)r1;
L_2038d78: r1 = a7;
L_2038d7c: *(unsigned short *)((unsigned char *)r0 + 10) = (unsigned short)r2;
L_2038d80: *(unsigned short *)((unsigned char *)r0 + 12) = (unsigned short)r1;
L_2038d84: return r0;
}
