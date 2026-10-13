/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020533a0(void);
unsigned int func_02052bb8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2052bc0: r1 = 0x217aa00u;
L_2052bc4: r2 = 0x0u;
L_2052bc8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2052bcc: *(unsigned int *)((unsigned char *)r1 + 16) = (unsigned int)r2;
L_2052bd0: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_2052bd4: cmp_a = r0; cmp_b = 0x0u;
L_2052be0: if ((cmp_a == cmp_b)) { return r0; }
L_2052be4: r0 = func_020533a0();
L_2052bf0: return r0;
}
