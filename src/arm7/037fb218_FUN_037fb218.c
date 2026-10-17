/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define MultiStore16 FUN_037fb218
void MultiStore16(unsigned short val, char *dst, int nbytes) {
    int i = 0;
    do {
        if (i < nbytes) {
            *(unsigned short*)(dst + i) = val;
            i += 2;
        } else break;
    } while (1);
}
