
unsigned int G2d_Sprite_CreateImpl(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8)
{
unsigned int cmp_a,cmp_b;
L_2023510: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r2;
L_2023514: r2 = a4;
L_2023518: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r3;
L_202351c: *(unsigned char *)((unsigned char *)r0 + 12) = (unsigned char)r2;
L_2023520: r2 = a5;
L_2023524: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_2023528: r1 = a6;
L_202352c: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r2;
L_2023530: r2 = a7;
L_2023534: *(unsigned int *)((unsigned char *)r0 + 24) = (unsigned int)r1;
L_2023538: r1 = a8;
L_202353c: *(unsigned int *)((unsigned char *)r0 + 28) = (unsigned int)r2;
L_2023540: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)r1;
L_2023544: return r0;
}
