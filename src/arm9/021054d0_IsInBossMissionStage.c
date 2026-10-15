/* C reconstructed from original ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
/* Only the observed fields are named; the remaining layout is padding. */
typedef struct {
    int padding_00[2];
    int mode;                       /* 0x08 */
    int player_mode;                /* 0x0c */
    char padding_10[0x44];
    signed char level;              /* 0x54 */
    signed char stage;              /* 0x55 */
    char padding_56[12];
    signed char player;             /* 0x62 */
    unsigned char network_player;   /* 0x63 */
} RaceConfig;

int IsInBossMissionStage(void)
{
    RaceConfig *config = *(RaceConfig **)0x021759c0;
    int result = 0;
    if (config->mode != 4)
        return result;
    if ((config->mode == 4 ? config->stage : -1) == 9)
        result = 1;
    return result;
}
