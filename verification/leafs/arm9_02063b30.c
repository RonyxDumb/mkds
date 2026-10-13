unsigned int StructMQRacerEntry_GetVec555(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((p0)+(0x120u))) + 12));
    *(unsigned int *)((unsigned char *)(unsigned int)(p1) + 0) = (unsigned int)(load_0);
    unsigned int load_2 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((p0)+(0x120u))) + 16));
    *(unsigned int *)((unsigned char *)(unsigned int)(p1) + 4) = (unsigned int)(load_2);
    unsigned int load_4 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((p0)+(0x120u))) + 20));
    *(unsigned int *)((unsigned char *)(unsigned int)(p1) + 8) = (unsigned int)(load_4);
    return load_4;
}
