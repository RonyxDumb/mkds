/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_021470f8(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02147914(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4)
{
unsigned int cmp_a,cmp_b,ip,r4,r5,stack_0;
L_214791c: ip = a4;
L_2147920: r5 = r0;
L_2147924: stack_0 = ip;
L_2147928: r4 = r1;
L_214792c: r0 = func_021470f8(r0,r1,r2,r3,stack_0);
L_2147930: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 36));
L_2147934: *(unsigned int *)((unsigned char *)r4 + 36) = (unsigned int)r0;
L_2147938: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 40));
L_214793c: *(unsigned int *)((unsigned char *)r4 + 40) = (unsigned int)r0;
L_2147940: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 44));
L_2147944: *(unsigned int *)((unsigned char *)r4 + 44) = (unsigned int)r0;
L_2147950: return r0;
}
