/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int Fs_Archive_LoadFromFatFnt(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b;
L_2004018: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r1;
L_200401c: *(unsigned int *)((unsigned char *)r0 + 48) = (unsigned int)r3;
L_2004020: *(unsigned int *)((unsigned char *)r0 + 60) = (unsigned int)r2;
L_2004024: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 60));
L_2004028: r2 = a5;
L_200402c: *(unsigned int *)((unsigned char *)r0 + 44) = (unsigned int)r1;
L_2004030: *(unsigned int *)((unsigned char *)r0 + 56) = (unsigned int)r2;
L_2004034: r1 = a4;
L_2004038: r2 = a6;
L_200403c: *(unsigned int *)((unsigned char *)r0 + 64) = (unsigned int)r1;
L_2004040: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 64));
L_2004044: cmp_a = r2; cmp_b = 0x0u;
L_2004048: *(unsigned int *)((unsigned char *)r0 + 52) = (unsigned int)r1;
L_200404c: if ((cmp_a == cmp_b)) { r2 = 0x2004760u; }
L_2004050: r1 = a7;
L_2004054: *(unsigned int *)((unsigned char *)r0 + 72) = (unsigned int)r2;
L_2004058: cmp_a = r1; cmp_b = 0x0u;
L_200405c: if ((cmp_a == cmp_b)) { r1 = 0x2004734u; }
L_2004060: *(unsigned int *)((unsigned char *)r0 + 76) = (unsigned int)r1;
L_2004064: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 72));
L_2004068: r1 = 0x0u;
L_200406c: *(unsigned int *)((unsigned char *)r0 + 80) = (unsigned int)r2;
L_2004070: *(unsigned int *)((unsigned char *)r0 + 68) = (unsigned int)r1;
L_2004074: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 28));
L_2004078: r1 = (r1|0x2u);
L_200407c: *(unsigned int *)((unsigned char *)r0 + 28) = (unsigned int)r1;
L_2004080: r0 = 0x1u;
L_2004084: return r0;
}
