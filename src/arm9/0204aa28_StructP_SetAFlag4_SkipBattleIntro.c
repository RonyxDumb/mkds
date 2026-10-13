/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int StructP_SetAFlag4_SkipBattleIntro(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_204aa28: r1 = 0x27ffc40u;
L_204aa2c: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_204aa30: cmp_a = r1; cmp_b = 0x2u;
L_204aa34: if ((cmp_a == cmp_b)) { return r0; }
L_204aa38: r1 = 0x21759d0u;
L_204aa3c: r0 = (r0&0x1u);
L_204aa40: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_204aa44: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 28));
L_204aa48: r1 = (r1&~(0x4u));
L_204aa4c: r0 = (r1|(r0 << 2));
L_204aa50: *(unsigned int *)((unsigned char *)r2 + 28) = (unsigned int)r0;
L_204aa54: return r0;
}
