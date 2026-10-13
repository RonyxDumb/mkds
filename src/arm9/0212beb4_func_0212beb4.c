/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int IntrusiveListWrapper_NextItem(unsigned int, unsigned int);
extern unsigned int IntrusiveListWrapper_SomeFn_0(unsigned int, unsigned int, unsigned int);
unsigned int func_0212beb4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_212bebc: r5 = r0;
L_212bec0: r0 = 0x217d450u;
L_212bec4: r1 = 0x0u;
L_212bec8: r0 = IntrusiveListWrapper_NextItem(r0,r1);
L_212becc: r1 = r0; cmp_a = r1; cmp_b = 0;
L_212bed0: if ((cmp_a == cmp_b)) { goto L_212bef8; }
L_212bed4: r4 = 0x217d450u;
L_212bed8: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r5 + 61));
L_212bedc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 61));
L_212bee0: cmp_a = r2; cmp_b = r0;
L_212bee4: if ((cmp_a < cmp_b)) { goto L_212bef8; }
L_212bee8: r0 = r4;
L_212beec: r0 = IntrusiveListWrapper_NextItem(r0,r1);
L_212bef0: r1 = r0; cmp_a = r1; cmp_b = 0;
L_212bef4: if ((cmp_a != cmp_b)) { goto L_212bed8; }
L_212bef8: r0 = 0x217d450u;
L_212befc: r2 = r5;
L_212bf00: r0 = IntrusiveListWrapper_SomeFn_0(r0,r1,r2);
L_212bf0c: return r0;
}
