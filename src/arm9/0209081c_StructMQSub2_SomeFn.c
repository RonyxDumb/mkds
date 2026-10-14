/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQSub2_MaybeApplyBulletItem(unsigned int);
extern unsigned int StructMQSub2_SomeFn_0(unsigned int);
unsigned int StructMQSub2_SomeFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2090820: r4 = r0;
L_2090824: r0 = StructMQSub2_MaybeApplyBulletItem(r0);
L_2090828: r0 = r4;
L_209082c: r0 = StructMQSub2_SomeFn_0(r0);
L_2090834: return r0;
}
