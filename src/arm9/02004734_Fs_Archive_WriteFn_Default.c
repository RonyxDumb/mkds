/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_CpuCopy8(unsigned int, unsigned int, unsigned int);
unsigned int Fs_Archive_WriteFn_Default(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_200473c: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 40));
L_2004740: r0 = r1;
L_2004744: r1 = (ip+r2);
L_2004748: r2 = r3;
L_200474c: r0 = Mem_CpuCopy8(r0,r1,r2);
L_2004750: r0 = 0x0u;
L_200475c: return r0;
}
