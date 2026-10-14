/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02100138(unsigned int);
extern unsigned int func_0209bbfc(unsigned int);
extern unsigned int func_020a1218(unsigned int);
extern unsigned int func_0210b98c(unsigned int, unsigned int);
unsigned int func_020a5744(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,r7;
L_20a574c: r6 = r0;
L_20a5750: r0 = 0x6au;
L_20a5754: r5 = r1;
L_20a5758: r7 = r2;
L_20a575c: r0 = func_02100138(r0);
L_20a5760: r0 = func_0209bbfc(r0);
L_20a5764: r4 = r0; cmp_a = r4; cmp_b = 0;
L_20a5770: if ((cmp_a == cmp_b)) { return r0; }
L_20a5774: cmp_a = r7; cmp_b = 0x0u;
L_20a5778: if ((cmp_a == cmp_b)) { goto L_20a57c4; }
L_20a577c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 0));
L_20a5780: r1 = 0x0u;
L_20a5784: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r0;
L_20a5788: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_20a578c: r0 = 0x2800u;
L_20a5790: r2 = (r2+0x32000u);
L_20a5794: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r2;
L_20a5798: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 8));
L_20a579c: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r2;
L_20a57a0: *(unsigned int *)((unsigned char *)r4 + 16) = (unsigned int)r1;
L_20a57a4: *(unsigned int *)((unsigned char *)r4 + 20) = (unsigned int)r0;
L_20a57a8: *(unsigned int *)((unsigned char *)r4 + 24) = (unsigned int)r1;
L_20a57ac: *(unsigned int *)((unsigned char *)r4 + 160) = (unsigned int)r1;
L_20a57b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_20a57b4: r0 = (r0+0x14000u);
L_20a57b8: *(unsigned int *)((unsigned char *)r4 + 164) = (unsigned int)r0;
L_20a57bc: *(unsigned int *)((unsigned char *)r4 + 224) = (unsigned int)r1;
L_20a57c0: goto L_20a5800;
L_20a57c4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 0));
L_20a57c8: r1 = 0x0u;
L_20a57cc: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r0;
L_20a57d0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 4));
L_20a57d4: r0 = 0x1u;
L_20a57d8: r2 = (r2+0x14000u);
L_20a57dc: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r2;
L_20a57e0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 8));
L_20a57e4: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r2;
L_20a57e8: *(unsigned int *)((unsigned char *)r4 + 16) = (unsigned int)r1;
L_20a57ec: *(unsigned int *)((unsigned char *)r4 + 20) = (unsigned int)r1;
L_20a57f0: *(unsigned int *)((unsigned char *)r4 + 24) = (unsigned int)r1;
L_20a57f4: *(unsigned int *)((unsigned char *)r4 + 160) = (unsigned int)r1;
L_20a57f8: *(unsigned int *)((unsigned char *)r4 + 164) = (unsigned int)r1;
L_20a57fc: *(unsigned int *)((unsigned char *)r4 + 224) = (unsigned int)r0;
L_20a5800: r0 = 0x0u;
L_20a5804: *(unsigned int *)((unsigned char *)r4 + 168) = (unsigned int)r0;
L_20a5808: *(unsigned int *)((unsigned char *)r4 + 192) = (unsigned int)r0;
L_20a580c: *(unsigned int *)((unsigned char *)r4 + 196) = (unsigned int)r5;
L_20a5810: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_20a5814: r0 = 0x1u;
L_20a5818: r1 = (r1&~(0x1u));
L_20a581c: *(unsigned short *)((unsigned char *)r4 + 2) = (unsigned short)r1;
L_20a5820: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_20a5824: r1 = (r1&~(0x20u));
L_20a5828: *(unsigned short *)((unsigned char *)r4 + 2) = (unsigned short)r1;
L_20a582c: r0 = func_020a1218(r0);
L_20a5830: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_20a5834: r1 = 0x138u;
L_20a5838: r0 = func_0210b98c(r0,r1);
L_20a5844: return r0;
}
