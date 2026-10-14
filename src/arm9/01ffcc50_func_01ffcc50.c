/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020732d8(unsigned int);
extern unsigned int func_01ffca50(unsigned int);
extern unsigned int func_01ffbe70(unsigned int);
extern unsigned int func_02067488(unsigned int);
extern unsigned int func_01ffbe04(unsigned int);
extern unsigned int func_01ffbd9c(unsigned int);
extern unsigned int func_01ffc6c0(unsigned int);
extern unsigned int func_01ff9d18(unsigned int);
extern unsigned int func_020708a4(unsigned int);
extern unsigned int func_01ffb130(unsigned int);
unsigned int func_01ffcc50(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_1ffcc54: r4 = r0;
L_1ffcc58: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_1ffcc5c: r1 = (r1&0xa0u); cmp_a = r1; cmp_b = 0;
L_1ffcc60: if ((cmp_a == cmp_b)) { goto L_1ffcc70; }
L_1ffcc64: r0 = func_020732d8(r0);
L_1ffcc6c: return r0;
L_1ffcc70: r0 = func_01ffca50(r0);
L_1ffcc74: r0 = r4;
L_1ffcc78: r0 = func_01ffbe70(r0);
L_1ffcc7c: r0 = r4;
L_1ffcc80: r0 = func_02067488(r0);
L_1ffcc84: r0 = r4;
L_1ffcc88: r0 = func_01ffbe04(r0);
L_1ffcc8c: r0 = r4;
L_1ffcc90: r0 = func_01ffbd9c(r0);
L_1ffcc94: r0 = r4;
L_1ffcc98: r0 = func_01ffc6c0(r0);
L_1ffcc9c: r0 = r4;
L_1ffcca0: r0 = func_01ff9d18(r0);
L_1ffcca4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_1ffcca8: r0 = (r0&0x10000u); cmp_a = r0; cmp_b = 0;
L_1ffccac: if ((cmp_a == cmp_b)) { goto L_1ffccc0; }
L_1ffccb0: r0 = r4;
L_1ffccb4: r0 = func_020708a4(r0);
L_1ffccbc: return r0;
L_1ffccc0: r0 = r4;
L_1ffccc4: r0 = func_01ffb130(r0);
L_1ffcccc: return r0;
}
