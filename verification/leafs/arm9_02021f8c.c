void Gfx_MakePaletteOffsetsAbsolute(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 12)))+(p0)));
}
