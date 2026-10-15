/* Exact Thumb reconstruction from reference instructions; local bytes verified.
 * Four race-option entry pointers are cleared. Global ABI remains unverified. */
extern unsigned char *Menu_RaceOptionBase;

void ClearRaceOptionMenuEntries_from_thumb(void)
{
    int i = 0;
    do {
        *(unsigned *)(Menu_RaceOptionBase + i * 28 + 0x50) = 0;
        i++;
    } while (i < 4);
}
