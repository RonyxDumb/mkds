
unsigned int func_02087934(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2087934: r2 = 0x4000480u;
L_2087938: r1 = 0x21659b4u;
L_208793c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2087940: r0 = 0x21659c0u;
L_2087944: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2087948: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_208794c: r2 = 0x400046cu;
L_2087950: r0 = 0x1333u;
L_2087954: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r1;
L_2087958: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r3;
L_208795c: r1 = 0x2155a74u;
L_2087960: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2087964: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_2087968: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 2));
L_208796c: r0 = 0x400048cu;
L_2087970: r2 = (r3|(r2 << 16));
L_2087974: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_2087978: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 4));
L_208797c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_2087980: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 6));
L_2087984: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 8));
L_2087988: r2 = (r3|(r2 << 16));
L_208798c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_2087990: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 10));
L_2087994: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_2087998: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 12));
L_208799c: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 14));
L_20879a0: r2 = (r3|(r2 << 16));
L_20879a4: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_20879a8: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 16));
L_20879ac: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_20879b0: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 18));
L_20879b4: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 20));
L_20879b8: r2 = (r3|(r2 << 16));
L_20879bc: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_20879c0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 22));
L_20879c4: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20879c8: return r0;
}
