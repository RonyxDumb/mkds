/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02100138(unsigned int);
extern unsigned int func_0209bbfc(unsigned int);
unsigned int func_020ac5e4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20ac5e8: r4 = r0;
L_20ac5ec: r0 = 0x70u;
L_20ac5f0: r0 = func_02100138(r0);
L_20ac5f4: r0 = func_0209bbfc(r0);
L_20ac5f8: cmp_a = r0; cmp_b = 0x0u;
L_20ac600: if ((cmp_a == cmp_b)) { return r0; }
L_20ac604: r1 = 0x0u;
L_20ac608: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_20ac60c: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r1;
L_20ac610: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r1;
L_20ac614: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)r1;
L_20ac618: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_20ac61c: *(unsigned int *)((unsigned char *)r0 + 24) = (unsigned int)r1;
L_20ac620: *(unsigned int *)((unsigned char *)r0 + 172) = (unsigned int)r4;
L_20ac624: *(unsigned int *)((unsigned char *)r0 + 160) = (unsigned int)r1;
L_20ac628: *(unsigned int *)((unsigned char *)r0 + 164) = (unsigned int)r1;
L_20ac62c: *(unsigned int *)((unsigned char *)r0 + 168) = (unsigned int)r1;
L_20ac630: *(unsigned int *)((unsigned char *)r0 + 176) = (unsigned int)r1;
L_20ac638: return r0;
}
