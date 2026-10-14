/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020a1048(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a1048: r2 = 0x217b1fcu;
L_20a104c: r1 = 0x70u;
L_20a1050: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20a1054: r3 = 0x0u;
L_20a1058: r1 = (r0*r1+r2);
L_20a105c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 76));
L_20a1060: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 944));
L_20a1064: cmp_a = r0; cmp_b = r1;
L_20a1068: if ((cmp_a != cmp_b)) { goto L_20a1078; }
L_20a106c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 940));
L_20a1070: cmp_a = r0; cmp_b = r1;
L_20a1074: if ((cmp_a != cmp_b)) { r3 = 0x1u; }
L_20a1078: r0 = r3;
L_20a107c: return r0;
}
