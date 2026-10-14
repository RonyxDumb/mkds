/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02010b50(unsigned int, unsigned int);
extern unsigned int func_02010bc8(unsigned int, unsigned int);
unsigned int StructML_SomeFn_3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2010abc: r4 = r1;
L_2010ac0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 8));
L_2010ac4: r5 = r0;
L_2010ac8: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_2010acc: cmp_a = r0; cmp_b = 0x4au;
L_2010ad0: if ((cmp_a == cmp_b)) { goto L_2010b10; }
L_2010ad4: cmp_a = r0; cmp_b = 0x4du;
L_2010ad8: if ((cmp_a == cmp_b)) { goto L_2010af0; }
L_2010adc: cmp_a = r0; cmp_b = 0x56u;
L_2010ae0: if ((cmp_a == cmp_b)) { goto L_2010b30; }
L_2010aec: return r0;
L_2010af0: r0 = (r5+0x3cu);
L_2010af4: r0 = func_02010b50(r0,r1);
L_2010af8: r1 = r4;
L_2010afc: r0 = (r5+0x8u);
L_2010b00: r0 = func_02010bc8(r0,r1);
L_2010b0c: return r0;
L_2010b10: r0 = (r5+0x44u);
L_2010b14: r0 = func_02010b50(r0,r1);
L_2010b18: r1 = r4;
L_2010b1c: r0 = (r5+0x10u);
L_2010b20: r0 = func_02010bc8(r0,r1);
L_2010b2c: return r0;
L_2010b30: r0 = (r5+0x4cu);
L_2010b34: r0 = func_02010b50(r0,r1);
L_2010b38: r1 = r4;
L_2010b3c: r0 = (r5+0x18u);
L_2010b40: r0 = func_02010bc8(r0,r1);
L_2010b4c: return r0;
}
