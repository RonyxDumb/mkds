void Animation_SetLoop(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 32))) + 0 + (((p1) << 2))) = (unsigned int)(p2);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned short)(p2);
}
