/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int Rtc_Time_GetSeconds(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214e258: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_214e25c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214e260: r1 = 0x3cu;
L_214e264: r3 = (r2*r1+r3);
L_214e268: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_214e26c: r0 = (r3*r1+r0);
L_214e270: return r0;
}
