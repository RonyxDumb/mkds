#include "03/Graphics/hl_scr.h"
#include "03/code_021bf000.h"
#include "03/Net/essid_packet_steps.h"
#include "03/code_021cd2e0.h"
#include "03/System/dwc_archive.h"
#include "03/unk_021d5000.h"
#include "03/Menu/menu_pair_loading.h"

#include "03/System/tasks.h"
#include "os_thread.h"
#include "code_0200eddc.h"
#include "gx_load2d.h"
#include "03/code_021d1000.h"
#include "code_0214d018.h"
#include "03/System/exp_heap.h"
#include "03/unk_021d67d8.h"
#include "03/System/application.h"

void *gHlNscNames[20] = {
    gJb2HlWiFiNscName, gJb2HlApNscName,     gJb3HlList1NscName, gJb3HlList2NscName,   gJb3HlList3NscName,
    gJb4HlSet1NscName, gJb4HlSet2NscName,   gJb4HlSet3NscName,  gJb4HlUsbNscName,     gJb4HlSsidNscName,
    gJb4HlWepNscName,  gJb4HlIpNscName,     gJb4HlMaskNscName,  gJb4HlGatewayNscName, gJb4HlDns0NscName,
    gJb4HlDns1NscName, gJb5HlOptionNscName, gJb5HlInfoNscName,  gJb5HlEraseNscName,   gJb5HlMoveNscName,
};
char gJb4HlGatewayNscName[24] = "char/jb4HlGateway.nsc.l";
char gJb5HlOptionNscName[23] = "char/jb5HlOption.nsc.l";
char gJb3HlList1NscName[22] = "char/jb3HlList1.nsc.l";
char gJb3HlList2NscName[22] = "char/jb3HlList2.nsc.l";
char gJb3HlList3NscName[22] = "char/jb3HlList3.nsc.l";
char gJb5HlEraseNscName[22] = "char/jb5HlErase.nsc.l";
char gJb4HlSet3NscName[21] = "char/jb4HlSet3.nsc.l";
char gJb4HlDns0NscName[21] = "char/jb4HlDns0.nsc.l";
char gJb4HlSet2NscName[21] = "char/jb4HlSet2.nsc.l";
char gJb4HlSsidNscName[21] = "char/jb4HlSsid.nsc.l";
char gJb2HlWiFiNscName[21] = "char/jb2HlWiFi.nsc.l";
char gJb5HlInfoNscName[21] = "char/jb5HlInfo.nsc.l";
char gJb4HlMaskNscName[21] = "char/jb4HlMask.nsc.l";
char gJb4HlSet1NscName[21] = "char/jb4HlSet1.nsc.l";
char gJb4HlDns1NscName[21] = "char/jb4HlDns1.nsc.l";
char gJb5HlMoveNscName[21] = "char/jb5HlMove.nsc.l";
char gJb4HlWepNscName[20] = "char/jb4HlWep.nsc.l";
char gJb4HlUsbNscName[20] = "char/jb4HlUsb.nsc.l";
char gJb4HlIpNscName[19] = "char/jb4HlIp.nsc.l";
char gJb2HlApNscName[19] = "char/jb2HlAp.nsc.l";
void *gHlScr;

void InitHlScr(void) {
    gHlScr = AllocExpHeapBlock(0xc0, 4);
    LoadFileToVram("char/jbBgHl.ncg.l", GX_LoadBG1Char);
    switch (GetMode()) {
        case 0:
            LoadFileToVram(gHlNscNames[0], GX_LoadBG1Scr);
            break;
        case 1:
            LoadFileToVram(gHlNscNames[1], GX_LoadBG1Scr);
            break;
    }
}

void ReleaseHlScr(void) {
    FreeExpHeapBlockAndClearPointer(&gHlScr);
}

void LoadHlScr(int scrIndex) {
    void *file;

    file = LoadFile(BuildFilePathWithLanguage(gHlNscNames[scrIndex]), NULL, 4);
    MIi_CpuCopyFast(file, gHlScr, 0xc0);
    DeleteLoadedFile(file);
    AddTask(1, UploadHlScr, NULL, 0x78);
}

void LoadHlSetScr(void) {
    u32 scrIndex;
    scrIndex = GetApWorkCopy()->mEntryIndex;
    scrIndex = (scrIndex) + (5u);
    LoadHlScr(scrIndex);
}

void LoadHlListScr(void) {
    u32 scrIndex;
    scrIndex = GetApWorkCopy()->mEntryIndex;
    scrIndex = (scrIndex) + (2u);
    LoadHlScr(scrIndex);
}

void UploadHlScr(TaskEntry *entry, void *arg) {
    DC_FlushRange(gHlScr, 0xc0);
    GX_LoadBG1Scr(gHlScr, 0, 0xc0);
    RequestTaskRemoval(1, entry);
}
