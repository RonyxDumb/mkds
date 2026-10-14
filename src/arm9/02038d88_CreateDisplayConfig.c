/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Mem_AllocateHeap(unsigned int, unsigned int);
extern unsigned int DisplayConfig_SomeFn(unsigned int, unsigned int);
unsigned int CreateDisplayConfig(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2038d8c: r5 = r1;
L_2038d90: r1 = 0xdcu;
L_2038d94: r6 = r0;
L_2038d98: r0 = Mem_AllocateHeap(r0,r1);
L_2038d9c: r4 = r0;
L_2038da0: r1 = r5;
L_2038da4: r0 = DisplayConfig_SomeFn(r0,r1);
L_2038da8: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 10));
L_2038dac: cmp_a = r0; cmp_b = 0x1u;
L_2038db0: if ((cmp_a != cmp_b)) { goto L_2038dd8; }
L_2038db4: r0 = r6;
L_2038db8: r1 = 0x8u;
L_2038dbc: r0 = Mem_AllocateHeap(r0,r1);
L_2038dc0: r1 = 0x5000u;
L_2038dc4: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_2038dc8: r1 = 0x1u;
L_2038dcc: *(unsigned char *)((unsigned char *)r0 + 2) = (unsigned char)r1;
L_2038dd0: *(unsigned char *)((unsigned char *)r0 + 3) = (unsigned char)r1;
L_2038dd4: *(unsigned int *)((unsigned char *)r4 + 108) = (unsigned int)r0;
L_2038dd8: r0 = r4;
L_2038de0: return r0;
}
