void FriendCode_SetCrcChecksum_from_thumb(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(p1);
}
