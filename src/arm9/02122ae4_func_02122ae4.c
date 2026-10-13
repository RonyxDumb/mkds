/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_02122ae4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2122ae4: r1 = 0x217d384u;
L_2122ae8: r0 = 0x0u;
L_2122aec: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2122af0: r1 = (r1+0x1000u);
L_2122af4: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 2477));
L_2122af8: cmp_a = r2; cmp_b = 0x1u;
L_2122afc: if ((cmp_a != cmp_b)) { return r0; }
L_2122b00: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 2384));
L_2122b04: cmp_a = r1; cmp_b = 0xcu;
L_2122b08: if ((cmp_a == cmp_b)) { r0 = 0x1u; }
L_2122b0c: return r0;
}
