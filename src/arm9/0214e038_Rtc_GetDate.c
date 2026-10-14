/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Rtc_GetDateAsync(unsigned int, unsigned int, unsigned int);
extern unsigned int Rtc_WaitBusy(void);
unsigned int Rtc_GetDate(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214e040: r1 = 0x214d954u;
L_214e044: r2 = 0x0u;
L_214e048: r0 = Rtc_GetDateAsync(r0,r1,r2);
L_214e04c: r1 = 0x21803b0u;
L_214e050: cmp_a = r0; cmp_b = 0x0u;
L_214e054: *(unsigned int *)((unsigned char *)r1 + 32) = (unsigned int)r0;
L_214e058: if ((cmp_a != cmp_b)) { goto L_214e060; }
L_214e05c: r0 = Rtc_WaitBusy();
L_214e060: r0 = 0x21803b0u;
L_214e064: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 32));
L_214e070: return r0;
}
