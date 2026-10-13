/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int DisplayEngineConfig_SetBg3Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b;
L_2038cd8: *(unsigned short *)((unsigned char *)r0 + 52) = (unsigned short)r1;
L_2038cdc: *(unsigned short *)((unsigned char *)r0 + 54) = (unsigned short)r2;
L_2038ce0: r1 = a4;
L_2038ce4: *(unsigned short *)((unsigned char *)r0 + 56) = (unsigned short)r3;
L_2038ce8: r2 = a5;
L_2038cec: *(unsigned short *)((unsigned char *)r0 + 58) = (unsigned short)r1;
L_2038cf0: r1 = a6;
L_2038cf4: *(unsigned short *)((unsigned char *)r0 + 60) = (unsigned short)r2;
L_2038cf8: *(unsigned short *)((unsigned char *)r0 + 62) = (unsigned short)r1;
L_2038cfc: return r0;
}
