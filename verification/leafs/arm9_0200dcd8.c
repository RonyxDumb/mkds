unsigned int Os_Thread_GetPriority(unsigned int p0)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 112));
}
