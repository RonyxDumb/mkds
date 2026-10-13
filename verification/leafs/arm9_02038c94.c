void DisplayConfig_SetBottomEngineObjVramModeBmp(unsigned int p0, unsigned int p1)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 178) = (unsigned short)(p1);
}
