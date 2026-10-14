/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int IsAwardOrStaffRoll(void);
extern unsigned int func_01ffc9e8(unsigned int, unsigned int);
extern unsigned int func_020e0538(unsigned int, unsigned int);
unsigned int func_01ff9cb0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_1ff9cb4: r4 = r0;
L_1ff9cb8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 76));
L_1ff9cbc: r0 = (r0&0x2u); cmp_a = r0; cmp_b = 0;
L_1ff9cc0: if ((cmp_a != cmp_b)) { goto L_1ff9cdc; }
L_1ff9cc4: r0 = IsAwardOrStaffRoll();
L_1ff9cc8: cmp_a = r0; cmp_b = 0x1u;
L_1ff9ccc: if ((cmp_a != cmp_b)) { goto L_1ff9cdc; }
L_1ff9cd0: r0 = r4;
L_1ff9cd4: r1 = 0x0u;
L_1ff9cd8: r0 = func_01ffc9e8(r0,r1);
L_1ff9cdc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_1ff9ce0: r0 = (r0&~(0x1000u));
L_1ff9ce4: *(unsigned int *)((unsigned char *)r4 + 68) = (unsigned int)r0;
L_1ff9ce8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 520));
L_1ff9cec: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_1ff9cf0: cmp_a = r1; cmp_b = 0x0u;
L_1ff9cf8: if ((cmp_a == cmp_b)) { return r0; }
L_1ff9cfc: r1 = (r4+0x80u);
L_1ff9d00: r0 = func_020e0538(r0,r1);
L_1ff9d04: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 520));
L_1ff9d08: r1 = 0x0u;
L_1ff9d0c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_1ff9d14: return r0;
}
