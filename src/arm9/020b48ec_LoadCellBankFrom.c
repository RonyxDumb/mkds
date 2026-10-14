/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int CellBank_InitializeLoad(unsigned int);
unsigned int LoadCellBankFrom(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20b48f0: r4 = r0;
L_20b48f4: cmp_a = r1; cmp_b = 0x0u;
L_20b48fc: if ((cmp_a == cmp_b)) { return r0; }
L_20b4900: r0 = r1;
L_20b4904: r1 = 0x4345424bu;
L_20b4908: r0 = Common_FindBlockByMagic(r0,r1);
L_20b490c: cmp_a = r0; cmp_b = 0x0u;
L_20b4914: if ((cmp_a == cmp_b)) { return r0; }
L_20b4918: r0 = (r0+0x8u);
L_20b491c: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20b4920: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b4924: r0 = CellBank_InitializeLoad(r0);
L_20b492c: return r0;
}
