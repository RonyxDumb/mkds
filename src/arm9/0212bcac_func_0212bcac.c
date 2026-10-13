/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int IntrusiveListWrapper_RemoveItem(unsigned int, unsigned int);
extern unsigned int func_0212bf14(unsigned int, unsigned int);
extern unsigned int func_0212beb4(unsigned int);
unsigned int func_0212bcac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_212bcb0: r6 = r0;
L_212bcb4: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_212bcb8: r5 = r1;
L_212bcbc: cmp_a = r4; cmp_b = 0x0u;
L_212bcc0: if ((cmp_a == cmp_b)) { goto L_212bcd8; }
L_212bcc4: r0 = r4;
L_212bcc8: r1 = r6;
L_212bccc: r0 = IntrusiveListWrapper_RemoveItem(r0,r1);
L_212bcd0: r0 = 0x0u;
L_212bcd4: *(unsigned int *)((unsigned char *)r6 + 4) = (unsigned int)r0;
L_212bcd8: r0 = 0x217d450u;
L_212bcdc: r1 = r6;
L_212bce0: r0 = IntrusiveListWrapper_RemoveItem(r0,r1);
L_212bce4: *(unsigned char *)((unsigned char *)r6 + 61) = (unsigned char)r5;
L_212bce8: cmp_a = r4; cmp_b = 0x0u;
L_212bcec: if ((cmp_a == cmp_b)) { goto L_212bcfc; }
L_212bcf0: r0 = r4;
L_212bcf4: r1 = r6;
L_212bcf8: r0 = func_0212bf14(r0,r1);
L_212bcfc: r0 = r6;
L_212bd00: r0 = func_0212beb4(r0);
L_212bd08: return r0;
}
