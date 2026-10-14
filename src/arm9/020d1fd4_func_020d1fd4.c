/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetRaceStartCountdown(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_020d1de8(unsigned int, unsigned int);
extern unsigned int func_020d1a98(unsigned int);
extern unsigned int func_020d18d4(unsigned int);
unsigned int func_020d1fd4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d1fd8: r4 = r0;
L_20d1fdc: r0 = GetRaceStartCountdown(r0,r1,r2,r3);
L_20d1fe0: r2 = 0x21759c0u;
L_20d1fe4: r1 = r0;
L_20d1fe8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20d1fec: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 12));
L_20d1ff0: cmp_a = r0; cmp_b = 0x4u;
L_20d1ff8: if ((cmp_a == cmp_b)) { return r0; }
L_20d1ffc: cmp_a = r0; cmp_b = 0x1u;
L_20d2004: if ((cmp_a == cmp_b)) { return r0; }
L_20d2008: cmp_a = r1; cmp_b = 0xb4u;
L_20d2010: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20d2014: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 8));
L_20d2018: cmp_a = r0; cmp_b = 0x5u;
L_20d201c: if ((cmp_a == cmp_b)) { goto L_20d203c; }
L_20d2020: cmp_a = r0; cmp_b = 0x3u;
L_20d2028: if ((cmp_a != cmp_b)) { return r0; }
L_20d202c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 28));
L_20d2030: cmp_a = r0; cmp_b = 0x2u;
L_20d2038: if ((cmp_a != cmp_b)) { return r0; }
L_20d203c: r0 = r4;
L_20d2040: r0 = func_020d1de8(r0,r1);
L_20d2044: r0 = 0x217b4b4u;
L_20d2048: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d204c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 28));
L_20d2050: cmp_a = r0; cmp_b = 0x0u;
L_20d2058: if ((cmp_a == cmp_b)) { return r0; }
L_20d205c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 4));
L_20d2060: cmp_a = r0; cmp_b = 0xau;
L_20d2064: if (((int)cmp_a < (int)cmp_b)) { goto L_20d2078; }
L_20d2068: r0 = r4;
L_20d206c: r0 = func_020d1a98(r0);
L_20d2074: return r0;
L_20d2078: r0 = r4;
L_20d207c: r0 = func_020d18d4(r0);
L_20d2084: return r0;
}
