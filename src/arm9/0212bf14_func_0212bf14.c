/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int IntrusiveListWrapper_NextItem(unsigned int, unsigned int);
extern unsigned int IntrusiveListWrapper_SomeFn_0(unsigned int, unsigned int, unsigned int);
unsigned int func_0212bf14(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_212bf1c: r4 = r1;
L_212bf20: r1 = 0x0u;
L_212bf24: r5 = r0;
L_212bf28: r0 = IntrusiveListWrapper_NextItem(r0,r1);
L_212bf2c: r1 = r0; cmp_a = r1; cmp_b = 0;
L_212bf30: if ((cmp_a == cmp_b)) { goto L_212bf54; }
L_212bf34: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 61));
L_212bf38: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 61));
L_212bf3c: cmp_a = r2; cmp_b = r0;
L_212bf40: if ((cmp_a < cmp_b)) { goto L_212bf54; }
L_212bf44: r0 = r5;
L_212bf48: r0 = IntrusiveListWrapper_NextItem(r0,r1);
L_212bf4c: r1 = r0; cmp_a = r1; cmp_b = 0;
L_212bf50: if ((cmp_a != cmp_b)) { goto L_212bf34; }
L_212bf54: r0 = r5;
L_212bf58: r2 = r4;
L_212bf5c: r0 = IntrusiveListWrapper_SomeFn_0(r0,r1,r2);
L_212bf60: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r5;
L_212bf6c: return r0;
}
