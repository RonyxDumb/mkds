/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210bafc(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int DriverContext_MaybeQueuePlaySfx(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0210b234(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210b238: r4 = r0;
L_210b23c: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 52));
L_210b240: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_210b248: if ((cmp_a == cmp_b)) { return r0; }
L_210b24c: r0 = r1;
L_210b250: r1 = r2;
L_210b254: r2 = r3;
L_210b258: r0 = func_0210bafc(r0,r1,r2,r3);
L_210b25c: r2 = 0xffffu;
L_210b260: r1 = r0;
L_210b264: cmp_a = r1; cmp_b = r2;
L_210b26c: if ((cmp_a == cmp_b)) { return r0; }
L_210b270: r0 = 0x21759c0u;
L_210b274: r2 = 0x7fu;
L_210b278: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_210b27c: r3 = 0x0u;
L_210b280: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_210b284: cmp_a = r0; cmp_b = 0x1du;
L_210b288: if ((cmp_a == cmp_b)) { r1 = 0x1b6u; }
L_210b28c: r0 = r4;
L_210b290: r0 = DriverContext_MaybeQueuePlaySfx(r0,r1,r2,r3);
L_210b298: return r0;
}
