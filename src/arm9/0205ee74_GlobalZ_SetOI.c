/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_CpuCopy8(unsigned int, unsigned int, unsigned int);
unsigned int GlobalZ_SetOI(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_205ee7c: r2 = 0x217aa08u;
L_205ee80: ip = r0;
L_205ee84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_205ee88: r2 = 0x24u;
L_205ee8c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 32));
L_205ee90: r0 = r1;
L_205ee94: r1 = (r3+0x4u);
L_205ee98: r1 = (ip*r2+r1);
L_205ee9c: r0 = Mem_CpuCopy8(r0,r1,r2);
L_205eea8: return r0;
}
