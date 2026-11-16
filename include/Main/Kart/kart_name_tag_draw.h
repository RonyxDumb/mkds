#pragma once

#include "types.h"

typedef struct TexPlttEntry TexPlttEntry;

typedef struct TexPlttEntry TexPlttEntry;
typedef struct KartNameTag KartNameTag;

#include "Main/System/backup_net_camera_work.h"

void StructAERSubSub_SomeFn_from_thumb(TexPlttEntry *texPlttEntry);
void UploadKartEmblem(u32 kartIndex, void *texData, void *plttData);
void UploadKartEmblems(void);
void LoadEmblemDataInAED0_from_thumb(void);
void StructAERSubSub_Fn1_Sub4_from_thumb(TexPlttEntry *texPlttEntry, u16 kartIndex);
void StructAERSubSub_Fn1_Sub3_from_thumb(TexPlttEntry *texPlttEntry, u32 kartIndex);
void StructAERSubSub_Fn1_Sub2_from_thumb(TexPlttEntry *texPlttEntry, u32 kartIndex);
void StructAERSubSub_Fn1_Sub1_from_thumb(TexPlttEntry *texPlttEntry, u16 kartIndex);
void UploadKartNameTagTextures(void);
u16 GetVsRacerIndicatorColor_from_thumb(int kartIndex);
void StructAERSubSub_SomeFn_1_from_thumb(TexPlttEntry *texPlttEntry);
void StructAER_SomeFn_from_thumb(KartNameTag *kartObject, u16 kartIndex, void *heap);
void CreateGlobalAED0_from_thumb(void);
void DrawKartNameTagLineVertices(s32 texWidthFixed, s32 texHeightFixed, u32 color);

// Bytes of the emblem texture and palette a name tag uses.
#define KART_EMBLEM_TEX_BYTES 0x200
#define KART_EMBLEM_PLTT_BYTES 0x20
