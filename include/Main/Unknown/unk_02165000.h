#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // SceneCallbacks
#include "Main/Unknown/code_02086058.h"

extern const char aSS_8[];
extern const char aSS_S_nsbca[];
extern u16 data_021656d8;
extern u16 data_021656dc;
extern s32 data_021656e0;
extern s32 data_021656e4;
extern u32 data_021656e8;
extern s32 data_021656ec;
extern Vec3 data_021656f0;
extern Vec3 data_021656fc;
extern Vec3 data_02165708;
extern u8 aKartoffsetdata[];
extern u8 aCharmenuparam_[];
extern u8 aKartmenuparam_[];
extern u8 aKartSelectSele[];
extern u8 aKartSelectSe_0[];
extern const char aSS_9[];
extern const u8 aRom[];

// Objects whose layout isn't known yet.
typedef struct QueueMPDataToPortParams {
    /* 00 */ void (*mCallback)();
    /* 04 */ u16 mMaxDataSize;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mPort;
    /* 0c */ u16 mPriority;
    /* 0e */ u8 mUnk_0e[2];
} QueueMPDataToPortParams;

extern QueueMPDataToPortParams data_0216523c;
extern const s32 data_02165510[2];
extern const Vec3 data_02165524;
extern const Vec3 data_0216553c;
extern const Vec3 data_02165548;
extern const SceneCallbacks recordsMenu_vtable;
extern const SceneCallbacks menu2_vtable;
extern const SceneCallbacks gEmblemSceneCallbacks;
extern const SceneCallbacks sLogoMenu;
extern QueueMPDataToPortParams data_021652a0;
extern u16 data_02165228;
extern QueueMPDataToPortParams data_0216522c;
extern UnkFunc *const gMPStateTable[];
extern UnkFunc *const data_02165388[];
struct Kart;
extern void (*const driver_sReactionUpdateFuncs[])(struct Kart *);
extern const SceneCallbacks gResultSceneCallbacks;
extern const SceneCallbacks multiplayerMenu_vtable;
extern const char aS_S_carc[];
extern const char aDataSceneS_S_S[];
extern const char a_carc[];
extern const char aDataSceneS_SS[];
extern const char a_carc_0[];
extern const char aDataSceneSta_0[];
extern const char a_carc_1[];
extern const char aDataSceneSS[];
extern const char a_carc_4[];
extern const char aDataSceneS_S_0[];
extern const char a_carc_5[];
extern const char aKart_appear_kt[];
extern const char *cklcr_sCharacterFolder;
extern const char *cklcr_sKartFolder;
extern const char *sCharFolderNames[13];
extern u16 data_021659d4[12];
extern TexPlttEntry data_021659ec;
extern TexPlttEntry data_02165a10;
extern TexPlttEntry data_02165a34;
extern TexPlttEntry data_02165a58;
extern const char aSScommonP_face[];
extern const char aDataKartmode_1[];
extern const char gKartModelSlashPrefix[];

extern s16 scproc_sSceneManager[];
extern const SceneCallbacks ghost_sceneDef;
extern u16 cam_sDefaultFov;
extern u16 data_021656a0;
extern s32 cam_sCannonShakeAmount;
extern s32 cam_sColSphereSize;
extern Vec3 data_02165530;
extern s32 data_02165948;
extern s32 data_0216593c;
extern s32 data_02165944;
extern s32 data_0216594c;
extern s32 data_02165950;
extern u32 rptc_sRainbowEffectEmitterIds[];

// Three words, three more words and two halfwords; data_02165ff0, data_0216600c and data_02166028 are one each.
typedef struct Unk02165ff0 {
    /* 00 */ s32 mUnk_00[3];
    /* 0c */ s32 mUnk_0c[3];
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
} Unk02165ff0;

extern Unk02165ff0 data_02165ff0;

extern u8 aRom_0[];
extern const s32 data_02166048;
extern const Vec3 data_0216608c;
extern u8 aRom_1[];
extern const char aKartaiparam_bi[];
extern const char *const sTeamNames[];
extern const char aSemblemTeamS_e[];
extern const char aSemblemS_emble[];
extern s32 data_021659a0;
extern s32 data_021659a4;
extern s32 data_021659a8;
extern s32 data_021659ac;
extern s32 data_021659b0;
extern s32 data_021659b4;
extern s32 data_021659b8;
extern s32 data_021659bc;
extern s32 data_021659c0;
extern s32 data_021659c4;
extern s32 data_021659c8;
extern s32 data_021659cc;
extern s32 data_021659d0;
extern const char aEmblem_s_b_n_1[];
extern s32 data_021654ec;
extern s32 data_021654f4;
// Three words.
typedef struct KartFollowEffectIds {
    /* 00 */ u32 mEffectIds[3];
} KartFollowEffectIds;

extern const KartFollowEffectIds gKartFollowEffectIds;

// Eight halfwords.
typedef struct KartKillerEndRankOffsets {
    /* 00 */ s16 mUnk_00[8];
} KartKillerEndRankOffsets;

extern const KartKillerEndRankOffsets driver_sKillerPlaceImprovement;
extern s32 data_021654dc;
extern const Vec3 data_02165554;
// 37 words.
typedef struct Unk02165608 {
    /* 00 */ s32 mUnk_00[37];
} Unk02165608;

extern const Unk02165608 data_02165608;
extern s32 data_02165504;
extern const s32 data_02165500;
extern const s16 data_021654c0;

extern u16 data_021658f0;
extern const s32 *data_021658f4;
extern const u16 data_021658f8[3];
extern const u16 data_02165900[3];
extern const u16 data_02165908[3];
extern const s32 *const data_02165910[];
extern s32 driver_sTurningSpeedLoose;
