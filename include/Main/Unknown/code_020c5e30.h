#pragma once

#include "types.h"
#include "Main/Unknown/code_02056b30.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// Time-attack record handling of the race (mode 1 only), one record behind r2dtar_sStatus (0xe8 bytes, allocated by
// r2dtar_init, set NULL by r2dtar_finalize): mUnk_00 is the function it runs every frame
// (r2dtar_update), which compares the finished run with the course's saved records, inserts and saves a new one
// (savd_setNktaEntry) and slides in and draws the new-record page (r2dtar_render).
typedef struct RaceNewRecordTa {
    /* 00 */ void (*mUpdate)(void);
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mFinishTimeIsRecord;
    /* 0c */ s32 mFinishRecordIndex;
    /* 10 */ s32 mBestLapIsRecord;
    /* 14 */ u16 mBestLapNumber;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18;
    // The course's six time records, copied from the save by r2dtar_init (savd_getNktaEntry): slots 0..4 are
    // the ranked list (an insert shifts them down and writes through savd_setNktaEntry), slot 5 is a further record
    // shown in a sixth row: the best lap time.
    /* 1c */ TimeRecord mRecords[6];
    /* dc */ s32 mUnk_dc;
    // X of the whole page: -0x100 at allocation, eased to 0 over 0x14 frames by SlideInRaceNewRecordTa, added to every
    // sprite and row x in the draw.
    /* e0 */ s32 mOffsetX;
    /* e4 */ s32 mCycleFrames;
} RaceNewRecordTa;

s32 r2dtar_isSaving(void);
s32 func_020c70a0(void);
void r2dtar_init(void);
void r2dtar_finalize(void);
void r2dtar_update(void);
void DrawRaceNewRecordTaTime(RaceHudOamBuffer *oamBuffer, s32 x, s32 y, TimeRecord *record);
void DrawRaceNewRecordTaRow(RaceHudOamBuffer *oamBuffer, s32 b, s32 x, s32 y);
void r2dtar_render(RaceHudOamBuffer *oamBuffer);
BOOL r2dtar_20C657C(s32 store);
BOOL r2dtar_20C6428(s32 store);
void r2dtar_20C610C(void);
void func_020c5f7c(void);
void func_020c5f08(void);
void ShowRaceNewRecordTaSubScreen(void);
void SlideInRaceNewRecordTa(void);
