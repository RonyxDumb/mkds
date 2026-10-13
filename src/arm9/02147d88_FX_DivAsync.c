/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int FX_DivAsync(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_2147d88: r2 = 0x4000280u;
L_2147d8c: ip = 0x1u;
L_2147d90: r3 = 0x4000290u;
L_2147d94: *(unsigned short *)((unsigned char *)r2 + 0) = (unsigned short)ip;
L_2147d98: ip = 0x0u;
L_2147d9c: *(unsigned int *)((unsigned char *)r3 + 0) = (unsigned int)ip;
L_2147da0: r2 = 0x4000298u;
L_2147da4: *(unsigned int *)((unsigned char *)r3 + 4) = (unsigned int)r0;
L_2147da8: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r1;
L_2147dac: *(unsigned int *)((unsigned char *)r2 + 4) = (unsigned int)ip;
L_2147db0: return r0;
}
