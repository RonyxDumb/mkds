void BillboardModel_SomeFn(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 16)))&(0x8000ffffu)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 16)))|(0x294a0000u)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 20)))&~(0x3f000000u)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 20)))|(0x3f000000u)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 20)))&~(0xfu)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 20)))|(0x2u)));
}
