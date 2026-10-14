/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StateDualHandler_SetState(unsigned int, unsigned int);
extern unsigned int func_020d2398(unsigned int);
extern unsigned int func_020f0f70(unsigned int, unsigned int);
unsigned int func_020fd494(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20fd49c: r5 = r0;
L_20fd4a0: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 0));
L_20fd4a4: r1 = 0x0u;
L_20fd4a8: r0 = (r4+0x184u);
L_20fd4ac: r0 = StateDualHandler_SetState(r0,r1);
L_20fd4b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 408));
L_20fd4b4: cmp_a = r0; cmp_b = 0x0u;
L_20fd4b8: if ((cmp_a == cmp_b)) { goto L_20fd4f4; }
L_20fd4bc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20fd4c0: r1 = (r1&~(0x1u));
L_20fd4c4: *(unsigned short *)((unsigned char *)r0 + 2) = (unsigned short)r1;
L_20fd4c8: r0 = func_020d2398(r0);
L_20fd4cc: r0 = 0x0u;
L_20fd4d0: *(unsigned int *)((unsigned char *)r4 + 408) = (unsigned int)r0;
L_20fd4d4: r0 = 0x27e00ccu;
L_20fd4d8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_20fd4dc: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20fd4e0: r0 = 0x44u;
L_20fd4e4: r0 = (r1*r0+r2);
L_20fd4e8: r1 = r4;
L_20fd4ec: r0 = func_020f0f70(r0,r1);
L_20fd4f0: goto L_20fd510;
L_20fd4f4: r0 = 0x27e00ccu;
L_20fd4f8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_20fd4fc: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20fd500: r0 = 0x44u;
L_20fd504: r0 = (r1*r0+r2);
L_20fd508: r1 = r4;
L_20fd50c: r0 = func_020f0f70(r0,r1);
L_20fd510: r0 = 0x0u;
L_20fd514: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r0;
L_20fd520: return r0;
}
