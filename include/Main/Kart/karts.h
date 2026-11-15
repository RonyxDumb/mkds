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

// Value of the kart and character indexes of a menu slot or view that shows nothing.
#define KART_MODEL_MENU_NONE (-1)
// Last kart index the kart model menu cycles through; the yaw angle it rests at; the frames a timed spin stop waits; the
// tilt limits and the scale floor of the view.
#define KART_MODEL_MENU_LAST_KART_INDEX 0x23
#define KART_MODEL_MENU_REST_YAW 0xeaab
#define KART_MODEL_MENU_SPIN_STOP_FRAMES 0x3c
#define KART_MODEL_MENU_TILT_DOWN_MAX 0x1b58
#define KART_MODEL_MENU_TILT_UP_MAX 0x1388
#define KART_MODEL_MENU_SCALE_MIN 0x800

// Sets of material colours of SetKartModelMaterialColors: the course colours, the bright set of the menu models, the
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
#include "Main/Kart/kart_drift.h"

// Resource names (16 bytes, zero padded) that are looked up in the kart models.
extern const char gHeyhoPMainMaterialName[16];
extern const char gSpecialKartBodyMaterialName[16];
extern const char gKartEmblemMaterialName[16];
extern const char gCharacterBPMainMaterialName[16];
extern const char gCharacterBPFaceMaterialName[16];
extern const char gEmblemTextureName[16];
extern const char gCharacterBEMainMaterialName[16];
extern const char gHeyhoEMainMaterialName[16];
extern const char gCharacterBEFaceMaterialName[16];
extern const char gKartAPaletteMaterialName[16];
extern const char gTireModelMaterialName[16];
extern const char gEmblemPaletteName[16];
extern const char gKartTireMaterialName[16];
extern const u16 gCharacterBEFacePalette[8];
extern const u16 gCharacterBEMainPalette[16];
extern const u16 gSpecialKartFirstPalette[16];
extern const u16 gSpecialKartSecondPalette[16];
extern const u16 gCharacterBPMainPalette[16];
extern const u16 gCharacterBPFacePalette[32];

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
void SetupLightFrustumAndLookAt(s32 unusedBg0Offset, s32 yOffset);
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
BOOL IsEntryKartRespawnFalling(void);
BOOL IsEntryKartInContact(void);
BOOL IsEntryKartNotNormalOrScaleTableBit(void);
void SetKartModelsFogEnable(s32 fogEnableFlag);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *GetEntryKartCounters(void);
void IncrementEntryKartSurfaceCount(Kart *kart);
void IncrementEntryKartItemHitCount(s32 kartIndex);
BOOL IsKartOnBoostSurface(s32 kartIndex);
BOOL IsKartRemovedWrapper(u16 kartIndex);
// Copies mScale of Kart b to a.
void GetKartScale(Vec3 *scale, s32 kartIndex);
void GetKartPosFromPosSourceCopy(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void GetKartPos(Vec3 *dst, s32 idx);
void ReleaseKartsAndClear(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time UpdateRace runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);

BOOL IsCharacterPNameUsed(s32 kartIndex);

void InitCharacterAnimationState(u32 animationStateAddress);

void InitKartModelsEntry(void *entry);

u32 GetKartVariant(u16 kartIndex);

void *GetKillerItemNsbca(void);
void *GetKillerItemS(void);
void *GetKillerItem(void);

struct KartModelsEntry;

void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible);

extern s32 gMinKartDistanceSquared;

void SetKartModelMaterialColors(NNSG3dResMdl *mdl, u32 colorSet);
BOOL IsEntryKartNormalOrNotMissionRun(void);
BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared);

void SetKillerItemKartIndex(unsigned int kartIndex);
unsigned int GetKillerItemKartIndex(void);

extern s32 gNearPlayerRankKartCount;

void SetKartNearPlayerRankBits(void);
BOOL IsKartInRespawnWait(s32 kartIndex);

u32 GetKartCourseHitAttributeBitWrapper(int kartIndex);

void SetKartSpeedLimitReciprocal(unsigned int speedLimitReciprocal);

void SetKartForwardSpeedRatio(s32 forwardSpeed);

unsigned int GetKartZoneMask(void);

void SetKartZoneMask(s32 kartIndex);

unsigned int GetKartForwardSpeedRatio(void);

void StartKartRaceEndWrapper(u16 kartIndex);

// Whether this is a mission run on a course with a shape of kind 2.
unsigned int IsMissionRunWithEndShapes(void);

typedef struct Kart Kart;

void DrawShadowModelIfDrawFlag(ShadowModel *shadowModel, u32 unusedSecond, u32 unusedThird);

extern u16 gKartCount;
extern u16 gKillerItemKartIndex;
extern struct Kart *gKarts;
extern s32 gKartForwardSpeedRatio;
extern struct EntryKartCounters *gEntryKartCounters;
extern s32 gMinKartDistanceSquaredPresent;
// 1 when this is a mission run and the course has a shape of kind 2, else 0; set by InitKarts.
extern s32 gMissionRunEndShapesPresent;
extern s32 gKartSpeedLimitReciprocal;
extern u32 gKartZoneMask;
