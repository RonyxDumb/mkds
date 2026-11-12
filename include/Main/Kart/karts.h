#pragma once

#include "types.h"
#include "code_02012b30.h" // NNSG3dResMdl

void LoadKartAndCharacterFiles(void);

#include "Main/Graphics/font_and_player_character.h" // Nclr

typedef struct HeyhoPalette HeyhoPalette;
typedef struct ShadowModel ShadowModel;
typedef struct KartModelMenuFiles KartModelMenuFiles;

typedef struct KartModelMenuSlot KartModelMenuSlot;

typedef struct KartModelMenuView KartModelMenuView;

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;

void InitKartModels(void *heap, u32 kartCount);

#include "Main/Item/item_in_use.h" // KartModelsEntry

void LoadKartModelMenuFile(void *heap, const void *fileName, void **file);
void CreateKillerItem(void *heap);
void CreateKartShadow(KartModelsEntry *kartModelsEntry, void *heap);
void CreateTire(KartModelsEntry *kartModelsEntry, void *heap);
u16 *LoadKartAPaletteFromKartModelMenu(void *heap);
u16 *LoadKartAPaletteFromKartModelFile(void);
void CreateKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void CreateCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);

#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd

extern u8 data_usa_02154fe8[];
extern u32 data_usa_02155008[];
extern u32 data_usa_02155028[];
extern u32 data_usa_02155038[];
extern u32 data_usa_02155058[];
extern u32 data_usa_02155078[];
extern u32 data_usa_02155088[];
extern u32 data_usa_021550b8[];
extern u8 data_usa_021550c8[];
extern u8 data_usa_021550e8[];
extern u8 data_usa_02155108[];
extern u8 data_usa_02155128[];
extern u8 data_usa_02155148[];
extern Nclr *gEmblemSBNclr;
extern u8 *data_usa_0217acec;

void InitLnkVramManagers(void *heap);
void AdvanceKartModelMenuLoad(void);
void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files);
Nclr *GetEmblemSBNclr(void);
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor);
void SetKartModelMenuSpinStopped(unsigned int flag);
void StartKartModelMenuTimedSpinStop(void);
HeyhoPalette *GetHeyhoPalette(int kartIndex);
void UploadHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette);
void SetupHeyhoPalettes(void);
void CopyHeyhoPaletteIndices(void);
void DrawKartModelMenuUnmirrored(void);
void DrawKartModelMenu(void);
void AdvanceKartModelMenuInput(void);
void AdvanceShownSlotAndQueueEmblem(void);
void AdvanceKartModelMenu(s32 mirrorMode);
void SetupKartModelEmblemTex(KartModelMenuSlot *slot);
void DrawKartModelMenuSlot(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored);
void SetupLightFrustumAndLookAt(s32 unusedArg1, s32 yOffset);
void SetFrustumProjection(s32 mirrored);
void StartKartModelMenuBg0Decrease(void);
void StartKartModelMenuBg0Increase(void);
void AdvanceKartModelMenuBg0Offset(void);
void RequestKartModelMenuKart(s32 kartIndex);
void RequestKartModelMenuCharacter(s32 characterIndex);
s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex);
void InitKartModelMenu(void *heap);
void InitKartModelMenuWithKartList(void *heap);
void InitKartModelMenuWithParamFiles(void *heap);
void QueueKartEmblemTexture(void *emblemData, void *emblemPalette);
void InitKartModelMenuView(KartModelMenuView *view, int flag);
void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot);
void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file);
void LoadKartModelMenuSelectModel(void *heap);
void *CreateKartModelMenuShadow(ShadowModel *shadowModel, NNSG3dResFileHeader *modelFile);
void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void CreateKartModelMenuCharacter(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile);
void InitKartModelMenuAppearAndPalette(void *heap, s32 createKartAppear);
void UploadKartModelsEntryPalettes(KartModelsEntry *kartModelsEntry, s32 pNameUsed);
void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette);
void CreateKartModelsEntryModels(void *heap, s32 firstPass);
void SetKartModelsEntryVariant(KartModelsEntry *kartModelsEntry, int kartIndex);
void DrawKarts(void);
Kart *GetKart(s32 idx);
void GetKartPrevPos(Vec3 *dst, s32 idx);
void InitKarts(u32 kartCount);
void UpdateKarts(void);
void SetMinKartDistanceSquared(s32 distanceSquared);
BOOL IsEntryKartFlag1000Set(void);
BOOL IsEntryKartInContact(void);
BOOL IsEntryKartNotNormalOrScaleTableBit(void);
void SetKartModelsFogEnable(s32 fogEnableFlag);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *GetEntryKartCounters(void);
void IncrementEntryKartSurfaceCount(Kart *kart);
void IncrementEntryKartItemHitCount(s32 kartIndex);
BOOL IsKartOnBoostSurface(s32 kartIndex);
BOOL IsKartRemovedWrapper(s32 kartIndex);
// Copies mScale of Kart b to a.
void GetKartScale(Vec3 *scale, s32 kartIndex);
void GetKartPosFromPosSourceCopy(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void GetKartPos(Vec3 *dst, s32 idx);
void CallKartSlot8AndClearKarts(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time UpdateRace runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);

BOOL IsCharacterPNameUsed(s32 kartIndex);

void InitCharacterAnimationState(u32 animationStateAddress);

void InitKartModelsEntry(void *entry);

u32 GetKartVariant(u32 kartIndex);

void *GetKillerItemNsbca(void);
void *GetKillerItemS(void);
void *GetKillerItem(void);

struct KartModelsEntry;

void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible);

extern s32 gMinKartDistanceSquaredPresent;
extern s32 gMinKartDistanceSquared;

void SetKartModelMaterialColors(NNSG3dResMdl *mdl, u32 colorSet);
BOOL IsEntryKartNormalOrNotMissionRun(void);
BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared);

void SetKillerItemKartIndex(unsigned int kartIndex);
unsigned int GetKillerItemKartIndex(void);

extern s32 data_usa_021658bc;
extern u16 gKartCount;

void SetKartNearPlayerRankBits(void);
BOOL IsKartInRespawnWait(s32 kartIndex);

u32 GetKartCourseHitAttributeBitWrapper(int kartIndex);

void SetKartSpeedLimitReciprocal(unsigned int speedLimitReciprocal);

void SetKartForwardSpeedRatio(s32 forwardSpeed);

unsigned int GetKartKind3ShapeListMask(void);

void SetKartKind3ShapeListMask(s32 kartIndex);

unsigned int GetKartForwardSpeedRatio(void);

void StartKartRaceEndWrapper(s32 kartIndex);

// Whether this is a mission run on a course with a shape of kind 2.
unsigned int IsMissionRunWithKind2Shapes(void);

typedef struct Kart Kart;

// The functions every Kart starts with, copied into Kart.mSlotFunctions by InitKart. Slots 0, 1, 6, 7 and 8 keep these;
// slots 2 to 5 are zero here and always replaced by InitKart.
extern void (*gKartDefaultSlotFunctions[])(Kart *a);

void DrawShadowModelIfDrawFlag(ShadowModel *shadowModel, u32 unusedArg1, u32 unusedArg2);
