#include "Main/Menu/record_scene.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/System/heap.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/oam_lists.h"

#include "Main/Menu/record_vs.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/heap_call.h"

static char sRecordTAttMBnllName[] = "Record_T_att_m.bnll";
static char sRecordGpxSBNcgrName[] = "Record_Gpx_s_b.ncgr";
static char sRecordTAttSONclrName[] = "Record_T_att_s_o.nclr";
static char sRecordTAttSBNcgrName[] = "Record_T_att_s_b.ncgr";
static char sRecordTAttSBnclName[] = "Record_T_att_s.bncl";
static char sRecordGpxMNscrName[] = "Record_Gpx_m.nscr";
static char sRecordGpxSBnblName[] = "Record_Gpx_s.bnbl";
static char sRecordTAttMNscrName[] = "Record_T_att_m.nscr";
static char sRecordTopMenuMNscrName[] = "Record_top_menu_m.nscr";
static char sRecordTAttSNscrName[] = "Record_T_att_s.nscr";
static char sRecordTAttSNcgrName[] = "Record_T_att_s.nce.ncgr";
static char sRecordTAttMBNcgrName[] = "Record_T_att_m_b.ncgr";
static char sRecordTAttMBNclrName[] = "Record_T_att_m_b.nclr";
static char sRecordGpxSBnllName[] = "Record_Gpx_s.bnll";
static char sRecordTopMenuMBnclName[] = "Record_top_menu_m.bncl";
static char sRecordGpxSNscrName[] = "Record_Gpx_s.nscr";
static char sRecordTAttMNcgrName[] = "Record_T_att_m.nce.ncgr";
static char sRecordTopMenuMNcerName[] = "Record_top_menu_m.nce.ncer";
static char sRecordGpxMBnclName[] = "Record_Gpx_m.bncl";
static char sRecordTopMenuSNcgrName[] = "Record_top_menu_s.nce.ncgr";
static char sRecordTopMenuMBnllName[] = "Record_top_menu_m.bnll";
static char sRecordGpxSBNclrName[] = "Record_Gpx_s_b.nclr";
static char sRecordTAttMNcerName[] = "Record_T_att_m.nce.ncer";
static char sRecordTAttSNcerName[] = "Record_T_att_s.nce.ncer";
static char sRecordTAttSBnblName[] = "Record_T_att_s.bnbl";
static char sRecordTAttSBNclrName[] = "Record_T_att_s_b.nclr";
static char sRecordGpxMNcgrName[] = "Record_Gpx_m.nce.ncgr";
static char sRecordGpxMONclrName[] = "Record_Gpx_m_o.nclr";
static char sRecordTopMenuSBnclName[] = "Record_top_menu_s.bncl";
static char sRecordTrophySONclrName[] = "Record_trophy_s_o.nclr";
static char sRecordTopMenuSNcerName[] = "Record_top_menu_s.nce.ncer";
static char sRecordGpxMNcerName[] = "Record_Gpx_m.nce.ncer";
static char sRecordTrophyONcgrName[] = "Record_trophy_o.nce.ncgr";
static char sRecordTAttSBnllName[] = "Record_T_att_s.bnll";
static char sRecordTrophyONcerName[] = "Record_trophy_o.nce.ncer";
static char sRecordTopMenuSONclrName[] = "Record_top_menu_s_o.nclr";
static char sRecordGpxMBnllName[] = "Record_Gpx_m.bnll";
static char sRecordTAttMONclrName[] = "Record_T_att_m_o.nclr";
static char sRecordGpxMBNcgrName[] = "Record_Gpx_m_b.ncgr";
static char sRecordGpxMBNclrName[] = "Record_Gpx_m_b.nclr";
static char sRecordTopMenuSBnblName[] = "Record_top_menu_s.bnbl";
static char sRecordTAttMScoreNscrName[] = "Record_T_att_m_score.nscr";
static char sRecordTrophySOBnclName[] = "Record_trophy_s_o.bncl";
static char sRecordTAttMBnclName[] = "Record_T_att_m.bncl";
static char sRecordTopMenuMBNcgrName[] = "Record_top_menu_m_b.ncgr";
static char sRecordGpxSONclrName[] = "Record_Gpx_s_o.nclr";
static char sRecordGpxSNcgrName[] = "Record_Gpx_s.nce.ncgr";
static char sRecordTopMenuMBNclrName[] = "Record_top_menu_m_b.nclr";
static char sRecordTopMenuMONclrName[] = "Record_top_menu_m_o.nclr";
static char sRecordGpxSNcerName[] = "Record_Gpx_s.nce.ncer";
static char sRecordTopMenuMNcgrName[] = "Record_top_menu_m.nce.ncgr";
static char sRecordGpxSBnclName[] = "Record_Gpx_s.bncl";
const char *gRecordTopMenuMNcerName = sRecordTopMenuMNcerName;
const char *gRecordTopMenuMBnllName = sRecordTopMenuMBnllName;
const char *gRecordTAttMONclrName = sRecordTAttMONclrName;
const char *gRecordTopMenuSONclrName = sRecordTopMenuSONclrName;
const char *gRecordTAttSBnblName = sRecordTAttSBnblName;
const char *gRecordGpxMNcgrName = sRecordGpxMNcgrName;
const char *gRecordTAttMBNclrName = sRecordTAttMBNclrName;
const char *gRecordTAttSBNclrName = sRecordTAttSBNclrName;
const char *gRecordGpxSNscrName = sRecordGpxSNscrName;
const char *gRecordTopMenuMNcgrName = sRecordTopMenuMNcgrName;
const char *gRecordGpxSBNcgrName = sRecordGpxSBNcgrName;
const char *gRecordTAttMNcgrName = sRecordTAttMNcgrName;
const char *gRecordGpxSBnllName = sRecordGpxSBnllName;
const char *gRecordTopMenuMNscrName = sRecordTopMenuMNscrName;
const char *gRecordTopMenuSBnblName = sRecordTopMenuSBnblName;
const char *gRecordTAttSNscrName = sRecordTAttSNscrName;
const char *gRecordTAttSBNcgrName = sRecordTAttSBNcgrName;
const char *gRecordTAttMBnclName = sRecordTAttMBnclName;
const char *gRecordTopMenuSBnclName = sRecordTopMenuSBnclName;
const char *gRecordTrophySONclrName = sRecordTrophySONclrName;
const char *gRecordTAttSNcerName = sRecordTAttSNcerName;
const char *gRecordTAttMNcerName = sRecordTAttMNcerName;
const char *gRecordGpxMNscrName = sRecordGpxMNscrName;
const char *gRecordGpxSNcerName = sRecordGpxSNcerName;
const char *gRecordTAttSBnllName = sRecordTAttSBnllName;
const char *gRecordGpxSONclrName = sRecordGpxSONclrName;
const char *gRecordGpxMBNcgrName = sRecordGpxMBNcgrName;
const char *gRecordGpxSBnblName = sRecordGpxSBnblName;
const char *gRecordGpxMBNclrName = sRecordGpxMBNclrName;
const char *gRecordTAttSNcgrName = sRecordTAttSNcgrName;
const char *gRecordTopMenuMBNcgrName = sRecordTopMenuMBNcgrName;
const char *gRecordTAttMNscrName = sRecordTAttMNscrName;
const char *gRecordTAttSBnclName = sRecordTAttSBnclName;
const char *gRecordTAttMBNcgrName = sRecordTAttMBNcgrName;
const char *gRecordTAttMScoreNscrName = sRecordTAttMScoreNscrName;
const char *gRecordTrophySOBnclName = sRecordTrophySOBnclName;
const char *gRecordGpxMBnclName = sRecordGpxMBnclName;
const char *gRecordGpxMBnllName = sRecordGpxMBnllName;
const char *gRecordGpxSBnclName = sRecordGpxSBnclName;
const char *gRecordGpxSNcgrName = sRecordGpxSNcgrName;
const char *gRecordTAttMBnllName = sRecordTAttMBnllName;
const char *gRecordTrophyONcerName = sRecordTrophyONcerName;
const char *gRecordGpxSBNclrName = sRecordGpxSBNclrName;
const char *gRecordGpxMONclrName = sRecordGpxMONclrName;
const char *gRecordTopMenuMBNclrName = sRecordTopMenuMBNclrName;
const char *gRecordTopMenuMONclrName = sRecordTopMenuMONclrName;
const char *gRecordTopMenuMBnclName = sRecordTopMenuMBnclName;
const char *gRecordTAttSONclrName = sRecordTAttSONclrName;
const char *gRecordTrophyONcgrName = sRecordTrophyONcgrName;
const char *gRecordTopMenuSNcgrName = sRecordTopMenuSNcgrName;
const char *gRecordTopMenuSNcerName = sRecordTopMenuSNcerName;
const char *gRecordGpxMNcerName = sRecordGpxMNcerName;
OamEntryList *gRecordSubOam;
OamEntryList *gRecordMainOam;

