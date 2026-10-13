void Os_Thread_SetDestructor(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 180) = (unsigned int)(p1);
}
