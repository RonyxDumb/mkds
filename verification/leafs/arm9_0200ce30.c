unsigned int SetCartOwnerArm7(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x4000204u) + 0));
    *(unsigned short *)((unsigned char *)(unsigned int)(0x4000204u) + 0) = (unsigned short)(((load_0)|(0x80u)));
    return ((load_0)|(0x80u));
}
