/* High-level C; whole-function bytes verified with Zig 0.14.1 Clang.
 * Zero relocations; whole-ROM linking remains unverified. */
void func_020c0b84(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0))) + 0) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0))) + 12) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0))) + 16) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(0x0u);
}
