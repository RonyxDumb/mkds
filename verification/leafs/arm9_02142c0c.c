unsigned int SetSomeFunctionPtr(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217eed4u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(((load_0)+(((p0) << 2)))) + 24) = (unsigned int)(p1);
    return ((load_0)+(((p0) << 2)));
}
