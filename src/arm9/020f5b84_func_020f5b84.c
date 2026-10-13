/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f2228(unsigned int, unsigned int);
extern unsigned int func_0210ddf4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_020f11f0(unsigned int, unsigned int);
extern unsigned int func_020fe71c(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020f1180(unsigned int, unsigned int);
unsigned int func_020f5b84(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,stack_0;
L_20f5b8c: r4 = r0;
L_20f5b90: r1 = 0x8800u;
L_20f5b94: r0 = func_020f2228(r0,r1);
L_20f5b98: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f5b9c: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_20f5ba0: if ((cmp_a != cmp_b)) { goto L_20f5bc4; }
L_20f5ba4: r0 = 0x0u;
L_20f5ba8: stack_0 = r0;
L_20f5bac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 212));
L_20f5bb0: r0 = 0x217d294u;
L_20f5bb4: r2 = 0x20f5fb8u;
L_20f5bb8: r3 = r4;
L_20f5bbc: r1 = (r1&~(0xc000001fu));
L_20f5bc0: r0 = func_0210ddf4(r0,r1,r2,r3,stack_0);
L_20f5bc4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f5bc8: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_20f5bd4: if ((cmp_a != cmp_b)) { return r0; }
L_20f5bd8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 576));
L_20f5bdc: cmp_a = r0; cmp_b = 0x10u;
L_20f5be0: if ((cmp_a <= cmp_b)) { goto L_20f5c48; }
L_20f5be4: r0 = r4;
L_20f5be8: r1 = 0x0u;
L_20f5bec: r0 = func_020f11f0(r0,r1);
L_20f5bf0: cmp_a = r0; cmp_b = 0x0u;
L_20f5bfc: if ((cmp_a == cmp_b)) { return r0; }
L_20f5c00: r1 = (r4+0x200u);
L_20f5c04: r0 = 0x4u;
L_20f5c08: *(unsigned short *)((unsigned char *)r1 + 76) = (unsigned short)r0;
L_20f5c0c: r0 = 0x1u;
L_20f5c10: *(unsigned short *)((unsigned char *)r1 + 78) = (unsigned short)r0;
L_20f5c14: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f5c18: r1 = (r1&0x8000000u); cmp_a = r1; cmp_b = 0;
L_20f5c24: if ((cmp_a == cmp_b)) { return r0; }
L_20f5c28: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 552));
L_20f5c2c: r2 = (unsigned int)(*(short *)((unsigned char *)r4 + 78));
L_20f5c30: r1 = (r1+0x100u);
L_20f5c34: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 248));
L_20f5c38: r0 = func_020fe71c(r0,r1,r2);
L_20f5c44: return r0;
L_20f5c48: cmp_a = r0; cmp_b = 0x4u;
L_20f5c54: if ((cmp_a <= cmp_b)) { return r0; }
L_20f5c58: r0 = r4;
L_20f5c5c: r1 = 0x0u;
L_20f5c60: r0 = func_020f1180(r0,r1);
L_20f5c64: cmp_a = r0; cmp_b = 0x0u;
L_20f5c70: if ((cmp_a == cmp_b)) { return r0; }
L_20f5c74: r1 = (r4+0x200u);
L_20f5c78: r0 = 0x4u;
L_20f5c7c: *(unsigned short *)((unsigned char *)r1 + 76) = (unsigned short)r0;
L_20f5c80: r0 = 0x1u;
L_20f5c84: *(unsigned short *)((unsigned char *)r1 + 78) = (unsigned short)r0;
L_20f5c88: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f5c8c: r1 = (r1&0x8000000u); cmp_a = r1; cmp_b = 0;
L_20f5c98: if ((cmp_a == cmp_b)) { return r0; }
L_20f5c9c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 552));
L_20f5ca0: r2 = (unsigned int)(*(short *)((unsigned char *)r4 + 78));
L_20f5ca4: r1 = (r1+0x100u);
L_20f5ca8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 248));
L_20f5cac: r0 = func_020fe71c(r0,r1,r2);
L_20f5cb8: return r0;
}
