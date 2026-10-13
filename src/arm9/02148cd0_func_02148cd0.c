/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_02148cd0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2148cd0: r2 = 0x0u;
L_2148cd4: r1 = (r0&0x1u); cmp_a = r1; cmp_b = 0;
L_2148cd8: if ((cmp_a != cmp_b)) { r2 = (r2+0x20000u); }
L_2148cdc: r1 = (r0&0x2u); cmp_a = r1; cmp_b = 0;
L_2148ce0: if ((cmp_a != cmp_b)) { r2 = (r2+0x20000u); }
L_2148ce4: r1 = (r0&0x4u); cmp_a = r1; cmp_b = 0;
L_2148ce8: if ((cmp_a != cmp_b)) { r2 = (r2+0x20000u); }
L_2148cec: r1 = (r0&0x8u); cmp_a = r1; cmp_b = 0;
L_2148cf0: if ((cmp_a != cmp_b)) { r2 = (r2+0x20000u); }
L_2148cf4: r1 = (r0&0x10u); cmp_a = r1; cmp_b = 0;
L_2148cf8: if ((cmp_a != cmp_b)) { r2 = (r2+0x10000u); }
L_2148cfc: r1 = (r0&0x20u); cmp_a = r1; cmp_b = 0;
L_2148d00: if ((cmp_a != cmp_b)) { r2 = (r2+0x4000u); }
L_2148d04: r1 = (r0&0x40u); cmp_a = r1; cmp_b = 0;
L_2148d08: if ((cmp_a != cmp_b)) { r2 = (r2+0x4000u); }
L_2148d0c: r1 = (r0&0x80u); cmp_a = r1; cmp_b = 0;
L_2148d10: if ((cmp_a != cmp_b)) { r2 = (r2+0x8000u); }
L_2148d14: r0 = (r0&0x100u); cmp_a = r0; cmp_b = 0;
L_2148d18: if ((cmp_a != cmp_b)) { r2 = (r2+0x4000u); }
L_2148d1c: r0 = r2;
L_2148d20: return r0;
}
