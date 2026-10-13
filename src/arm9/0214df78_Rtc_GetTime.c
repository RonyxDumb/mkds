/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Rtc_GetTimeAsync(unsigned int, unsigned int, unsigned int);
extern unsigned int Rtc_WaitBusy(void);
unsigned int Rtc_GetTime(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214df80: r1 = 0x214d954u;
L_214df84: r2 = 0x0u;
L_214df88: r0 = Rtc_GetTimeAsync(r0,r1,r2);
L_214df8c: r1 = 0x21803b0u;
L_214df90: cmp_a = r0; cmp_b = 0x0u;
L_214df94: *(unsigned int *)((unsigned char *)r1 + 32) = (unsigned int)r0;
L_214df98: if ((cmp_a != cmp_b)) { goto L_214dfa0; }
L_214df9c: r0 = Rtc_WaitBusy();
L_214dfa0: r0 = 0x21803b0u;
L_214dfa4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 32));
L_214dfb0: return r0;
}
