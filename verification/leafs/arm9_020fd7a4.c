
unsigned int func_020fd7a4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20fd7a4: r1 = 0x27e00ccu;
L_20fd7a8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20fd7ac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 616));
L_20fd7b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + (0 + (r0 << 2))));
L_20fd7b4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 116));
L_20fd7b8: r1 = (r2&0x8000u); cmp_a = r1; cmp_b = 0;
L_20fd7bc: if ((cmp_a == cmp_b)) { goto L_20fd7e4; }
L_20fd7c0: r1 = (r2&0x180000u); cmp_a = r1; cmp_b = 0;
L_20fd7c4: if ((cmp_a != cmp_b)) { goto L_20fd7e4; }
L_20fd7c8: r1 = (r0+0x100u);
L_20fd7cc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 146));
L_20fd7d0: cmp_a = r1; cmp_b = 0x3u;
L_20fd7d4: if ((cmp_a == cmp_b)) { goto L_20fd7e4; }
L_20fd7d8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 408));
L_20fd7dc: cmp_a = r1; cmp_b = 0x0u;
L_20fd7e0: if ((cmp_a == cmp_b)) { return r0; }
L_20fd7e4: r0 = 0x0u;
L_20fd7e8: return r0;
}
