/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02016b00(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02016c44(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,stack_0;
L_2016c4c: ip = 0x0u;
L_2016c50: stack_0 = ip;
L_2016c54: r0 = func_02016b00(r0,r1,r2,r3,stack_0);
L_2016c60: return r0;
}
