/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Model_CreateFromNsbmd(unsigned int, unsigned int);
extern unsigned int ModelBlock_SomeTexPltFn_8(unsigned int, unsigned int, unsigned int);
extern unsigned int func_02013588(unsigned int, unsigned int, unsigned int);
unsigned int StructAD00Sh_SomeFn_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_207afac: r6 = r0;
L_207afb0: r5 = r2;
L_207afb4: r0 = Model_CreateFromNsbmd(r0,r1);
L_207afb8: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_207afbc: r0 = 0xdu;
L_207afc0: *(unsigned short *)((unsigned char *)r6 + 108) = (unsigned short)r5;
L_207afc4: *(unsigned short *)((unsigned char *)r6 + 110) = (unsigned short)r0;
L_207afc8: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r6 + 112));
L_207afcc: r0 = r4;
L_207afd0: r1 = 0x0u;
L_207afd4: r3 = (r2|0x1u);
L_207afd8: r2 = 0x3u;
L_207afdc: *(unsigned short *)((unsigned char *)r6 + 112) = (unsigned short)r3;
L_207afe0: r0 = ModelBlock_SomeTexPltFn_8(r0,r1,r2);
L_207afe4: r1 = 0x0u;
L_207afe8: r0 = r4;
L_207afec: r2 = r1;
L_207aff0: r0 = func_02013588(r0,r1,r2);
L_207aff4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_207affc: return r0;
}
