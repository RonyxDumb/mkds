
unsigned int func_ov003_021b8748(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21b8748: r2 = 0x0u; cmp_a = r2; cmp_b = 0;
L_21b874a: r1 = 0x10u; cmp_a = r1; cmp_b = 0;
L_21b874c: r0 = (r0&r1); cmp_a = r0; cmp_b = 0;
L_21b874e: cmp_a = r0; cmp_b = 0x0u;
L_21b8750: if ((cmp_a == cmp_b)) { goto L_21b8754; }
L_21b8752: r2 = 0x1u; cmp_a = r2; cmp_b = 0;
L_21b8754: r0 = (r2+0x0u); cmp_a = r0; cmp_b = 0;
L_21b8756: return r0;
}
