/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructML_SomeFn(unsigned int, unsigned int);
extern unsigned int ModelBlock_SomeTexPltFn_8(unsigned int, unsigned int, unsigned int);
extern unsigned int func_02013588(unsigned int, unsigned int, unsigned int);
unsigned int StructAD00Sh_SomeFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_207b004: r6 = r0;
L_207b008: r5 = r2;
L_207b00c: r0 = StructML_SomeFn(r0,r1);
L_207b010: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_207b014: r0 = 0xdu;
L_207b018: *(unsigned short *)((unsigned char *)r6 + 108) = (unsigned short)r5;
L_207b01c: *(unsigned short *)((unsigned char *)r6 + 110) = (unsigned short)r0;
L_207b020: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r6 + 112));
L_207b024: r0 = r4;
L_207b028: r1 = 0x0u;
L_207b02c: r3 = (r2|0x1u);
L_207b030: r2 = 0x3u;
L_207b034: *(unsigned short *)((unsigned char *)r6 + 112) = (unsigned short)r3;
L_207b038: r0 = ModelBlock_SomeTexPltFn_8(r0,r1,r2);
L_207b03c: r1 = 0x0u;
L_207b040: r0 = r4;
L_207b044: r2 = r1;
L_207b048: r0 = func_02013588(r0,r1,r2);
L_207b050: return r0;
}
