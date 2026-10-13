/* High-level C; whole-function bytes verified with Zig 0.14.1 Clang.
 * Zero relocations; whole-ROM linking remains unverified. */
unsigned int func_020204b4(unsigned int p0)
{
    return p0 == 255u ? 254u : p0;
}
