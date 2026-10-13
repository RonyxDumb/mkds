void IntrusiveListWrapper_InitializeEmpty(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned short)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 10) = (unsigned short)(p1);
}
