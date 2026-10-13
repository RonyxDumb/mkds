/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SetPolygonId(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMapObject_MaybeSetPolygonId(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_209b948: r5 = r0;
L_209b94c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_209b950: r4 = r1;
L_209b954: cmp_a = r2; cmp_b = 0x0u;
L_209b958: if ((cmp_a == cmp_b)) { goto L_209b974; }
L_209b95c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 20));
L_209b960: r0 = (r0&~(0x3f000000u));
L_209b964: *(unsigned int *)((unsigned char *)r2 + 20) = (unsigned int)r0;
L_209b968: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 20));
L_209b96c: r0 = (r0|(r4 << 24));
L_209b970: *(unsigned int *)((unsigned char *)r2 + 20) = (unsigned int)r0;
L_209b974: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 16));
L_209b978: cmp_a = r0; cmp_b = 0x0u;
L_209b97c: if ((cmp_a == cmp_b)) { goto L_209b98c; }
L_209b980: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_209b984: r1 = r4;
L_209b988: r0 = ModelBlock_SetPolygonId(r0,r1,r2,r3);
L_209b98c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209b990: cmp_a = r0; cmp_b = 0x0u;
L_209b994: if ((cmp_a != cmp_b)) { *(unsigned short *)((unsigned char *)r0 + 108) = (unsigned short)r4; }
L_209b9a0: return r0;
}
