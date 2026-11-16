#pragma once

#include "types.h"

void SPM_2077D68(void);

#include "Main/Unknown/code_020b4000.h" // Nclr

typedef struct HeyhoPalette HeyhoPalette;
typedef struct KartModelMenuFiles KartModelMenuFiles;

typedef struct KartModelMenuSlot KartModelMenuSlot;

typedef struct KartModelMenuSlot KartModelMenuSlot;
typedef struct KartModelMenuView KartModelMenuView;

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;

typedef struct KartModelMenuView KartModelMenuView;

void chkrt_init(void *heap, u32 kartCount);

#include "Main/Item/ItemInUse.h" // KartModelsEntry

void LoadFileInKartModelMenuFolder(void *heap, const void *fileName, void **file);
void loadKillerItem(void *heap);
void loadKartShadow(KartModelsEntry *kartModelsEntry, void *heap);
void loadKartTire(KartModelsEntry *kartModelsEntry, void *heap);
u16 *LoadKartPaletteInKartModelMenuFolder(void *heap);
u16 *loadStandardKartPaletteFromKartModelArc(void);
void loadKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void loadCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void chkrt_init(void *heap, u32 kartCount);

// Declared here until the code that defines them is decompiled.

#include "Main/Unknown/code_020846c0.h" // Nsbmd

extern u8 data_02154fe8[];
extern u32 aKart_body[];
extern u32 aP_main[];
extern u32 aP_face[];
extern u32 aE_main[];
extern u32 aE_face[];
extern u32 aKart_body_1[];
extern u32 aKart_tire_1[];
extern u8 data_021550c8[];
extern u8 ROB_BLS_Palette[];
extern u8 ROB_LGS_Palette[];
extern u8 data_02155128[];
extern u8 data_02155148[];
extern Nclr *gEmblemSBNclr;
extern u8 *data_0217ad0c;

void SPM_InitVramManager(void *heap);
void AdvanceKartModelMenuLoad(void);
void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files);
Nclr *GetEmblemSBNclr(void);
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor);
void func_02077f48(unsigned int flag);
void func_02077f5c(void);
HeyhoPalette *chkrt_getHeyhoPaletteRow(int kartIndex);
void chkrt_applyHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette);
void chkrt_applyAllHeyhoPalettes(void);
void chkrt_setupHeyhoPaletteRows(void);
void DrawKartModelMenuUnmirrored(void);
void SPM_RenderCharacterSelect3D(void);
void AdvanceKartModelMenuInput(void);
void AdvanceShownSlotAndQueueEmblem(void);
void SPM_2078420(s32 mirrorMode);
void SPM_UpdateKartEmblem(KartModelMenuSlot *slot);
void RenderCharacterForMenu(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored);
void SetupLightFrustumAndLookAt(s32 param_1, s32 yOffset);
void SetFrustumProjection(s32 mirrored);
void StartKartModelMenuBg0Decrease(void);
void StartKartModelMenuBg0Increase(void);
void AdvanceKartModelMenuBg0Offset(void);
void RequestKartModelMenuKart(s32 kartIndex);
void RequestKartModelMenuCharacter(s32 characterIndex);
s16 *spm_LoadCharKartParam(s32 kartIndex, s32 characterIndex);
void InitKartModelMenu(void *heap);
void func_02078c58(void *heap);
void SPM_InitCharacterKartSelect(void *heap);
void QueueKartEmblemTexture(void *emblemData, void *emblemPalette);
void InitKartModelMenuView(KartModelMenuView *view, int b);
void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot);
void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file);
void LoadSelectModel(void *heap);
void *CreateKartModelMenuShadow(void *shadowModel, NNSG3dResFileHeader *modelFile);
void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void anim_2079078(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile);
void func_020790e0(void *heap, s32 createKartAppear);
void PatchROBPalette(KartModelsEntry *kartModelsEntry, s32 pNameUsed);
void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette);
void loadDrivers(void *heap, s32 firstPass);
void chkrt_setKartABC(KartModelsEntry *kartModelsEntry, int kartIndex);
void driver_renderAll(void);
Kart *driver_getById(s32 idx);
void driver_getKartChassisPosition(Vec3 *dst, s32 idx);
void driver_initAll(u32 kartCount);
void UpdateKarts(void);
void SetMinKartDistanceSquared(s32 distanceSquared);
BOOL driver_isPlayerRespawning(void);
BOOL driver_isPlayerHittingWall(void);
BOOL driver_isPlayerHit(void);
void driver_setFogEnableFlags(s32 fogEnableFlag);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *driver_getPlayerStatistics(void);
void driver_notifyOffRoad(Kart *kart);
void driver_notifyItemHit(s32 kartIndex);
BOOL driver_getIsOnAntigravity(s32 kartIndex);
BOOL RacerEntryHasFlags0x60(s32 kartIndex);
// Copies mScale of Kart b to a.
void driver_getScale(Vec3 *scale, s32 kartIndex);
void GetKartPosFromPosSourceCopy(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void driver_getPosition(Vec3 *dst, s32 idx);
void driver_finalize(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time race_update runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);
