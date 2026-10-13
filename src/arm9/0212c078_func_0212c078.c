/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020ddc(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_02020c60(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0212bf70(unsigned int);
extern unsigned int func_02021114(void);
unsigned int func_0212c078(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_212c080: r5 = r0;
L_212c084: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r5 + 60));
L_212c088: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 4));
L_212c08c: r0 = func_02020ddc(r0,r1,r2,r3);
L_212c090: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 28));
L_212c094: cmp_a = r2; cmp_b = 0x0u;
L_212c098: if ((cmp_a == cmp_b)) { goto L_212c0a8; }
L_212c09c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r5 + 60));
L_212c0a0: r1 = 0xffffu;
L_212c0a4: r0 = func_02020c60(r0,r1,r2);
L_212c0a8: r0 = r5;
L_212c0ac: r0 = func_0212bf70(r0);
L_212c0b0: r0 = func_02021114();
L_212c0b4: *(unsigned int *)((unsigned char *)r5 + 48) = (unsigned int)r0;
L_212c0b8: r0 = 0x1u;
L_212c0bc: *(unsigned char *)((unsigned char *)r5 + 47) = (unsigned char)r0;
L_212c0c0: *(unsigned char *)((unsigned char *)r5 + 44) = (unsigned char)r0;
L_212c0cc: return r0;
}
