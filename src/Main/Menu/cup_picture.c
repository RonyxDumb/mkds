#include "Main/Menu/cup_picture.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/System/thread_function_queue_run.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_goal_times.h"

#pragma optimize_for_size on

#pragma thumb on
char gCupPictureRetro[6] = "retro";
char gCupPictureNitro[6] = "nitro";
char gCupPicturePrefix[29] = "/data/CupPicture/select_cup_";

BOOL IsCupPictureReady(void) {
    if (gCupPicture != NULL && GetThreadFunctionQueueRunRequested() == 0) {
        return TRUE;
    }
    return FALSE;
}

void *GetCupPictureNclrData(void) {
    if (IsCupPictureReady() != FALSE) {
        return gCupPicture->mCupPictureNclr->mData;
    }
    return NULL;
}

void *GetCupPictureNcgrData(void) {
    if (IsCupPictureReady() != FALSE) {
        return gCupPicture->mCupPictureNcgr->mData;
    }
    return NULL;
}

void *GetCupPictureNscrData(void) {
    if (IsCupPictureReady() != FALSE) {
        return &gCupPicture->mCupPictureNscr->mData;
    }
    return NULL;
}
#pragma thumb off

s32 CreateRaceHudSubScreenFireball2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenFireball2Cells, MAP_OBJECT_KIND_FIREBALL2);
}
