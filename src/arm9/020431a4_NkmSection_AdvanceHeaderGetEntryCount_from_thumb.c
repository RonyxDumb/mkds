/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int NkmSection_AdvanceHeaderGetEntryCount_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20431a4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20431a6: r1 = (r1+0x4u); cmp_a = r1; cmp_b = 0;
L_20431a8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20431aa: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20431ac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_20431ae: r1 = (r1 << 16); cmp_a = r1; cmp_b = 0;
L_20431b0: r2 = (r1 >> 16); cmp_a = r2; cmp_b = 0;
L_20431b2: r1 = (r3+0x4u); cmp_a = r1; cmp_b = 0;
L_20431b4: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20431b6: r0 = (r2+0x0u); cmp_a = r0; cmp_b = 0;
L_20431b8: return r0;
}