#pragma thumb on

void InitRecordScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gRecordMainOam = HeapAlloc(heap, sizeof(*gRecordMainOam));
    gRecordSubOam = HeapAlloc(heap, sizeof(*gRecordSubOam));
    InitRecordSceneObject(heap, *sceneNumbers);
}

#pragma thumb off

#pragma thumb on
void ReleaseRecordScene(void) {
    ReleaseRecordSceneObject();
    gRecordMainOam = NULL;
    gRecordSubOam = NULL;
}
#pragma thumb off

#pragma thumb on
void WriteRecordSceneRegistersCallback(void) {
    WriteRecordSceneRegisters();
    UploadOamLists(gRecordMainOam, gRecordSubOam);
}
#pragma thumb off

#pragma thumb on

void UpdateRecordScene(SceneNumbers *sceneNumbers) {
    ClearOamListCounts(gRecordMainOam, gRecordSubOam);
    AdvanceRecordScene();
    HideUnusedOams(gRecordMainOam, gRecordSubOam);
    if (sceneNumbers != NULL && GetRecordNextScene() != -1) {
        sceneNumbers->mNextScene = GetRecordNextScene();
    }
}

void *GetRecordMainOam(void) {
    return gRecordMainOam;
}

void *GetRecordSubOam(void) {
    return gRecordSubOam;
}

#pragma thumb off
