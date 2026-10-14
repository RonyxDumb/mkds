/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int StructML_SetSomeFields(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4)
{
unsigned int cmp_a,cmp_b;
L_20109c4: *(unsigned int *)((unsigned char *)r0 + 32) = (unsigned int)r1;
L_20109c8: r1 = a4;
L_20109cc: *(unsigned char *)((unsigned char *)r0 + 36) = (unsigned char)r3;
L_20109d0: *(unsigned char *)((unsigned char *)r0 + 37) = (unsigned char)r1;
L_20109d4: return r0;
}
