void Mem_SetWramcnt(unsigned int p0)
{
    *(unsigned char *)((unsigned char *)(unsigned int)(0x4000247u) + 0) = (unsigned char)(p0);
}
