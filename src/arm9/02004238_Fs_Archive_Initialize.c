/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_CpuFill8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int Fs_Archive_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_200423c: r1 = 0x0u;
L_2004240: r2 = 0x5cu;
L_2004244: r4 = r0;
L_2004248: r0 = Mem_CpuFill8(r0,r1,r2,r3);
L_200424c: r1 = 0x0u;
L_2004250: *(unsigned int *)((unsigned char *)r4 + 16) = (unsigned int)r1;
L_2004254: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 16));
L_2004258: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r0;
L_200425c: *(unsigned int *)((unsigned char *)r4 + 24) = (unsigned int)r1;
L_2004260: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 24));
L_2004264: *(unsigned int *)((unsigned char *)r4 + 20) = (unsigned int)r0;
L_200426c: return r0;
}
