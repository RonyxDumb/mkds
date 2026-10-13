/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208606c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020a392c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20a3930: r4 = r0;
L_20a3934: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 168));
L_20a3938: r0 = func_0208606c(r0,r1,r2,r3);
L_20a393c: *(unsigned short *)((unsigned char *)r4 + 114) = (unsigned short)r0;
L_20a3944: return r0;
}
