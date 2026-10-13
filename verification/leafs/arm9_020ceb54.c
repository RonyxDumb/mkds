unsigned int GXS_SetGraphicsMode__mkds_ceb54(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0) = (unsigned int)(((((load_0)&~(0x1f00u)))|(((p0) << 8))));
    return ((((load_0)&~(0x1f00u)))|(((p0) << 8)));
}
