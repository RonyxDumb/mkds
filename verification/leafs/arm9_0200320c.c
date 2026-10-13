unsigned int Fs_File_DefaultOperation_OpenFileRaw(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 36) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 48)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 44) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 48)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 40) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 52)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 32) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 56)));
    return 0x0u;
}
