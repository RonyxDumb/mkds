
unsigned int DisplayEngineConfig_SetBg2Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5)
{
unsigned int cmp_a,cmp_b,ip;
L_2038cb0: ip = 0x5u;
L_2038cb4: *(unsigned int *)((unsigned char *)r0 + 32) = (unsigned int)ip;
L_2038cb8: *(unsigned short *)((unsigned char *)r0 + 36) = (unsigned short)r1;
L_2038cbc: *(unsigned short *)((unsigned char *)r0 + 38) = (unsigned short)r2;
L_2038cc0: r2 = a4;
L_2038cc4: *(unsigned short *)((unsigned char *)r0 + 40) = (unsigned short)r3;
L_2038cc8: r1 = a5;
L_2038ccc: *(unsigned short *)((unsigned char *)r0 + 42) = (unsigned short)r2;
L_2038cd0: *(unsigned short *)((unsigned char *)r0 + 44) = (unsigned short)r1;
L_2038cd4: return r0;
}
