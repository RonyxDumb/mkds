/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StateDualHandler_Execute(unsigned int);
extern unsigned int func_020d77e0(unsigned int, unsigned int, unsigned int);
extern unsigned int func_01ffccd0(unsigned int, unsigned int);
unsigned int func_020e595c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e5960: r4 = r1;
L_20e5964: r0 = (r4+0x80u);
L_20e5968: r0 = StateDualHandler_Execute(r0);
L_20e596c: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 126));
L_20e5970: r0 = (r4+0xb0u);
L_20e5974: r2 = (r4+0xa0u);
L_20e5978: r0 = func_020d77e0(r0,r1,r2);
L_20e597c: r0 = (r4+0x28u);
L_20e5980: r1 = (r4+0xa0u);
L_20e5984: r0 = func_01ffccd0(r0,r1);
L_20e598c: return r0;
}
