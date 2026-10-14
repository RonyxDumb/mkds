/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetCupForCourse(unsigned int);
extern unsigned int func_0203b96c(unsigned int);
unsigned int func_020600b4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20600bc: r0 = GetCupForCourse(r0);
L_20600c0: r0 = func_0203b96c(r0);
L_20600cc: return r0;
}
