
unsigned int G3X_SetClearColor(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4)
{
unsigned int cmp_a,cmp_b,ip;
L_214a700: r0 = (r0|(r1 << 16));
L_214a704: ip = a4;
L_214a708: r3 = (r0|(r3 << 24));
L_214a70c: cmp_a = ip; cmp_b = 0x0u;
L_214a710: r1 = 0x4000350u;
L_214a714: if ((cmp_a != cmp_b)) { r3 = (r3|0x8000u); }
L_214a718: r0 = 0x4000354u;
L_214a71c: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r3;
L_214a720: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r2;
L_214a724: return r0;
}
