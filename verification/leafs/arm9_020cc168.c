unsigned int SetSubDispcntTileObjMappingRemoveBoundary(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0) = (unsigned int)(((((load_0)&(0xffcfffefu)))|(p0)));
    return ((((load_0)&(0xffcfffefu)))|(p0));
}
