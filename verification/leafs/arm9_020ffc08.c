
unsigned int func_020ffc08(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20ffc08: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 166));
L_20ffc0c: ip = (r0+0xa6u);
L_20ffc10: r1 = (r1+0x96u);
L_20ffc14: *(unsigned short *)((unsigned char *)r0 + 166) = (unsigned short)r1;
L_20ffc18: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 188));
L_20ffc1c: r1 = (r1-0x96u);
L_20ffc20: *(unsigned int *)((unsigned char *)r0 + 188) = (unsigned int)r1;
L_20ffc24: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 188));
L_20ffc28: cmp_a = r3; cmp_b = 0x0u;
L_20ffc2c: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20ffc30: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)ip + 0));
L_20ffc34: r1 = 0x1u;
L_20ffc38: r2 = (r2+r3);
L_20ffc3c: *(unsigned short *)((unsigned char *)ip + 0) = (unsigned short)r2;
L_20ffc40: *(unsigned short *)((unsigned char *)r0 + 144) = (unsigned short)r1;
L_20ffc44: *(unsigned short *)((unsigned char *)r0 + 146) = (unsigned short)r1;
L_20ffc48: return r0;
}
