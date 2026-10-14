/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetCharacterKartModel(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2079bcc: r2 = 0x217ad00u;
L_2079bd0: r1 = 0xb4u;
L_2079bd4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2079bd8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2079bdc: r1 = (r0*r1+r2);
L_2079be0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 20));
L_2079be4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_2079be8: return r0;
}
