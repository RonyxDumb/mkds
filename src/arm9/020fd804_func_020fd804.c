/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d2398(unsigned int);
unsigned int func_020fd804(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20fd80c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 408));
L_20fd810: cmp_a = r0; cmp_b = 0x0u;
L_20fd81c: if ((cmp_a == cmp_b)) { return r0; }
L_20fd820: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20fd824: r1 = (r1&~(0x1u));
L_20fd828: *(unsigned short *)((unsigned char *)r0 + 2) = (unsigned short)r1;
L_20fd82c: r0 = func_020d2398(r0);
L_20fd838: return r0;
}
