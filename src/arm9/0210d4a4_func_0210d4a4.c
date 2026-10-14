/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210e2c4(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_0210e328(unsigned int);
extern unsigned int StructMQChild_Create(unsigned int);
extern unsigned int IntrusiveListWrapper_InitializeEmpty(unsigned int, unsigned int);
unsigned int func_0210d4a4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,r7,r8;
L_210d4a8: r8 = r0;
L_210d4ac: r7 = r1;
L_210d4b0: r0 = 0x217d034u;
L_210d4b4: r1 = r8;
L_210d4b8: r2 = r7;
L_210d4bc: r3 = 0x1cu;
L_210d4c0: r0 = func_0210e2c4(r0,r1,r2,r3);
L_210d4c4: cmp_a = r7; cmp_b = 0x0u;
L_210d4c8: r6 = 0x0u;
L_210d4cc: if (((int)cmp_a <= (int)cmp_b)) { goto L_210d50c; }
L_210d4d0: r5 = r6;
L_210d4d4: r4 = 0x7fu;
L_210d4d8: r0 = r8;
L_210d4dc: r0 = func_0210e328(r0);
L_210d4e0: r0 = (r8+0x8u);
L_210d4e4: r0 = StructMQChild_Create(r0);
L_210d4e8: *(unsigned char *)((unsigned char *)r8 + 24) = (unsigned char)r5;
L_210d4ec: *(unsigned short *)((unsigned char *)r8 + 22) = (unsigned short)r5;
L_210d4f0: *(unsigned char *)((unsigned char *)r8 + 25) = (unsigned char)r5;
L_210d4f4: *(unsigned short *)((unsigned char *)r8 + 20) = (unsigned short)r5;
L_210d4f8: r6 = (r6+0x1u);
L_210d4fc: *(unsigned char *)((unsigned char *)r8 + 26) = (unsigned char)r4;
L_210d500: cmp_a = r6; cmp_b = r7;
L_210d504: r8 = (r8+0x1cu);
L_210d508: if (((int)cmp_a < (int)cmp_b)) { goto L_210d4d8; }
L_210d50c: r0 = 0x217d028u;
L_210d510: r1 = 0x0u;
L_210d514: r0 = IntrusiveListWrapper_InitializeEmpty(r0,r1);
L_210d518: r6 = 0x217d048u;
L_210d51c: r5 = 0x0u;
L_210d520: r4 = 0x1cu;
L_210d524: r0 = r6;
L_210d528: r1 = r4;
L_210d52c: r0 = IntrusiveListWrapper_InitializeEmpty(r0,r1);
L_210d530: r5 = (r5+0x1u);
L_210d534: cmp_a = r5; cmp_b = 0x2u;
L_210d538: r6 = (r6+0xcu);
L_210d53c: if (((int)cmp_a < (int)cmp_b)) { goto L_210d524; }
L_210d540: r1 = 0x217d010u;
L_210d544: r2 = 0x0u;
L_210d548: r0 = 0x217d024u;
L_210d54c: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_210d550: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_210d558: return r0;
}
