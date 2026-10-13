unsigned int dtor_fn(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 140) = (unsigned int)(0x0u);
    return 0x0u;
}
