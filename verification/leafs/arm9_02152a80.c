void FriendCode_SetFriendCodeValues_from_thumb(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(p2);
}
