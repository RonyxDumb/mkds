/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateAllocateMapObject_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020d49d8(unsigned int);
unsigned int func_02098328(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2098330: r0 = 0x2098a14u;
L_2098334: r1 = 0x2098954u;
L_2098338: r2 = 0x20989fcu;
L_209833c: r0 = CreateAllocateMapObject_from_thumb(r0,r1,r2);
L_2098340: r1 = 0x217b108u;
L_2098344: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2098348: r0 = r1;
L_209834c: r0 = func_020d49d8(r0);
L_2098350: r0 = 0x217b108u;
L_2098354: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2098360: return r0;
}
