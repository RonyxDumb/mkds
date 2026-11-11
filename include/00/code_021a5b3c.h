#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "code_02142eac.h"
#include "00/code_02188de4.h"
#include "00/code_021a4b98.h"


// 0xc0 bytes; WCM_ConnectAsync copies one to mUnk_2140 of an WCMWork, WCMi_EntryApList to a list entry.
typedef struct Unk021a5e84 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 mUnk_04[0x38];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u8 mUnk_3e[0x82];
} Unk021a5e84;

u32 WCM_UpdateOption(u32 option);
s32 WCM_TerminateAsync(void);
s32 WCM_ConnectAsync(Unk021a5e84 *bssDesc, WCMWepDesc *wepDesc, u32 option);
s32 WCM_BeginSearchAsync(const void *bssid, const u8 *essid, u32 option);
s32 WCM_SearchAsync(const void *bssid, const u8 *essid, u32 option);
s32 WCM_StartupAsync(WCMConfig *config, void (*notify)(WCMNotice *));
BOOL WCM_Finish(void);
s32 WCM_Init(WCMWork *buf, u32 len);
void WcmAppendApList(WCMApList *aplist);
WCMApList *WcmSearchIndexedApList(u32 index);
WCMApList *WcmSearchApList(const u8 *bssid);
