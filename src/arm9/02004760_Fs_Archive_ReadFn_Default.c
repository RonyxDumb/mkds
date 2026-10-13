/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_CpuCopy8(unsigned int, unsigned int, unsigned int);
unsigned int Fs_Archive_ReadFn_Default(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2004768: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 40));
L_200476c: r0 = (r0+r2);
L_2004770: r2 = r3;
L_2004774: r0 = Mem_CpuCopy8(r0,r1,r2);
L_2004778: r0 = 0x0u;
L_2004784: return r0;
}
