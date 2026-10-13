unsigned int func_020107e4(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 50));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 50) = (unsigned short)(((load_0)&~(0x1u)));
    unsigned int load_2 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 44));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 44) = (unsigned int)(0x0u);
    return load_2;
}
