/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int NFTR_LoadImpl(unsigned int, unsigned int);
unsigned int NFTR_Load(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20b4794: cmp_a = r1; cmp_b = 0x0u;
L_20b47a0: if ((cmp_a == cmp_b)) { return r0; }
L_20b47a4: r0 = NFTR_LoadImpl(r0,r1);
L_20b47b0: return r0;
}
