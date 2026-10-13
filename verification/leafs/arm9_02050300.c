unsigned int func_02050300(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa00u) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x400u))) + 84));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x400u))) + 84) = (unsigned short)(((load_1)|(0x1u)));
    return ((load_0)+(0x400u));
}
