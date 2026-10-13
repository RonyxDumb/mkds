unsigned int func_02028010(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x400100eu) + 0));
    *(unsigned short *)((unsigned char *)(unsigned int)(0x400100eu) + 0) = (unsigned short)(((((load_0)&~(0x3u)))|(p0)));
    return ((((load_0)&~(0x3u)))|(p0));
}
