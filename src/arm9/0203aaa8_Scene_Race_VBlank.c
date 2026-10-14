/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MaybeIsMenuOn_from_thumb(void);
extern unsigned int func_02055cbc(unsigned int);
extern unsigned int func_02062000(unsigned int);
extern unsigned int func_020b0b8c(void);
unsigned int Scene_Race_VBlank(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203aab0: r0 = MaybeIsMenuOn_from_thumb();
L_203aab4: r0 = func_02055cbc(r0);
L_203aab8: r0 = func_02062000(r0);
L_203aabc: r0 = func_020b0b8c();
L_203aac8: return r0;
}
