/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define MultiStore16 Mem_CpuFill16
void MultiStore16(unsigned short val, char *dst, int nbytes) {
    int i = 0;
    do {
        if (i < nbytes) {
            *(unsigned short*)(dst + i) = val;
            i += 2;
        } else break;
    } while (1);
}
