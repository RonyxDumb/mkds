/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0206a24c(unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02067b0c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2067b10: r6 = r0;
L_2067b14: r5 = r1;
L_2067b18: r4 = r2;
L_2067b1c: r0 = func_0206a24c(r0);
L_2067b20: cmp_a = r0; cmp_b = 0x0u;
L_2067b24: if ((cmp_a == cmp_b)) { goto L_2067b50; }
L_2067b28: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 1100));
L_2067b2c: cmp_a = r0; cmp_b = r4;
L_2067b30: if ((cmp_a == cmp_b)) { goto L_2067b50; }
L_2067b34: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 124));
L_2067b38: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2067b3c: if ((cmp_a == cmp_b)) { goto L_2067b50; }
L_2067b40: r0 = GetGlobalRK();
L_2067b44: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_2067b48: r1 = (r1+0x1u);
L_2067b4c: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_2067b50: r0 = 0x0u;
L_2067b54: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r0;
L_2067b5c: return r0;
}
