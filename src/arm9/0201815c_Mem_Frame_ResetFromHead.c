/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int Mem_Frame_ResetFromHead(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_201815c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 24));
L_2018160: r2 = (r0+0x24u);
L_2018164: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)r1;
L_2018168: r0 = 0x0u;
L_201816c: *(unsigned int *)((unsigned char *)r2 + 8) = (unsigned int)r0;
L_2018170: return r0;
}
