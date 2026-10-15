/* C reconstructed from original ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
typedef struct {
    int padding_00[5];
    int status;                    /* 0x14 */
    char padding_18[0x74];
} Racer;                          /* stride 0x8c */

int IsRacerFinishStatus4(int id)
{
    Racer *racers = *(Racer **)0x0217561c;
    return racers[id].status == 4;
}
