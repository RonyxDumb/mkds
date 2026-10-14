/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_02055490 G3X_GetMtxStackLevelPV
int func_02055490(int *out) {
    if (*(volatile unsigned int *)0x4000600 & 0x4000)
        return -1;
    *out = (*(volatile unsigned int *)0x4000600 & 0x1f00) >> 8;
    return 0;
}
