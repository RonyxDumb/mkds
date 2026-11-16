#pragma once

#include "types.h"

void *arc_getKartModelArcFileCopy(const char *path);
void *arc_getKartModelArcFile(const char *path);
void *arc_getCourseArcFile(const char *path);
void *arc_getSceneArcFile(const char *name);
void *arc_getMainRaceMainEffectArcFile(const char *path);
void *arc_getArchiveFile(u32 archiveName, const char *path);

// 0x18-byte entries.
typedef struct ArchiveSlotInfo {
    /* 00 */ const char *mPath;
    /* 04 */ s32 mNextSlot;
    /* 08 */ s8 mBufferIndex;
    /* 09 */ u8 field9[0x3];
    /* 0c */ s32 mUncompressSource;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
} ArchiveSlotInfo;

// 8-byte entries of a string and a number.
typedef struct SceneName {
    /* 00 */ const char *mName;
    /* 04 */ s32 field4;
} SceneName;

#include "Main/Unknown/unk_02175000.h"

// The scene-name table, 16 rows indexed by scene number like scproc_sSceneTable: 0 'Title', 1 'Menu', 2 'Race', 3 'Emblem',
// 4 'Menu', 5 'Test', 6 'WLMenu', 7 'Option', 8 'Record', 9 'Logo', 10 'Result', 11 'Nickname', 12 'WiFiMenu',
// 13 'Ghost', 14 'Keyboard', 15 'Ending'.
extern SceneName sSceneDefs[];
extern ArchiveSlotInfo sArcDefs[];
extern const char aSS_0[];
extern const char aSS_1[];
extern const char aSS_2[];
extern const char aSS_3[];
extern const char aSS_4[];
extern const char aSS_5[];
extern const char aSS_6[];
extern const char aSS_7[];
extern const char aDataSceneStaff[];
extern const char aDl_0[];
extern const char g_EmptyString_1[];
extern const char aDataSceneSS_SS[];
extern const char a_carc_2[];
extern const char aDl[];
extern const char g_EmptyString_2[];
extern const char aDataSceneSSS[];
extern const char a_carc_3[];

void spi_init(void *heap);
void spi_initTouch(void);
void arc_loadStatic2D(void *heap);
void arc_resizeMainEffectArc(u8 *a, u32 b);
s32 arc_isCourseTexAvailable(void);
void arc_2047274(void);
void RequestResultDLArchives(void);
void RequestRaceArchives(void *courseId, void *b);
void RequestMenuDLArchives(void);
void func_020473e4(void);
void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex);
void RequestArchiveLoad(const void *path, s32 bufferIndex);
void func_020474e4(void);
void InitArchiveBuffers(NNSiFndHeapHead *a, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *c);
void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 c, u32 uncompress, u32 e);
void func_020476ac(void);
void arc_switchCourseTexToSceneRace(void);
void arc_switchKartModelBSubToCourse(void);
void arc_switchKartModelMainAtoB(void);
void *arc_getKartModelArcFileSafe(const char *path);
void *arc_get2dArcFile(const char *name);
void arc_setHeapGroupId(u32 groupId);
void arc_unloadAllArchives(void);
void arc_loadArchivesForScene(s32 sceneNumber);
void arc_unloadArchive(int slotIndex);
void arc_mountArchive(void);
void arc_loadArchiveFromMem(void);
void arc_loadArchiveFromFile(void);
void arc_loadArchive(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 e, s32 uncompressSource, s32 g);
void arc_loadArchiveForScene(int slotIndex, int sceneNumber);
void arc_getLocalizedArcPath(const char *prefix, char *path);
void arc_getLocalizedRaceSceneArcPath(char *path, const char *sceneName, int mode);
void arc_getRaceSceneArcPath(char *path, const char *sceneName, int mode);
void arc_getLocalizedStaffrollSceneArcPath(char *path);
void arc_getLocalizedResultSceneArcPath(char *path);
void arc_getResultSceneArcPath(char *path);
