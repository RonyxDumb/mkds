/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int NFTR_CharacterMap_GetTileIndexForCharacter(unsigned int, unsigned int);
unsigned int NFTR_GetTileIndexForCharacter(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2022cec: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2022cf0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 16));
L_2022cf4: cmp_a = r0; cmp_b = 0x0u;
L_2022cf8: if ((cmp_a == cmp_b)) { goto L_2022d30; }
L_2022cfc: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_2022d00: cmp_a = r2; cmp_b = r1;
L_2022d04: if ((cmp_a > cmp_b)) { goto L_2022d24; }
L_2022d08: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_2022d0c: cmp_a = r1; cmp_b = r2;
L_2022d10: if ((cmp_a > cmp_b)) { goto L_2022d24; }
L_2022d14: r0 = NFTR_CharacterMap_GetTileIndexForCharacter(r0,r1);
L_2022d20: return r0;
L_2022d24: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_2022d28: cmp_a = r0; cmp_b = 0x0u;
L_2022d2c: if ((cmp_a != cmp_b)) { goto L_2022cfc; }
L_2022d30: r0 = 0xffffu;
L_2022d3c: return r0;
}
