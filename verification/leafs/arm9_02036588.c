void ExecutionContext_SetFunction(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(p1);
}
