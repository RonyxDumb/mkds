/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Card_InitializeContext(void);
extern unsigned int Card_GetRomAccessFunction(void);
extern unsigned int Card_InitializePulledOutCallback(void);
unsigned int Card_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_214615c: ip = 0x217fa40u;
L_2146160: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 276));
L_2146164: cmp_a = r0; cmp_b = 0x0u;
L_2146170: if ((cmp_a != cmp_b)) { return r0; }
L_2146174: r0 = 0x1u;
L_2146178: *(unsigned int *)((unsigned char *)ip + 276) = (unsigned int)r0;
L_214617c: r3 = 0x0u;
L_2146180: *(unsigned int *)((unsigned char *)ip + 36) = (unsigned int)r3;
L_2146184: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 36));
L_2146188: r1 = ~(0x0u);
L_214618c: *(unsigned int *)((unsigned char *)ip + 32) = (unsigned int)r0;
L_2146190: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 32));
L_2146194: r0 = 0x2180060u;
L_2146198: *(unsigned int *)((unsigned char *)ip + 28) = (unsigned int)r2;
L_214619c: *(unsigned int *)((unsigned char *)ip + 40) = (unsigned int)r1;
L_21461a0: *(unsigned int *)((unsigned char *)ip + 56) = (unsigned int)r3;
L_21461a4: *(unsigned int *)((unsigned char *)ip + 60) = (unsigned int)r3;
L_21461a8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r3;
L_21461ac: r0 = Card_InitializeContext();
L_21461b0: r0 = Card_GetRomAccessFunction();
L_21461b4: r1 = 0x2180080u;
L_21461b8: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_21461bc: r0 = Card_InitializePulledOutCallback();
L_21461c8: return r0;
}
