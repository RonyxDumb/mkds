unsigned int VecFx32_Add(unsigned int p0, unsigned int p1, unsigned int p2)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p1) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 0) = (unsigned int)(((load_0)+(load_1)));
    unsigned int load_3 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 4));
    unsigned int load_4 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p1) + 4));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 4) = (unsigned int)(((load_3)+(load_4)));
    unsigned int load_6 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 8));
    unsigned int load_7 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p1) + 8));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 8) = (unsigned int)(((load_6)+(load_7)));
    return ((load_6)+(load_7));
}
