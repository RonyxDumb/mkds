/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210e328(unsigned int);
extern unsigned int StructMQChild_Create(unsigned int);
unsigned int func_0210cfe8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210cfec: r4 = r0;
L_210cff0: r0 = func_0210e328(r0);
L_210cff4: r0 = (r4+0x8u);
L_210cff8: r0 = StructMQChild_Create(r0);
L_210cffc: r0 = 0x0u;
L_210d000: *(unsigned char *)((unsigned char *)r4 + 24) = (unsigned char)r0;
L_210d004: *(unsigned short *)((unsigned char *)r4 + 22) = (unsigned short)r0;
L_210d008: *(unsigned char *)((unsigned char *)r4 + 25) = (unsigned char)r0;
L_210d00c: *(unsigned short *)((unsigned char *)r4 + 20) = (unsigned short)r0;
L_210d010: r0 = 0x7fu;
L_210d014: *(unsigned char *)((unsigned char *)r4 + 26) = (unsigned char)r0;
L_210d01c: return r0;
}
