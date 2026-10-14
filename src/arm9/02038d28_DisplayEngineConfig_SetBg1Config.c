/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int DisplayEngineConfig_SetBg1Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b;
L_2038d28: *(unsigned short *)((unsigned char *)r0 + 16) = (unsigned short)r1;
L_2038d2c: r1 = a4;
L_2038d30: *(unsigned short *)((unsigned char *)r0 + 20) = (unsigned short)r3;
L_2038d34: *(unsigned short *)((unsigned char *)r0 + 22) = (unsigned short)r1;
L_2038d38: r1 = a5;
L_2038d3c: *(unsigned short *)((unsigned char *)r0 + 18) = (unsigned short)r2;
L_2038d40: r2 = a6;
L_2038d44: *(unsigned short *)((unsigned char *)r0 + 24) = (unsigned short)r1;
L_2038d48: r1 = a7;
L_2038d4c: *(unsigned short *)((unsigned char *)r0 + 26) = (unsigned short)r2;
L_2038d50: *(unsigned short *)((unsigned char *)r0 + 28) = (unsigned short)r1;
L_2038d54: return r0;
}
