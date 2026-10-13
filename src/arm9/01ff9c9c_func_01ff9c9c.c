/* High-level C; whole-function bytes verified with Zig 0.14.1 Clang.
 * Zero relocations; whole-ROM linking remains unverified. */
void func_01ff9c9c(unsigned int p0, unsigned int p1)
{
    p1 &= 0x1000000u; if (p1 != *(const unsigned int *)(p0 + 0x4c0u)) *(unsigned int *)(p0 + 0x4c0u) = p1;
}
