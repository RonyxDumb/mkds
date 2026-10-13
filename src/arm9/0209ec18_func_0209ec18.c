/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
unsigned int func_0209ec18(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209ec20: r1 = 0x216745cu;
L_209ec24: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209ec28: r1 = 0x217b194u;
L_209ec2c: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_209ec38: return r0;
}
