/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int NNS_G3dGetResDataByName(unsigned int, unsigned int);
extern unsigned int func_0201063c(unsigned int, unsigned int);
unsigned int func_02010458(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_201045c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_2010460: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + (0 + r3)));
L_2010464: r4 = (r0+r3);
L_2010468: r0 = (r4+r2);
L_201046c: r0 = NNS_G3dGetResDataByName(r0,r1);
L_2010470: r1 = r0; cmp_a = r1; cmp_b = 0;
L_2010474: if ((cmp_a == cmp_b)) { goto L_2010498; }
L_2010478: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 3));
L_201047c: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2010480: if ((cmp_a == cmp_b)) { goto L_2010498; }
L_2010484: r0 = r4;
L_2010488: r0 = func_0201063c(r0,r1);
L_201048c: r0 = 0x1u;
L_2010494: return r0;
L_2010498: r0 = 0x0u;
L_20104a0: return r0;
}
