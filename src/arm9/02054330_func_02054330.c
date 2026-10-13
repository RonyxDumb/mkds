/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02054f58(void);
unsigned int func_02054330(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2054338: r0 = func_02054f58();
L_205433c: cmp_a = r0; cmp_b = 0x1u;
L_2054340: if ((cmp_a != cmp_b)) { goto L_2054338; }
L_2054344: r0 = 0x217aa00u;
L_2054348: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_205434c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 1110));
L_2054350: r0 = (r0&~(0x1u));
L_2054354: *(unsigned char *)((unsigned char *)r1 + 1110) = (unsigned char)r0;
L_2054360: return r0;
}
