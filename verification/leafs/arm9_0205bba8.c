
unsigned int func_0205bba8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205bba8: r1 = 0x217aa14u;
L_205bbac: r0 = 0x0u;
L_205bbb0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_205bbb4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 1880));
L_205bbb8: cmp_a = r1; cmp_b = 0x3u;
L_205bbbc: if ((cmp_a == cmp_b)) { goto L_205bbdc; }
L_205bbc0: cmp_a = r1; cmp_b = 0x5u;
L_205bbc4: if ((cmp_a != cmp_b)) { return r0; }
L_205bbc8: r1 = (r2+0x700u);
L_205bbcc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 92));
L_205bbd0: r1 = (r1&0x100u); cmp_a = r1; cmp_b = 0;
L_205bbd4: if ((cmp_a != cmp_b)) { r0 = 0x2u; }
L_205bbd8: return r0;
L_205bbdc: r0 = 0x9u;
L_205bbe0: return r0;
}
