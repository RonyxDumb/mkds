/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int VecFx32_Subtract(unsigned int, unsigned int, unsigned int);
extern unsigned int Vector3_MaybeNormalize(unsigned int, unsigned int);
unsigned int func_02080adc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2080ae0: r4 = r0;
L_2080ae4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_2080ae8: r2 = (r4+0x8u);
L_2080aec: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r0;
L_2080af0: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r1;
L_2080af4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_2080af8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_2080afc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 24));
L_2080b00: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 24));
L_2080b04: r0 = VecFx32_Subtract(r0,r1,r2);
L_2080b08: r0 = (r4+0x8u);
L_2080b0c: r1 = r0;
L_2080b10: r0 = Vector3_MaybeNormalize(r0,r1);
L_2080b18: return r0;
}
