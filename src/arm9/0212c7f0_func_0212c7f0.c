/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212bb7c(unsigned int);
extern unsigned int IntrusiveListWrapper_RemoveItem(unsigned int, unsigned int);
unsigned int func_0212c7f0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_212c7f4: r4 = r0;
L_212c7f8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 64));
L_212c7fc: r0 = func_0212bb7c(r0);
L_212c800: r0 = 0x217dd1cu;
L_212c804: r1 = r4;
L_212c808: r0 = IntrusiveListWrapper_RemoveItem(r0,r1);
L_212c80c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 36));
L_212c810: r0 = (r0&~(0x1u));
L_212c814: *(unsigned int *)((unsigned char *)r4 + 36) = (unsigned int)r0;
L_212c81c: return r0;
}
