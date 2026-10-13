/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020853f0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0207e200(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_207e204: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_207e208: r4 = r0;
L_207e20c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 716));
L_207e210: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 16));
L_207e214: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_207e218: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207e21c: *(unsigned int *)((unsigned char *)r4 + 16) = (unsigned int)r0;
L_207e220: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 4));
L_207e224: r0 = func_020853f0(r0,r1,r2,r3);
L_207e228: *(unsigned int *)((unsigned char *)r4 + 28) = (unsigned int)r0;
L_207e22c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 28));
L_207e230: r2 = 0x0u;
L_207e234: *(unsigned int *)((unsigned char *)r4 + 32) = (unsigned int)r0;
L_207e238: *(unsigned int *)((unsigned char *)r4 + 36) = (unsigned int)r2;
L_207e23c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207e240: r0 = ~(0x0u);
L_207e244: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r1;
L_207e248: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r2;
L_207e24c: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r2;
L_207e250: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207e254: *(unsigned int *)((unsigned char *)r4 + 16) = (unsigned int)r1;
L_207e258: *(unsigned int *)((unsigned char *)r4 + 20) = (unsigned int)r0;
L_207e25c: *(unsigned int *)((unsigned char *)r4 + 24) = (unsigned int)r2;
L_207e264: return r0;
}
