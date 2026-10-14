/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Nsbmd_GetMDL0Block(unsigned int);
extern unsigned int Nsbtx_GetTEX0Block(unsigned int);
extern unsigned int IntrusiveListWrapper_InsertLast(unsigned int, unsigned int);
extern unsigned int Tex0Block_MaybePrepareFields(unsigned int);
extern unsigned int func_02010168(unsigned int, unsigned int);
unsigned int LoadedModelTexture_SomeFn(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,r7;
L_2085274: r7 = r1;
L_2085278: r6 = r0;
L_208527c: r4 = r2;
L_2085280: r0 = r7;
L_2085284: r0 = Nsbmd_GetMDL0Block(r0);
L_2085288: r5 = r0;
L_208528c: r0 = r4;
L_2085290: r0 = Nsbtx_GetTEX0Block(r0);
L_2085294: r2 = 0x0u;
L_2085298: r4 = r0;
L_208529c: *(unsigned int *)((unsigned char *)r6 + 12) = (unsigned int)r2;
L_20852a0: r0 = 0x217aeb0u;
L_20852a4: r1 = r6;
L_20852a8: *(unsigned int *)((unsigned char *)r6 + 8) = (unsigned int)r2;
L_20852ac: r0 = IntrusiveListWrapper_InsertLast(r0,r1);
L_20852b0: cmp_a = r4; cmp_b = 0x0u;
L_20852b8: *(unsigned int *)((unsigned char *)r6 + 8) = (unsigned int)r7;
L_20852c0: if ((cmp_a == cmp_b)) { return r0; }
L_20852c4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 16));
L_20852c8: r2 = 0x0u;
L_20852cc: r0 = r4;
L_20852d0: r1 = (r1&~(0x1u));
L_20852d4: *(unsigned short *)((unsigned char *)r4 + 16) = (unsigned short)r1;
L_20852d8: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 32));
L_20852dc: r1 = (r1&~(0x1u));
L_20852e0: *(unsigned short *)((unsigned char *)r4 + 32) = (unsigned short)r1;
L_20852e4: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r2;
L_20852e8: *(unsigned int *)((unsigned char *)r4 + 24) = (unsigned int)r2;
L_20852ec: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 50));
L_20852f0: r1 = (r1&~(0x1u));
L_20852f4: *(unsigned short *)((unsigned char *)r4 + 50) = (unsigned short)r1;
L_20852f8: *(unsigned int *)((unsigned char *)r4 + 44) = (unsigned int)r2;
L_20852fc: r0 = Tex0Block_MaybePrepareFields(r0);
L_2085300: *(unsigned int *)((unsigned char *)r6 + 12) = (unsigned int)r4;
L_2085304: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 0));
L_2085308: r0 = 0x304c444du;
L_208530c: cmp_a = r1; cmp_b = r0;
L_2085318: if ((cmp_a != cmp_b)) { return r0; }
L_208531c: r0 = r5;
L_2085320: r1 = r4;
L_2085324: r0 = func_02010168(r0,r1);
L_2085330: return r0;
}
