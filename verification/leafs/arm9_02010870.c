void Tex0Block_SetPaletteVramKey(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 44) = (unsigned int)(p1);
}
