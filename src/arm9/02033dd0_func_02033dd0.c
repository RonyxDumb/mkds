/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02033dd0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2033dd0: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2033dd2: r1 = 0x2174e60u;
L_2033dd4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2033dd6: r1 = 0x148u;
L_2033dd8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_2033dda: cmp_a = r1; cmp_b = 0x0u;
L_2033ddc: if ((cmp_a == cmp_b)) { goto L_2033dea; }
L_2033dde: r1 = 0x14cu;
L_2033de0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_2033de2: r1 = 0x12cu;
L_2033de4: cmp_a = r2; cmp_b = r1;
L_2033de6: if (((int)cmp_a >= (int)cmp_b)) { goto L_2033dea; }
L_2033de8: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_2033dea: return r0;
}
