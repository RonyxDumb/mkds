/* High-level C; whole-function bytes verified with Zig 0.14.1 Clang.
 * Zero relocations; whole-ROM linking remains unverified. */
void Tex0Block_SetTexturesVramKeys(unsigned int p0, unsigned int p1, unsigned int p2)
{
    if (p1) *(unsigned int *)(p0 + 8u) = p1; if (p2) *(unsigned int *)(p0 + 0x18u) = p2;
}
