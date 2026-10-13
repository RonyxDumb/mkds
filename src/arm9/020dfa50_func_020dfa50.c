/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StateDualHandler_Execute(unsigned int);
extern unsigned int func_0208b5b0(unsigned int, unsigned int);
unsigned int func_020dfa50(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20dfa54: r4 = r1;
L_20dfa58: r0 = (r4+0x80u);
L_20dfa5c: r0 = StateDualHandler_Execute(r0);
L_20dfa60: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 240));
L_20dfa64: cmp_a = r0; cmp_b = 0x0u;
L_20dfa6c: if ((cmp_a != cmp_b)) { return r0; }
L_20dfa70: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_20dfa74: r0 = (r0&0x12u); cmp_a = r0; cmp_b = 0;
L_20dfa78: if ((cmp_a == cmp_b)) { goto L_20dfaa4; }
L_20dfa7c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 232));
L_20dfa80: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 36));
L_20dfa84: r0 = (r0|0x8u);
L_20dfa88: *(unsigned int *)((unsigned char *)r1 + 36) = (unsigned int)r0;
L_20dfa8c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 236));
L_20dfa90: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 36));
L_20dfa94: r0 = (r0|0x8u);
L_20dfa98: *(unsigned int *)((unsigned char *)r1 + 36) = (unsigned int)r0;
L_20dfaa0: return r0;
L_20dfaa4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 232));
L_20dfaa8: r1 = (r4+0x4u);
L_20dfaac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 36));
L_20dfab0: r0 = (r0&~(0x8u));
L_20dfab4: *(unsigned int *)((unsigned char *)r2 + 36) = (unsigned int)r0;
L_20dfab8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 236));
L_20dfabc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 36));
L_20dfac0: r0 = (r0&~(0x8u));
L_20dfac4: *(unsigned int *)((unsigned char *)r2 + 36) = (unsigned int)r0;
L_20dfac8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 232));
L_20dfacc: r0 = func_0208b5b0(r0,r1);
L_20dfad0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 236));
L_20dfad4: r1 = (r4+0x4u);
L_20dfad8: r0 = func_0208b5b0(r0,r1);
L_20dfae0: return r0;
}
