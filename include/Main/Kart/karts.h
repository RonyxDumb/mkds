#pragma once

#include "types.h"
#include "model_material_set.h" // NNSG3dResMdl

void LoadKartAndCharacterFiles(void);

#include "Main/Graphics/font_and_player_character.h" // Nclr

typedef struct HeyhoPalette HeyhoPalette;
typedef struct ShadowModel ShadowModel;
typedef struct KartModelMenuFiles KartModelMenuFiles;

typedef struct KartModelMenuSlot KartModelMenuSlot;

typedef struct KartModelMenuView KartModelMenuView;

// Value of the kart and character indexes of a menu slot or view that shows nothing.
#define KART_MODEL_MENU_NONE (-1)
// Last kart index the kart model menu cycles through; the yaw angle it rests at; the frames a timed spin stop waits;
// the tilt limits and the scale floor of the view.
#define KART_MODEL_MENU_LAST_KART_INDEX 0x23
#define KART_MODEL_MENU_REST_YAW 0xeaab
#define KART_MODEL_MENU_SPIN_STOP_FRAMES 0x3c
#define KART_MODEL_MENU_TILT_DOWN_MAX 0x1b58
#define KART_MODEL_MENU_TILT_UP_MAX 0x1388
#define KART_MODEL_MENU_SCALE_MIN 0x800

// Sets of material colours of ModelBlock_SomeMatFn: the course colours, the bright set of the menu models, the
// dark grey set, and the dark set with an emissive colour (no caller).
#define KART_MODEL_COLORS_COURSE 0
#define KART_MODEL_COLORS_MENU 1
#define KART_MODEL_COLORS_DARK 2
#define KART_MODEL_COLORS_DARK_EMISSIVE 3

// Kart indexes whose body palette is replaced by gSpecialKartFirstPalette and gSpecialKartSecondPalette.
#define KART_INDEX_SPECIAL_FIRST 0x22
#define KART_INDEX_SPECIAL_SECOND 0x23

// The kart of CHARACTER_HEYHO in both character to kart tables (gCharacterKartIndexTable and
// gCharacterKartIndexTableBattle).
#define KART_INDEX_HEYHO 0x24

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;

void InitializeGlobalAD00_from_thumb(void *heap, u32 kartCount);

#include "Main/Item/item_in_use.h" // KartModelsEntry

