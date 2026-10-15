/* C reconstructed from original ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
extern int GetCurrentMissionLevel_0(void);
extern int GetCurrentMissionLevelStage_0(void);

int IsCurrentMission_Boss6OrBoss7_from_thumb(void)
{
    return (GetCurrentMissionLevel_0() == 6 && GetCurrentMissionLevelStage_0() == 9)
        || (GetCurrentMissionLevel_0() == 7 && GetCurrentMissionLevelStage_0() == 9);
}
