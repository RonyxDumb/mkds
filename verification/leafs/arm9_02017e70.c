unsigned int Mem_Exp_InitializeMemoryBlock(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0));
    *(unsigned short *)((unsigned char *)(unsigned int)(load_0) + 0) = (unsigned short)(p1);
    *(unsigned short *)((unsigned char *)(unsigned int)(load_0) + 2) = (unsigned short)(0x0u);
    unsigned int load_3 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 4));
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 4) = (unsigned int)(((load_3)-(((load_0)+(0x10u)))));
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 8) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 12) = (unsigned int)(0x0u);
    return load_0;
}
