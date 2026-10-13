/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int GX_VRAMCNT_SetLCDC_(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02149060(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2149064: r4 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_2149068: r2 = 0x0u;
L_214906c: r1 = 0x21802b0u;
L_2149070: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r2;
L_2149074: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_2149078: r0 = r4;
L_214907c: r2 = (r2|r4);
L_2149080: *(unsigned short *)((unsigned char *)r1 + 0) = (unsigned short)r2;
L_2149084: r0 = GX_VRAMCNT_SetLCDC_(r0,r1,r2,r3);
L_2149088: r0 = r4;
L_2149090: return r0;
}
