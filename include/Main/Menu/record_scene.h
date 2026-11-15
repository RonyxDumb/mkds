#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void UpdateRecordScene(SceneNumbers *sceneNumbers);
void *GetRecordMainOam(void);
void *GetRecordSubOam(void);

void WriteRecordSceneRegistersCallback(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseRecordScene(void);

void InitRecordScene(s16 *sceneNumbers);

extern struct OamEntryList *gRecordSubOam;
extern struct OamEntryList *gRecordMainOam;

// Record screen file names (graphics of the Grand Prix, time trial, top menu and trophy screens).
extern const char *gRecordGpxSONclrName;
extern const char *gRecordGpxMBNcgrName;
extern const char *gRecordGpxSNcerName;
extern const char *gRecordTAttSONclrName;
extern const char *gRecordTAttMBnllName;
extern const char *gRecordGpxSBnclName;
extern const char *gRecordGpxMBnllName;
extern const char *gRecordTAttMBnclName;
extern const char *gRecordTopMenuSBnclName;
extern const char *gRecordTAttSBnllName;
extern const char *gRecordTAttMNcerName;
extern const char *gRecordGpxSNcgrName;
extern const char *gRecordGpxMNcgrName;
extern const char *gRecordGpxMNscrName;
extern const char *gRecordTopMenuSBnblName;
extern const char *gRecordGpxMBnclName;
extern const char *gRecordTAttMNcgrName;
extern const char *gRecordTopMenuSNcerName;
extern const char *gRecordGpxSBnllName;
extern const char *gRecordTopMenuSNcgrName;
extern const char *gRecordTrophySONclrName;
extern const char *gRecordGpxSBNclrName;
extern const char *gRecordTAttSNcgrName;
extern const char *gRecordTAttSNcerName;
extern const char *gRecordGpxMBNclrName;
extern const char *gRecordTAttMONclrName;
extern const char *gRecordGpxMNcerName;
extern const char *gRecordTAttSNscrName;
extern const char *gRecordTrophySOBnclName;
extern const char *gRecordTopMenuMBnclName;
extern const char *gRecordTopMenuMNcgrName;
extern const char *gRecordTAttSBNclrName;
extern const char *gRecordTopMenuMBNclrName;
extern const char *gRecordGpxMONclrName;
extern const char *gRecordTopMenuSONclrName;
extern const char *gRecordTopMenuMONclrName;
extern const char *gRecordGpxSNscrName;
extern const char *gRecordTAttMBNclrName;
extern const char *gRecordTAttSBnclName;
extern const char *gRecordTAttSBnblName;
extern const char *gRecordTopMenuMBnllName;
extern const char *gRecordTAttMScoreNscrName;
extern const char *gRecordTopMenuMNscrName;
extern const char *gRecordGpxSBNcgrName;
extern const char *gRecordTrophyONcgrName;
extern const char *gRecordTAttMNscrName;
extern const char *gRecordTAttSBNcgrName;
extern const char *gRecordTopMenuMBNcgrName;
extern const char *gRecordTrophyONcerName;
extern const char *gRecordTAttMBNcgrName;
extern const char *gRecordTopMenuMNcerName;
extern const char *gRecordGpxSBnblName;
