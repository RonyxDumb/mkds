
unsigned int StructPRSub_Create(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20f89b0: *(unsigned int *)((unsigned char *)r0 + 24) = (unsigned int)r1;
L_20f89b4: ip = 0x0u;
L_20f89b8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)ip;
L_20f89bc: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)ip;
L_20f89c0: r2 = 0x13u;
L_20f89c4: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r2;
L_20f89c8: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)r2;
L_20f89cc: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r2;
L_20f89d0: *(unsigned int *)((unsigned char *)r0 + 32) = (unsigned int)ip;
L_20f89d4: r1 = (r1+0x100u);
L_20f89d8: r2 = 0x21759c0u;
L_20f89dc: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 248));
L_20f89e0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20f89e4: r1 = 0x30u;
L_20f89e8: r1 = (r3*r1+r2);
L_20f89ec: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 112));
L_20f89f0: cmp_a = r1; cmp_b = 0x3u;
L_20f89f4: if ((cmp_a == cmp_b)) { ip = 0x1u; }
L_20f89f8: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)ip;
L_20f89fc: return r0;
}