void ReadKartModelMenuFile_from_thumb(void *heap, const void *fileName, void **file);
void LoadAD00KillerItemModel_from_thumb(void *heap);
void StructAD00Sub_LoadKartShadowModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap);
void StructAD00Sub_LoadKartTireModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap);
u16 *GetKartModelMenuKartAPalette_from_thumb(void *heap);
u16 *GetKartAPaletteData_from_thumb(void);
void StructAD00Sub_LoadKartModel_from_thumb(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void StructAD00Sub_LoadCharacterEmblem_from_thumb(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);

#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Kart/kart_drift.h"

// Resource names (16 bytes, zero padded) that are looked up in the kart models.
extern const char g_str_P_main[16];
extern const char g_str_kart_body[16];
extern const char gKartEmblemMaterialName[16];
extern const char g_str_P_main_0[16];
extern const char g_str_P_face[16];
extern const char g_str_emblem[16];
extern const char g_str_E_main_0[16];
extern const char g_str_E_main[16];
extern const char g_str_E_face[16];
extern const char g_str_kart_body_0[16];
extern const char g_str_kart_tire[16];
extern const char g_str_emblem_pl[16];
extern const char g_str_kart_tire_0[16];
extern const u16 gCharacterBEFacePalette[8];
extern const u16 gCharacterBEMainPalette[16];
extern const u16 gSpecialKartFirstPalette[16];
extern const u16 gSpecialKartSecondPalette[16];
extern const u16 gCharacterBPMainPalette[16];
extern const u16 gCharacterBPFacePalette[32];

void InitLnkVramManagers(void *heap);
void AdvanceKartModelMenuLoad(void);
void CreateCESex_from_thumb(void *heap, KartModelMenuFiles *files);
Nclr *GetEmblemPalette_from_thumb(void);
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor);
void SetKartModelMenuSpinStopped(unsigned int flag);
void StartKartModelMenuTimedSpinStop(void);
HeyhoPalette *GetHeyhoColorPaletteDataForRacer_from_thumb(int kartIndex);
void UploadHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette);
void CopyDefaultHeyhoColorPalettes_from_thumb(void);
void CopySomeHeyhoPaletteRows_from_thumb(void);
void DrawKartModelMenuUnmirrored(void);
void DrawKartModelMenu(void);
void AdvanceKartModelMenuInput(void);
void AdvanceShownSlotAndQueueEmblem(void);
void AdvanceKartModelMenu(s32 mirrorMode);
void StructCESub_SomeFn_from_thumb(KartModelMenuSlot *slot);
void DrawKartModelMenuSlot(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored);
void SetupLightFrustumAndLookAt(s32 unusedBg0Offset, s32 yOffset);
void SetFrustumProjection(s32 mirrored);
void StartKartModelMenuBg0Decrease(void);
void StartKartModelMenuBg0Increase(void);
void AdvanceKartModelMenuBg0Offset(void);
void RequestKartModelMenuKart(s32 kartIndex);
void RequestKartModelMenuCharacter(s32 characterIndex);
s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex);
void InitializeGlobalCE_from_thumb(void *heap);
void InitKartModelMenuWithKartList(void *heap);
void CreateGlobalCE_from_thumb(void *heap);
void QueueKartEmblemTexture(void *emblemData, void *emblemPalette);
void StructCE0_SomeFn_from_thumb(KartModelMenuView *view, int flag);
void StructCESub_Initialize_from_thumb(void *heap, KartModelMenuSlot *slot);
void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file);
void CreateCEML_from_thumb(void *heap);
void *StructAD00Sh_SomeFn_1_from_thumb(ShadowModel *shadowModel, NNSG3dResFileHeader *modelFile);
void StructML_LoadModel3Mat_from_thumb(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void StructML_SomeFn_6_from_thumb(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void MaybeLoadWinModelTextureAnimationHelper_from_thumb(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile);
void LoadKartAppearTablePointerCE_from_thumb(void *heap, s32 createKartAppear);
void StructAD00Sub_SomeFnPaletteSwapRelated_from_thumb(KartModelsEntry *kartModelsEntry, s32 pNameUsed);
void LoadKartBodyPalette_from_thumb(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette);
void CreateKartModelsEntryModels(void *heap, s32 firstPass);
void StructAD00Sub_SetKartIndex_from_thumb(KartModelsEntry *kartModelsEntry, int kartIndex);
void DrawKarts(void);
Kart *GetRacerMQEntry(s32 idx);
void LoadRacerMQVectorA(Vec3 *dst, s32 idx);
void CreateGlobalMQAndRK(u32 kartCount);
void UpdateKarts(void);
void SetMinKartDistanceSquared(s32 distanceSquared);
BOOL IsEntryKartRespawnFalling(void);
BOOL IsEntryKartInContact(void);
BOOL IsEntryKartNotNormalOrScaleTableBit(void);
void SetKartModelsFogEnable(s32 fogEnableFlag);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *GetGlobalRK(void);
void IncrementEntryKartSurfaceCount(Kart *kart);
void IncrementEntryKartItemHitCount(s32 kartIndex);
BOOL IsKartOnBoostSurface(s32 kartIndex);
BOOL RacerEntryHasFlags0x60(u16 kartIndex);
// Copies mScale of Kart b to a.
void LoadRacerMQVectorD(Vec3 *scale, s32 kartIndex);
void LoadRacerMQVectorC(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void LoadRacerMQVectorB(Vec3 *dst, s32 idx);
void ResetGlobalMQ(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time UpdateRace runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);

BOOL DetermineIsP_from_thumb(s32 kartIndex);

void StructAD00SubSub_Create_from_thumb(u32 animationStateAddress);

void StructAD00Sub_Initialize_from_thumb(void *entry);

u32 GetAD00SubKartIndexMod3(u16 kartIndex);

void *GetAD00KillerItemAnimation(void);
void *GetSomeAD00Sh(void);
void *GetKillerItemModel(void);

struct KartModelsEntry;

void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible);

extern s32 gMinKartDistanceSquared;

void ModelBlock_SomeMatFn(NNSG3dResMdl *mdl, u32 colorSet);
BOOL IsEntryKartNormalOrNotMissionRun(void);
BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared);

void SetKillerItemKartIndex(unsigned int kartIndex);
unsigned int GetKillerItemKartIndex(void);

extern s32 gNearPlayerRankKartCount;

void SetKartNearPlayerRankBits(void);
BOOL StructMQHasFlagB_800(s32 kartIndex);

u32 GetKartCourseHitAttributeBitWrapper(int kartIndex);

void SetKartSpeedLimitReciprocal(unsigned int speedLimitReciprocal);

void SetKartForwardSpeedRatio(s32 forwardSpeed);

unsigned int GetKartZoneMask(void);

void SetKartZoneMask(s32 kartIndex);

unsigned int GetKartForwardSpeedRatio(void);

void StructMQRacerEntry_SomeFn_21_ById(u16 kartIndex);

// Whether this is a mission run on a course with a shape of kind 2.
unsigned int IsMissionRunWithEndShapes(void);

typedef struct Kart Kart;

void DrawShadowModelIfDrawFlag(ShadowModel *shadowModel, u32 unusedSecond, u32 unusedThird);

extern u16 g_MQEntryCount;
extern u16 gKillerItemKartIndex;
extern struct Kart *g_GlobalMQ;
extern s32 gKartForwardSpeedRatio;
extern struct EntryKartCounters *g_GlobalRK;
extern s32 gMinKartDistanceSquaredPresent;
// 1 when this is a mission run and the course has a shape of kind 2, else 0; set by CreateGlobalMQAndRK.
extern s32 gMissionRunEndShapesPresent;
extern s32 gKartSpeedLimitReciprocal;
extern u32 gKartZoneMask;
