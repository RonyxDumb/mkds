/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int G2d_Sprite_CreateImpl(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int G2d_Sprite_CreateFromTiles(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_16,stack_4,stack_8;
L_2023410: lr = a4;
L_2023414: ip = 0x2023bccu;
L_2023418: stack_0 = lr;
L_202341c: lr = 0x2023944u;
L_2023420: stack_4 = ip;
L_2023424: ip = 0x2023764u;
L_2023428: stack_8 = lr;
L_202342c: stack_12 = ip;
L_2023430: stack_16 = r2;
L_2023434: r0 = G2d_Sprite_CreateImpl(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12,stack_16);
L_2023440: return r0;
}
