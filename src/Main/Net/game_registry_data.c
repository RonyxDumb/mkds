#include "Main/Net/game_registry_data.h"

#pragma explicit_zero_data on
char gGameRegistryRomPath[] = "";
char gGameRegistryGameName[] = "";
char gGameRegistryIntroduction[] = "";
#pragma explicit_zero_data off
char gGameRegistryIconCharPath[] = "/data/boot/mkds_banner02.nbfc";
char gGameRegistryIconPalettePath[] = "/data/boot/mkds_banner02.nbfp";

void *const g_GlobalBAN[15] = {gGameRegistryRomPath,
                                 gGameRegistryGameName,
                                 gGameRegistryIntroduction,
                                 gGameRegistryIconCharPath,
                                 gGameRegistryIconPalettePath,
                                 (void *) 0x25,
                                 (void *) 8,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL,
                                 NULL};
