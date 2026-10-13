unsigned int E7FnList4_Fn10(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa14u) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x700u))) + 92));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x700u))) + 92) = (unsigned short)(((load_1)&~(0x100u)));
    return ((load_0)+(0x700u));
}
