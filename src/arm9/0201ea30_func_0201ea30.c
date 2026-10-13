/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_0201ea30(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_201ea30: cmp_a = r1; cmp_b = 0x0u;
L_201ea34: r2 = (r0+0x8u);
L_201ea38: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 6));
L_201ea3c: if (((int)cmp_a < (int)cmp_b)) { goto L_201ea48; }
L_201ea40: cmp_a = r1; cmp_b = r0;
L_201ea44: if (((int)cmp_a < (int)cmp_b)) { goto L_201ea50; }
L_201ea48: r0 = 0x0u;
L_201ea4c: return r0;
L_201ea50: r0 = (r2+(r1 << 3));
L_201ea54: return r0;
}
