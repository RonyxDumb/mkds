/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_Exp_Finalize(void);
unsigned int DisposeOverlayManagerHeap(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2059d88: r0 = 0x217aa10u;
L_2059d8c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2059d90: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 164));
L_2059d94: cmp_a = r0; cmp_b = 0x0u;
L_2059da0: if ((cmp_a == cmp_b)) { return r0; }
L_2059da4: r0 = Mem_Exp_Finalize();
L_2059da8: r0 = 0x217aa10u;
L_2059dac: r1 = 0x0u;
L_2059db0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2059db4: *(unsigned int *)((unsigned char *)r0 + 164) = (unsigned int)r1;
L_2059dc0: return r0;
}
