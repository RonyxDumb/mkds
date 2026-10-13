/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0212c450(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_212c450: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c454: cmp_a = ip; cmp_b = 0x0u;
L_212c458: if ((cmp_a == cmp_b)) { return r0; }
L_212c45c: r3 = 0x2u;
L_212c460: *(unsigned short *)((unsigned char *)ip + 52) = (unsigned short)r3;
L_212c464: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c468: *(unsigned short *)((unsigned char *)r3 + 56) = (unsigned short)r1;
L_212c46c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c470: *(unsigned short *)((unsigned char *)r0 + 58) = (unsigned short)r2;
L_212c474: return r0;
}
