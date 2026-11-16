#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx22, NNSG3dResMatData
#include "Main/Kart/kart_effect_param_tables.h" // BattleKartAiParams
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h" // ResFileEntry
#include "sound_archive_load.h"
#include "Main/System/time_digits.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer
#include "Main/Race/race_goal_s_sb.h" // PaletteAndChars
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "ITCM/sphere_collision.h" // CourseCollision
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/map_object_model.h" // MapObjectModel
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/menu_screens_work.h" // NNSG2dCharCanvas
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Graphics/stem_set_array.h" // StemSet
#include "geometry_engine_setup.h" // MtxFx44

struct RandomState64;
struct MapObjects;
struct Water;
struct MenuScene;
struct Nscr;
struct Ncgr;
struct Nclr;
struct NNSG2dFont;
struct KartBalloons;

// The rotation of an item box: its cosine, sine, their squares and their product.
typedef struct BoxRotation {
    /* 00 */ s32 mCosine;
    /* 04 */ s32 mSine;
    /* 08 */ s32 mCosineSquared;
    /* 0c */ s32 mSineSquared;
    /* 10 */ s32 mCosineSineProduct;
} BoxRotation;
// Entries of the BoxRotation and QuestionRotation tables: one turn split into this many steps.
#define BOX_ROTATION_COUNT 0x12c
#define QUESTION_ROTATION_COUNT 0x82

// The rotation of the question model of an item box: its cosine and sine.
typedef struct QuestionRotation {
    /* 00 */ s32 mCosine;
    /* 04 */ s32 mSine;
} QuestionRotation;

// Two s32 values (mFirst, mSecond): HUD draw positions, checkpoint x and z, and the scale and frame count pairs of the
// sub screen cells.
typedef struct IntPair {
    /* 00 */ s32 mFirst;
    /* 04 */ s32 mSecond;
} IntPair;

// Values of RaceHudSubScreenCell.mPriority, stored as the OAM priority of the cell. Cells placed by their position take
// 2 when IsPositionOutsideBox holds and 3 when it does not; while the followed kart is inside the box only cells of
// priority 3 are drawn (mMinDrawValue).
#define RACE_HUD_PRIORITY_FRONT 1
#define RACE_HUD_PRIORITY_MIDDLE 2
#define RACE_HUD_PRIORITY_3 3
// One cell of the race sub screen: its draw position, cell, priority, translucency and angle.
typedef struct RaceHudSubScreenCell {
    /* 00 */ IntPair mDrawPos;
    /* 08 */ struct NNSG2dCellDataWithBR *mCell;
    /* 0c */ u16 mPriority;
    // Non-zero draws the cell translucent; the flipper cells use it as the mirror flag.
    /* 0e */ u16 mXlu;
    /* 10 */ u16 mAngle;
    /* 12 */ u8 mUnk_12[2];
} RaceHudSubScreenCell;

// Used by every gRaceHudSubScreen<Name>Cells list, made by CreateRaceHudSubScreenCells or
// CreateRaceHudSubScreenCellsWithCount.
typedef struct RaceHudSubScreenCells {
    /* 00 */ MapObject **mObjects;
    /* 04 */ s32 mCellCount;
    /* 08 */ s32 mObjectCount;
    // One pair per object: its course position, or in the scaled lists the scale in mFirst; the burner and fireball
    // lists also count frames in mSecond of pair 0.
    /* 0c */ IntPair *mObjectPairs;
    /* 10 */ RaceHudSubScreenCell *mCells;
} RaceHudSubScreenCells;

// The sub screen background colours of the Koopa course: mSecondObjectColors, mFirstObjectColors, mKoopaBlockColors.
typedef struct RaceHudSubScreenKoopaBgColors {
    /* 00 */ u16 mSecondObjectColors[6];
    /* 0c */ u16 mFirstObjectColors[2][3];
    /* 18 */ u16 mKoopaBlockColors[2];
} RaceHudSubScreenKoopaBgColors;

// The sub screen background colors of the course, one layout chosen by gRaceSetup.mCourseId: frame colors, gear colors,
// a color list or the Koopa colors.
typedef union RaceHudSubScreenBgColorSets {
    u16 mColorList[0x15];
    u16 mFrameColors[9][3];
    u16 mGearColors[5][4];
    RaceHudSubScreenKoopaBgColors mKoopaColors;
} RaceHudSubScreenBgColorSets;

// The background color sets of the race HUD sub screen.
typedef struct RaceHudSubScreenBgColors {
    /* 00 */ u16 mUnk_00;
    /* 02 */ RaceHudSubScreenBgColorSets mColors;
} RaceHudSubScreenBgColors;

// The course number and course count pair drawn on the main screen during the race start in a Wi-Fi race and in a
// Versus race with the race count rule (gRaceMNumberPair).
typedef struct RaceMNumberPair {
    // Copy of gRaceSetup.mCourseNumber taken in InitRaceMNumberPair.
    /* 00 */ s32 mCourseNumber;
    // Number of courses of the race series: 4 in a Wi-Fi race, gRaceSetup.mCourseCount in a VS race with the race count
    // rule, else 0 (not drawn).
    /* 04 */ s32 mCourseCount;
    /* 08 */ MtxFx22 mScaleMatrix;
    /* 18 */ MtxFx22 *mCellMatrix;
    /* 1c */ s32 mScale;
    /* 20 */ u16 mMatrixIndex;
    /* 22 */ u8 mUnk_22[2];
    // X added to every sprite of the pair: 0, or eased by InterpolateS16 (SetRaceMNumberPairAnimation) from 0 to 0x80
    // for the slide to the right after frame 0x78 of the start sequence.
    /* 24 */ s32 mOffsetX;
} RaceMNumberPair;

typedef struct WaterEfct WaterEfct;

// The camera view frustum: near and far distance, camera position and direction, and the four side plane normals.
typedef struct ViewFrustum {
    /* 00 */ s32 mNear;
    /* 04 */ s32 mFar;
    /* 08 */ Vec3 mCameraPos;
    /* 14 */ Vec3 mViewDirection;
    /* 20 */ Vec3 mLeftPlaneNormal;
    /* 2c */ Vec3 mRightPlaneNormal;
    /* 38 */ Vec3 mTopPlaneNormal;
    /* 44 */ Vec3 mBottomPlaneNormal;
    /* 50 */ BOOL mViewTestRefreshRequested;
    /* 54 */ BOOL mViewTestRefreshPending;
} ViewFrustum;

// Values of EmblemChoises.mChoisesIndex and of a picked mResult: the first goes back to editing, the second writes the
// emblem to the save data and leaves, the third leaves without writing. mResult is also -1 (nothing picked) and -2
// (closed with B or START, handled like the first).
enum { EMBLEM_CHOISE_BACK, EMBLEM_CHOISE_SAVE, EMBLEM_CHOISE_DISCARD };

// The emblem choice screen: mShown, the pick and close frame counts, mResult, mChoisesCount entries and their graphics.
typedef struct EmblemChoises {
    /* 00 */ s32 mShown;
    /* 04 */ s32 mDrawnShown;
    /* 08 */ BOOL mGraphicsUploadRequested;
    /* 0c */ void (*mHideCallback)(void);
    /* 10 */ BOOL mPickStartedOnSelected;
    /* 14 */ s32 mPickFrames;
    /* 18 */ s32 mCloseFrames;
    /* 1c */ s32 mResult;
    /* 20 */ s32 mChoisesIndex;
    /* 24 */ s32 mCycleFrames;
    /* 28 */ s32 mChoisesCount;
    /* 2c */ void *mFont;
    /* 30 */ NNSG2dCharCanvas mCharCanvas;
    /* 50 */ TextCanvas mTextCanvas;
    /* 60 */ struct Nclr *mChoisesSBNclr;
    /* 64 */ struct Ncgr *mChoisesSBNcgr;
    /* 68 */ struct Nscr *mChoisesS3Nscr;
} EmblemChoises;

// One row of the MapObj/grpconf.tbl table: a map object kind, view test and radius, draw distance, shape extents.
typedef struct GrpconfTblRow {
    /* 00 */ u16 mKind;
    /* 02 */ u16 mViewTestKind;
    /* 04 */ u16 mViewRadius;
    /* 06 */ u16 mDrawDistance;
    /* 08 */ u16 mShapeKind;
    /* 0a */ u16 mExtentX;
    /* 0c */ u16 mExtentY;
    /* 0e */ u16 mExtentZ;
} GrpconfTblRow;

struct SPLManager;
struct KartAi;
struct KartAiItemUse;

// The kart physics tables of a race: the kart and character parameters and the two files they come from.
typedef struct KartPhysicalParamTable {
    /* 00 */ struct KartPhysicalParam *mKartParams;
    /* 04 */ s32 *mCharParams;
    /* 08 */ s32 mFirstBaseSpeedLimit;
    /* 0c */ struct KartPhysicalParam *mKartParamFile;
    /* 10 */ s32 *mCharParamFile;
} KartPhysicalParamTable;

struct ModelEffect;

#define MODEL_EFFECT_POLYGON_ID_FIRST 10
#define MODEL_EFFECT_POLYGON_ID_LAST 13

// The ModelEffect pools: an active list, one free list and one object array per kind, and the next polygon id (first to
// last, then around).
typedef struct ModelEffects {
    /* 00 */ NNSFndList mActiveList;
    /* 0c */ NNSFndList mFreeLists[MODEL_EFFECT_KIND_COUNT];
    /* 48 */ struct ModelEffect **mObjects[MODEL_EFFECT_KIND_COUNT];
    /* 5c */ u16 mNextPolygonId;
    /* 5e */ u8 mUnk_5e[2];
} ModelEffects;

// The strip pool: the active strips, the free strips, the free points and the texture file.
typedef struct PosStrips {
    // [0] active strips, [1] free strips, [2] free points.
    /* 00 */ NNSFndList mLists[3];
    /* 24 */ ResFileEntry mEffectFileEntry;
    /* 34 */ s32 mPolygonAttrBits;
} PosStrips;

// The 0x10 bytes at 0x784 of StemSets; the callbacks at 0x794 and 0x798 get their address.
// TimedQuad.mColor: white as a 15-bit color.
#define TIMED_QUAD_COLOR_WHITE 0x7fff

// A quad with a countdown timer, alpha and 15-bit color, updated and drawn (in a normal race) while mEnabled.
typedef struct TimedQuad {
    /* 00 */ s16 mTimer;
    /* 02 */ s16 mAlpha;
    /* 04 */ u16 mColor;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ BOOL mEnabled;
    /* 0c */ u8 mUnk_0c[4];
} TimedQuad;

// The stem sets: eight sets and an entry for the one shown, the shown index and frames, a matrix and a timed quad.
typedef struct StemSets {
    // Entries 0 to 7 are the sets; entry 8 is a copy of the one shown.
    /* 000 */ StemSet *mSets[9];
    /* 024 */ u8 mUnk_024[0x718];
    // Index of the set DrawStemSets draws; 9 means none.
    /* 73c */ s32 mShownIndex;
    /* 740 */ u16 mShownFrames;
    /* 742 */ u16 mShownFrameCount;
    /* 744 */ MtxFx44 mOrthoMtx;
    /* 784 */ TimedQuad mTimedQuad;
    /* 794 */ void (*mStartFunction)(TimedQuad *);
    /* 798 */ void (*mUpdateFunction)(TimedQuad *);
} StemSets;

// Values of KartStanding.mEliminationStatus.
#define KART_STANDING_IN_PLAY 0
#define KART_STANDING_JUST_ELIMINATED 1
#define KART_STANDING_ELIMINATED 2

// Value of KartStanding.mNotNormalEndPending and mObjectsSkipEndPending when no hit end is waiting (s32).
#define KART_STANDING_HIT_END_NONE -2
// One kart's entry of Standings: its count, rank, side id, elimination status, last position and hit tracking.
typedef struct KartStanding {
    /* 00 */ BOOL mNotNormalOrFlaggedSeen;
    /* 04 */ BOOL mObjectsSkipSeen;
    // 0 in play, 1 just eliminated (UpdateStandings queues the kart's own sound with QueueKartOwnSoundIndex, except for
    // the entry kart once a winner is decided, and sets 2), 2 eliminated and handled; unused slots start at 2;
    // EliminateKartsUntilWinnerDecided also sets 2 directly. Only compared, never switched on.
    /* 08 */ s32 mEliminationStatus;
    // Copy of the kart's position, refreshed every update while the kart's count is above 0, it is not just eliminated
    // and no winner is decided.
    /* 0c */ Vec3 mPos;
    /* 18 */ s32 mNotNormalEndPending;
    /* 1c */ s32 mObjectsSkipEndPending;
    /* 20 */ BOOL mSkipNotNormalEnd;
    /* 24 */ s32 mHitSeenFromKart[8];
    /* 44 */ u16 mHitByKartIndex;
    // Id of the side the kart plays for: the entry's team index 0 gives 1, 1 gives 3, any other value gives the kart's
    // own index; an unused slot gets the kart count. The winner test compares it between the karts still in play.
    /* 46 */ u16 mTeamId;
    // Position in the order, 0 = first. Starts as the kart's own index; AddBalloonOrShineCountAndMoveRank and
    // EliminateKart move the kart past karts with a lower count, and karts still in play stay ahead of eliminated ones.
    /* 48 */ u16 mRankIndex;
    /* 4a */ u8 mUnk_4a[2];
    // The kart's count: balloons held where the balloon object exists (MODE_BATTLE with BATTLE_KIND_BALLOON, and
    // MODE_MISSION_RUN), shines held in the shine battle (MODE_BATTLE with BATTLE_KIND_SHINE). -1 for an unused slot
    // and for a kart eliminated in MODE_BATTLE; 0 at the start; changed in steps of +1 / -1. The rank order is sorted
    // by it.
    /* 4c */ s32 mBalloonOrShineCount;
    /* 50 */ u16 mBalloonsLeftToMake;
    /* 52 */ u8 mUnk_52[0x12];
    /* 64 */ s32 mMicInflateTimer;
    /* 68 */ s32 mSelectKeyInflate;
    /* 6c */ s32 mInflatingBalloon;
} KartStanding;

// The per-kart table of the modes that play with kart counts: ranks, eliminations, winning side and end timer.
typedef struct Standings {
    // One KartStanding per kart index; the entries past the kart count are unused slots.
    /* 000 */ KartStanding mKarts[8];
    // Called by CallKartCollisionCallbacks in Battle with the hit kart index and the other kart index when the other
    // kart has KART_DRIVE_KINOKO_BOOST and has not hit it before, the hit kart is not guarded, and the two karts are
    // not hitting each other; set by the balloon object, its result is returned to the collision code.
    /* 380 */ s32 (*mKartHitByKartCallback)(s32, s32);
    // Called by CallKartCollisionCallbacks in Battle with both kart indices when both karts have
    // KART_DRIVE_KINOKO_BOOST, neither is guarded and neither has hit the other before; set by the balloon object.
    /* 384 */ void (*mKartsHitEachOtherCallback)(s32, s32);
    // Called with the hit kart index and the index of the kart that hit it (8 when none) when a hit of the kart ends,
    // and for a kart that hit itself; set by the balloon object and the shine mode, which take a balloon or shine from
    // the hit kart.
    /* 388 */ s32 (*mKartHitCallback)(u16, u16);
    // Called with the kart index at the start of an elimination. Set by the balloon object (releases the kart's
    // balloons, in MODE_BATTLE only) and by the shine mode (drops one of the kart's shines).
    /* 38c */ void (*mKartEliminatedCallback)(u16);
    // Called when mEndTimer runs out and by FinishStandings in MODE_MISSION_RUN. Set by the balloon object, the shine
    // mode and the overlay 1 mission objects.
    /* 390 */ void (*mEndCallback)(void);
    /* 394 */ u8 mUnk_394[8];
    // Called in Battle with the kart index and the address of a Vec3 when a kart is moved: the position change of
    // PlaceKartAtKeyedPlacement, the position change in ResetKartAtRaceEnd, and the mPosStep of a Bound, Cream or Berry
    // that a kart hit (CollideKartWithBound); set by the balloon object, which adds that Vec3 to the positions of the
    // kart's balloons.
    /* 39c */ void (*mKartOffsetCallback)(u16, Vec3 *);
    // Number of Shine16 objects started and not yet finished: AddShineCount changes it (+1 when one is placed on the
    // course or released from a hit kart, -1 when one finishes); UpdateShineBattle stops placing at 3. Parking every
    // shine at once, as the shine mode's end callback does, does not subtract.
    /* 3a0 */ u16 mShineCount;
    /* 3a2 */ u16 mTimeLimitSeconds;
    /* 3a4 */ u16 mTimeLimitIndex;
    /* 3a6 */ u8 mUnk_3a6[2];
    // Frames left before mEndCallback runs once a winner is decided: MODE_BATTLE stores STANDINGS_END_FRAMES and
    // UpdateStandings counts it down; at 0 it becomes -1 and the callback runs. A value below 0 means the end is
    // reached. MODE_MISSION_RUN stores 0 and ends through FinishStandings (called by the race-progress end step), which
    // sets -1 and runs the callback.
    /* 3a8 */ s32 mEndTimer;
    // Highest KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort: MoveKartTowardFirstRank
    // and MoveKartTowardLastRank recompute it, and AddBalloonOrShineCountAndMoveRank calls one of them whenever its
    // amount is not 0.
    /* 3ac */ s32 mHighestBalloonOrShineCount;
    // Lowest non-negative KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort; 0xffff when no
    // kart has a non-negative count.
    /* 3b0 */ s32 mLowestBalloonOrShineCount;
    // Team id (KartStanding.mTeamId) of the winning team, -1 until a winner is decided. Set once every kart still in
    // play has the id of the rank 0 kart. In MODE_MISSION_RUN the ids are kart indices (it is compared with the local
    // entry index).
    /* 3b4 */ s32 mWinnerTeamId;
    /* 3b8 */ u16 mBattlePointIndex;
    /* 3ba */ u8 mUnk_3ba[2];
    // Pointer to entry 0 of the kind 0x69 object's KartBalloons array; set once by InitKartBalloons.
    /* 3bc */ struct KartBalloons *mKartBalloons;
} Standings;

// The Standings object, allocated by InitStandings in MODE_BATTLE and MODE_MISSION_RUN.
extern Standings *gStandings;

static inline KartStanding *GetKartStanding(u16 kartIndex) {
    return &gStandings->mKarts[kartIndex];
}
// One key rectangle of a keyboard layout: its position and size, the offset to the next rect of the same key
// (mNextRectOffset) and its key id.
typedef struct KeyboardRect {
    /* 00 */ u8 mX;
    /* 01 */ u8 mY;
    /* 02 */ u8 mWidth;
    /* 03 */ u8 mHeight;
    /* 04 */ s16 mNextRectOffset;
    /* 06 */ u16 mKeyId;
} KeyboardRect;

struct Ncgr;
struct KeyboardKeys;

// A keyboard layout: its key rectangles (mRects), the graphics (mNcgr) and the mCallback run with the KeyboardKeys.
typedef struct KeyboardLayout {
    /* 00 */ KeyboardRect *mRects;
    /* 04 */ struct Ncgr *mNcgr;
    /* 08 */ void (*mCallback)(struct KeyboardKeys *);
    /* 0c */ u16 mFixedKeyCount;
    /* 0e */ u16 mRectCount;
} KeyboardLayout;

static inline KeyboardRect *GetKeyboardLayoutRect(KeyboardLayout *layout, u32 rectIndex) {
    return &layout->mRects[rectIndex];
}

// A key repeat counter: mRepeatFrames counts against the first and repeat fire frames, mFired is set at either.
typedef struct RepeatCounter {
    /* 00 */ u16 mRepeatFrames;
    /* 02 */ u16 mFirstFireFrame;
    /* 04 */ u16 mRepeatFireFrame;
    /* 06 */ u16 mFired;
} RepeatCounter;

// The keyboard key repeat: a RepeatCounter (mCounter), the key bits that can repeat (mKeyMask) and the key bits now
// repeating (mRepeatKeys).
typedef struct KeyboardKeyRepeat {
    /* 00 */ RepeatCounter mCounter;
    /* 08 */ u16 mKeyMask;
    /* 0a */ u16 mRepeatKeys;
} KeyboardKeyRepeat;

// The keys of the on-screen keyboard: its buttons, layouts, touched and chosen keys, cursor and key callbacks.
typedef struct KeyboardKeys {
    /* 00 */ KeyboardRect mButton0Rect;
    /* 08 */ KeyboardRect mButton1Rect;
    /* 10 */ KeyboardRect *mTouchStartRect;
    /* 14 */ KeyboardRect *mTouchRect;
    /* 18 */ KeyboardRect *mKeyDownRect;
    /* 1c */ KeyboardLayout mLayout;
    /* 2c */ KeyboardLayout *mCurrentLayout;
    /* 30 */ u16 *mCharMap;
    /* 34 */ RepeatCounter mTouchRepeat;
    /* 3c */ u16 mKeyId;
    /* 3e */ u16 mKeyValue;
    /* 40 */ u16 mChosenKeyId;
    /* 42 */ u16 mToggledKeyId;
    /* 44 */ KeyboardRect *mCursorRect;
    /* 48 */ u8 mUnk_48[4];
    /* 4c */ u16 (*mCursorCallback)(s32, u16);
    /* 50 */ s32 (*mKeyCallback)(u32, s32);
} KeyboardKeys;

extern KeyboardKeys gKeyboardKeys;
extern KeyboardKeyRepeat gKeyboardKeyRepeat;
// The keyboard input state: the keys pressed, down and released and the touch position, hold frames and status.
typedef struct KeyboardInput {
    /* 00 */ s32 mCountedKeyFrames;
    /* 04 */ u16 mKeysPressed;
    /* 06 */ u16 mKeysDown;
    /* 08 */ u16 mKeysReleased;
    /* 0a */ u16 mCountedKeys;
    /* 0c */ u16 mPrevSample[4];
    /* 14 */ u16 mLastTouchX;
    /* 16 */ u16 mLastTouchY;
    /* 18 */ s32 mTouchHeldFrames;
    /* 1c */ s32 mTouchStatus;
    /* 20 */ u16 mTouchDown;
    /* 22 */ u16 mUnk_22;
    /* 24 */ BOOL mTouchEnabled;
} KeyboardInput;

extern KeyboardInput gKeyboardInput;
extern u16 *gKbdmapAscii;
extern u16 *gKbdmapOther1;
extern u16 *gKbdmapOther2;
extern u16 *gKbdmapOther3;
extern u16 *gKbdmapKatakana;
extern u16 *gKbdmapAsciiShift;
extern u16 *gKbdmapKatakanaDakuten;
extern u16 *gKbdmapHiraganaDakuten;
extern u16 *gKbdmapHiraganaHandaku;
extern u16 *gKbdmapHiraganaSmall;
extern u16 *gKbdmapAsciiCaps;
extern u16 *gKbdmapKatakanaHandaku;
extern u16 *gKbdmapKatakanaSmall;
// The on-screen keyboard's text entry: BG2 data, key graphics, the text buffer (mText) and the two button rectangles.
typedef struct KeyboardTextEntry {
    /* 00 */ void *mBg2Char;
    /* 04 */ void *mBg2Scr;
    /* 08 */ s32 mBg2CharSize;
    /* 0c */ s32 mBg2ScrSize;
    /* 10 */ struct Ncgr *mNcgrs[6];
    /* 28 */ void *mKbds[6];
    /* 40 */ u16 *mText;
    /* 44 */ u16 mTextCapacity;
    /* 46 */ u16 mTextIndex;
    /* 48 */ u16 mTextIndexCopy;
    /* 4a */ u16 mTextLimit;
    /* 4c */ s32 mLayoutIndex;
    /* 50 */ s32 mOffsetX;
    /* 54 */ s32 mOffsetY;
    /* 58 */ s32 mButton0X0;
    /* 5c */ s32 mButton0Y0;
    /* 60 */ s32 mButton0X1;
    /* 64 */ s32 mButton0Y1;
    /* 68 */ s32 mButton1X0;
    /* 6c */ s32 mButton1Y0;
    /* 70 */ s32 mButton1X1;
    /* 74 */ s32 mButton1Y1;
} KeyboardTextEntry;

extern KeyboardTextEntry *gKeyboardTextEntry;
extern u16 *gKbdmapHiragana;
// The functions of a title scene state: one writes the registers and one updates each frame.
typedef struct TitleStateHandlers {
    /* 00 */ void (*mWriteRegisters)(void);
    /* 04 */ void (*mUpdate)(s32);
} TitleStateHandlers;

struct LayoutTableEntry;
struct LayoutEntryTable;

// Values of TitleScene.mSelectedIndex, in the order of the scenes they start (SCENE_MENU, SCENE_WL_MENU,
// SCENE_WIFI_MENU, SCENE_OPTION, SCENE_RECORD); Option and Record share the last row.
enum {
    TITLE_ENTRY_FIRST,
    TITLE_ENTRY_WL_MENU,
    TITLE_ENTRY_WIFI_MENU,
    TITLE_ENTRY_OPTION,
    TITLE_ENTRY_RECORD,
};

// x offset of the title cells at the slide in start and slide out end, and the mNextState that names no state.
#define TITLE_OFFSCREEN_X 0xf8
#define TITLE_NEXT_STATE_NONE 8

// TitleScene.mState, mPrevState and mNextState values, in the order of gTitleStateHandlers.
#define TITLE_STATE_BLEND_IN 0
#define TITLE_STATE_SLIDE_IN 1
#define TITLE_STATE_MENU_INPUT 2
#define TITLE_STATE_SLIDE_OUT 3
// The pressed entry (not Option or Record) moves by TitleScene.mSelectedOffset for 10 frames, then the table slides
// out.
#define TITLE_STATE_SELECT_PRESS 4
#define TITLE_STATE_LEAVE 5
#define TITLE_STATE_REQUEST_NICKNAME_SCENE 6

// The title scene: its state machine, the selected entry, the title files and the main and sub OAM lists.
typedef struct TitleScene {
    /* 000 */ s32 mStateFrames;
    // TRUE from every change of state (and creation) until the current state's handler has run; nothing reads it.
    /* 004 */ BOOL mStateChanged;
    /* 008 */ s32 mPrevState;
    /* 00c */ s32 mState;
    /* 010 */ s32 mNextState;
    /* 014 */ TitleStateHandlers mStateHandlers[7];
    /* 04c */ s32 mNoInputFrames;
    /* 050 */ BOOL mBlendDone;
    /* 054 */ s32 mSelectedIndex;
    /* 058 */ BOOL mStartedOnSelected;
    // TRUE when a move down from the Wi-Fi menu entry or up from the first entry goes to record, not option.
    /* 05c */ BOOL mPreferRecordEntry;
    /* 060 */ s16 mSelectedOffset;
    /* 064 */ s32 mBlendFrames;
    /* 068 */ struct LayoutTableEntry *mTitleTable;
    /* 06c */ struct LayoutEntryTable *mTitleSBncl;
    /* 070 */ void *mTitleSBnbl;
    /* 074 */ struct LayoutEntryTable *mTitleSBnll;
    /* 078 */ struct Nclr *mTitleTrueMBOrMBNclr;
    /* 07c */ struct Ncgr *mTitleTrueMBOrMBNcgr;
    /* 080 */ struct Nclr *mTitleSBNclr;
    /* 084 */ struct Ncgr *mTitleSBNcgr;
    /* 088 */ struct Nscr *mTitleTrueM1OrM1Nscr;
    /* 08c */ struct Nscr *mTitleTrueM2OrM2Nscr;
    /* 090 */ struct Nscr *mTitleSBgNscr;
    /* 094 */ u8 mUnk_94[0xc];
    /* 0a0 */ struct Nclr *mTitleSONclr;
    /* 0a4 */ struct Ncgr *mTitleSNceNcgr;
    /* 0a8 */ struct NNSG2dCellDataBank *mTitleSNceNcer;
    /* 0ac */ u8 mUnk_ac[4];
    /* 0b0 */ OamEntryList mMainOam;
    /* 4b4 */ OamEntryList mSubOam;
    /* 8b8 */ struct CharacterKartPicks *mCharacterKartPicks;
} TitleScene;

extern TitleScene *gTitleScene;
extern u64 gLastTick;
// The affine matrix, center and start position (mX1, mY1) of the sub screen background.
typedef struct RaceHudSubScreenBgAffine {
    /* 00 */ s32 mMatrix0;
    /* 04 */ s32 mMatrix1;
    /* 08 */ s32 mMatrix2;
    /* 0c */ s32 mMatrix3;
    /* 10 */ s32 mCenterX;
    /* 14 */ s32 mCenterY;
    /* 18 */ s32 mX1;
    /* 1c */ s32 mY1;
} RaceHudSubScreenBgAffine;

// Values of RaceHud.mSubScreenState: the pages of the sub screen. The first four show the course from above: the kart
// icons placed over the whole course, the map turning with the camera angle, the map with a fixed angle that scrolls,
// and the map placed by the course map sub screen view. The goal pages list the finished karts or the teams; the last
// is the new-record page.
typedef enum {
    RACE_HUD_SUB_SCREEN_KART_ICONS,
    RACE_HUD_SUB_SCREEN_MAP_TURNING,
    RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL,
    RACE_HUD_SUB_SCREEN_MAP_VIEW,
    RACE_HUD_SUB_SCREEN_GOAL_KARTS,
    RACE_HUD_SUB_SCREEN_GOAL_TEAMS,
    RACE_HUD_SUB_SCREEN_NEW_RECORD
} RaceHudSubScreenState;

// The race's on-screen display (gRaceHud): the sprite entry buffers, loaded graphics and the sub screen page state.
typedef struct RaceHud {
    // Calls of UpdateRaceHud that get past the START_GP, AWARD and STAFF_ROLL kinds and the mEnabled test; wraps to 0
    // at RACE_HUD_UPDATE_FRAMES_WRAP. UploadRaceHud scrolls the KART_ICONS page by value / 6 and GetRaceHudUpdateFrames
    // (value / 32) is read by UpdateRaceHudSubScreenBg3CenterByFrames.
    /* 000 */ s32 mUpdateFrames;
    /* 004 */ RaceHudOamBuffer mMainOam;
    /* 408 */ RaceHudOamBuffer mSubOam;
    /* 80c */ struct Nclr *mNclrs[2];
    /* 814 */ struct Ncgr *mNcgrs[2];
    /* 81c */ struct Nscr *mNscrs[3];
    // RaceHudSubScreenState page of the sub screen (reg_GXS_DB_* / reg_G2S_DB_* = sub engine), switched on by the step,
    // the draw and the upload slot; assigned by UpdateRaceHudSubScreen (per mode and race state),
    // RequestRaceHudSubScreenGoalTeams (RaceGoalS teams) and RequestRaceHudSubScreenNewRecord (RaceNewRecordTa). The
    // player switches the icons page and the first map page with sounds 0x18 / 0x17.
    /* 828 */ s32 mSubScreenState;
    // Gate of the sub screen's page update and page upload.
    /* 82c */ BOOL mSubScreenEnabled;
    // Set when the goal teams page is requested; the upload copies its graphics once and clears it.
    /* 830 */ BOOL mSubScreenGoalTeamsUploadRequested;
    // Set when the new record page is requested; the upload copies its graphics once and clears it.
    /* 834 */ BOOL mSubScreenNewRecordUploadRequested;
    /* 838 */ BOOL mRaceGoalSShown;
    /* 83c */ BOOL mGoalMStarted;
    /* 840 */ BOOL mGoalMUploadPending;
    /* 844 */ s32 mGoalMUploadFrames;
    /* 848 */ s32 mGoalMUploaded;
    /* 84c */ s32 mGoalMEnabled;
    /* 850 */ s32 mGoalMDelayFrameCount;
    /* 854 */ s32 mSubScreenCourseScale;
    /* 858 */ RaceHudSubScreenBgAffine mSubScreenBgAffines[2];
    // FALSE from InitRaceHud until the scene's screen set-up SetupRaceHudScreens ends and sets it TRUE (never cleared
    // again); the step, the draw, the page choice and the upload slot return at once while FALSE.
    /* 898 */ BOOL mEnabled;
    /* 89c */ s32 mKartRemoved[8];
    /* 8bc */ s32 mRemovedSoundPlayed[8];
    /* 8dc */ s32 mShowLapTime;
    /* 8e0 */ s32 mShowLapTimeFrames;
    // Set once in InitRaceHud: 1 only in MODE_TIME_ATTACK with more than one kart; gates StartRaceHudLapTimeDisplay
    // (the computation) and the draw of the time difference.
    /* 8e4 */ s32 mUseTimeDifference;
    // ComputeTimeDifference's return: non-zero when the followed kart's summed lap times (GetKartLapTime) are >= the
    // summed ghost lap times (gRaceSetup.mGhostLapTimes); the draw picks the sign cell by it.
    /* 8e8 */ s32 mTimeDifferenceSign;
    // The difference as seven digits (SplitTimeDigits), written by StartRaceHudLapTimeDisplay, read through
    // GetRaceHudTimeDifference by the draw.
    /* 8ec */ TimeDigits mTimeDifferenceDigits;
    // 1 once the per-frame step has run.
    /* 908 */ s32 mStepHasRun;
    /* 90c */ BOOL mUnfilledNotEliminatedSet;
    /* 910 */ s32 mMissionRunRecordFilled;
} RaceHud;

struct ChoisesS;
struct RaceNcerNclrNcgrTables;
// An x and y position (mX, mY) of a row of the race rank list.
typedef struct RaceRankListPos {
    /* 00 */ s32 mX;
    /* 04 */ s32 mY;
} RaceRankListPos;

// One item in use in the race rank list: mInUseFrames, mItemInfoIndex and mObjectCount.
typedef struct RaceRankListItemInUse {
    /* 00 */ s32 mInUseFrames;
    /* 04 */ s32 mItemInfoIndex;
    /* 08 */ s32 mObjectCount;
} RaceRankListItemInUse;

// The rank list of the race HUD: per row positions, shown items, ranks and karts by rank, the slide and the matrix.
typedef struct RaceRankList {
    /* 000 */ RaceRankListPos mRowPositions[8];
    /* 040 */ s32 mShownItems[8];
    /* 060 */ s32 mPrevRanks[8];
    /* 080 */ s32 mRanks[8];
    /* 0a0 */ s32 mKartsByRank[8];
    /* 0c0 */ s32 mBalloonOrShineCounts[8];
    /* 0e0 */ s32 mSlideX;
    /* 0e4 */ u16 mOamMatrixIndex;
    /* 0e6 */ u8 mUnk_0e6[2];
    /* 0e8 */ MtxFx22 mMatrix;
    /* 0f8 */ u16 mMoveFrames;
    /* 0fa */ u8 mUnk_0fa[2];
    /* 0fc */ RaceRankListItemInUse mItemsInUse[8];
} RaceRankList;

// The cell groups of the race HUD sub screen: a scale and the clear, update and draw functions of each group.
typedef struct RaceHudSubScreenCellGroups {
    /* 000 */ u16 mMinDrawValue;
    /* 004 */ s32 mScale;
    /* 008 */ s32 mInverseScale;
    /* 00c */ s32 mGroupCount;
    /* 010 */ void (*mClearFunctions[49])(void);
    /* 0d4 */ void (*mUpdateFunctions[49])(void);
    /* 198 */ void (*mDrawFunctions[49])(RaceHudOamBuffer *);
} RaceHudSubScreenCellGroups;

// Values of RaceGoalS.mOffsetState: the panel offset slides in (ENTER), stays (HOLD) and slides out (LEAVE); FIRST,
// SECOND and LAST are the three stages, each drawn with its own cell (LAST blinks). FIRST ends when the rows are hidden
// or the wifi pick is locked, SECOND only when the wifi pick is locked; LAST is also reached directly from LEAVE_FIRST
// when the wifi pick is locked. START goes to HIDDEN unless mUpdate is SlideInRaceGoalS. LEAVE_END (from FIRST when
// mUpdate is SlideOutRaceGoalS) is the slide out before HIDDEN.
enum {
    RACE_GOAL_S_OFFSET_START,
    RACE_GOAL_S_OFFSET_ENTER_FIRST,
    RACE_GOAL_S_OFFSET_HOLD_FIRST,
    RACE_GOAL_S_OFFSET_LEAVE_FIRST,
    RACE_GOAL_S_OFFSET_ENTER_SECOND,
    RACE_GOAL_S_OFFSET_HOLD_SECOND,
    RACE_GOAL_S_OFFSET_LEAVE_SECOND,
    RACE_GOAL_S_OFFSET_ENTER_LAST,
    RACE_GOAL_S_OFFSET_HOLD_LAST,
    RACE_GOAL_S_OFFSET_LEAVE_END,
    RACE_GOAL_S_OFFSET_HIDDEN,
};

// Phases of RaceGoalS: pressing A ends a phase once PHASE_FRAMES frames have passed (HideRaceGoalSRows also ends by
// itself at that frame). Hiding or showing the rows changes one row every ROW_STEP_FRAMES frames and plays the sound
// sequence with the id FIRST plus the row index; CountUpRaceGoalSNumbers adds 1 to each shown number at the same rate.
#define RACE_GOAL_S_HIDE_ROW_SEQ_FIRST 0x32
#define RACE_GOAL_S_SHOW_ROW_SEQ_FIRST 0x2a
#define RACE_GOAL_S_ROW_STEP_FRAMES 5
#define RACE_GOAL_S_PHASE_FRAMES 0x2d
// Values of RaceGoalS.mRankComparison (a row moved down, moved up, or stayed), the largest points number counted up on
// a row, and the frames and distance of the slide in.
// Styles of a RaceGoalS row (WriteRaceGoalSRowTiles): the followed kart, another kart, a row not shown yet.
#define RACE_GOAL_S_ROW_STYLE_FOLLOWED 0
#define RACE_GOAL_S_ROW_STYLE_OTHER 1
#define RACE_GOAL_S_ROW_STYLE_HIDDEN 2
#define RACE_GOAL_S_RANK_DOWN 0
#define RACE_GOAL_S_RANK_UP 1
#define RACE_GOAL_S_RANK_SAME 2
#define RACE_GOAL_S_SHOWN_NUMBER_LIMIT 0x3e8
#define RACE_GOAL_S_SLIDE_FRAMES 0x14
#define RACE_GOAL_S_SLIDE_OFFSET 0x100

// The race results list: row visibility, shown numbers, kart indexes, update function, graphics and screen maps.
typedef struct RaceGoalS {
    /* 0000 */ s32 mRowVisible[8];
    /* 0020 */ s32 mShownNumbers[8];
    /* 0040 */ s32 mRowKartIndex[8];
    /* 0060 */ s32 mPreviousRowKartIndex[8];
    /* 0080 */ s32 mRankComparison[8];
    /* 00a0 */ s32 mOffsetX;
    // 1 from the first results step (the race is done) until the last results step clears it; 0 in Time Trial.
    /* 00a4 */ s32 mRunning;
    /* 00a8 */ s32 mHiddenRowCount;
    /* 00ac */ void (*mUpdate)(void);
    /* 00b0 */ s32 mUpdateFrames;
    /* 00b4 */ s32 mCourseCountReached;
    /* 00b8 */ PaletteAndChars mRaceGoalSB;
    /* 00c0 */ struct Nscr *mRaceGoalSNscrs[6];
    /* 00d8 */ u16 mRaceGoalSSpaceNscrCopies[2][0x800];
    /* 20d8 */ s32 mOffsetState;
    /* 20dc */ s32 mOffsetStateFrames;
    /* 20e0 */ s32 mOffset;
} RaceGoalS;

extern RaceGoalS *gRaceGoalS;
extern struct MenuScene *gMenuScene;
// The same pointer as gWaterEfct, stored by SetCourseWaterEfct (the last call of CreateWaterEfct) and set to NULL in
// InitMapObjects; the three water_efct file getters, GetHeightAboveWaterOrEfct and IsFarBelowWaterEfct read this one.
extern WaterEfct *gCourseWaterEfct;
extern Vec3 *gFoundMapObjectVectors;
extern s32 gMapObjectsTimeAttackOrWiFi;
// The same pointer as gWater, stored by SetCourseWater (the last call of each Create...Water) and set to NULL in
// InitMapObjects before the objects are created, so NULL means the course has no water; the update, draw, getters and
// camera read this one, while gWater (never cleared) is only the creators' variable.
extern struct Water *gCourseWater;
extern s32 gMapObjectKindCount;
extern struct MapObjects *gMapObjects;
extern u16 gItemBoxShadowAngle;
extern MapObjectDrawList *gQuestionDrawList;
extern BoxRotation *gBoxRotations;
extern QuestionRotation *gQuestionRotations;
extern MapObjectDrawList *gBoxDrawList;
extern NsbmdModel *gQuestion;
extern MapObjectDrawList *gItemBoxShadowDrawList;
extern MapObjectList *gItemBoxUpdateList;
extern NsbmdModel *gBox;
extern MtxFx43 gItemBoxShadowMatrix;
extern s32 gKouraWBlockTimer;
extern s32 gThunderBlockTimer;

// The mode counter of the race HUD: a number (also read as two halves), the mission run limit and a recording flag.
typedef struct RaceModeCount {
    /* 00 */ union {
        s32 mNumber;
        u16 mNumberHalves[2];
    };
    /* 04 */ s32 mMissionRunCountLimit;
    // 1 from init; cleared by DrawRaceModeCount in MODE_TIME_ATTACK once gInputSlots[0] is INPUT_SOURCE_PAD_RECORDED
    // and its key recording is full; IsRaceKeyRecordingNotFull reads it.
    /* 08 */ BOOL mKeyRecordingNotFull;
} RaceModeCount;

// Scale spring of the item cells: frame counter, x and y scale, y-scale per-frame increment and target (fx32).
typedef struct RaceItemSlotScale {
    /* 00 */ s32 mScaleFrames;
    /* 04 */ s32 mScaleX;
    /* 08 */ s32 mScaleY;
    /* 0c */ s32 mScaleYPerFrame;
    /* 10 */ s32 mScaleYTarget;
} RaceItemSlotScale;

// The item slot roulette of the race HUD: its scroll position, running state, the items shown and its scale.
typedef struct RaceItemSlot {
    /* 00 */ s32 mScrollY;
    /* 04 */ s32 mSlotFrames;
    /* 08 */ s32 mUpperItem;
    /* 0c */ s32 mLowerItem;
    /* 10 */ BOOL mSlotRunning;
    /* 14 */ BOOL mPrevSlotRunning;
    /* 18 */ RaceItemSlotScale mScale;
} RaceItemSlot;

// The time digits of the race HUD, with the flag and the marks of the last seconds sound.
typedef struct RaceTimeDigits {
    /* 00 */ TimeDigits mTime;
    /* 1c */ BOOL mUseLastSecondsSound;
    /* 20 */ s32 mLastSecondsReached[6];
} RaceTimeDigits;

// Values of RaceTaPositionSample.mKind: which cell the trail sample draws.
// Position samples kept per kart for the time attack trail, and the frames between two ageing steps of the boost point
// samples (an age of the sample count means the point is gone).
#define RACE_TA_SAMPLE_COUNT 0x28
#define RACE_TA_SAMPLE_FRAME_COUNT 0xf
#define RACE_TA_SAMPLE_KIND_NONE 0
#define RACE_TA_SAMPLE_KIND_PLAIN 1
#define RACE_TA_SAMPLE_KIND_HOPPING_OR_DRIFTING 2
#define RACE_TA_SAMPLE_KIND_BOOSTING 3

// One sampled Time Attack position: its position, angle, kind and priority.
typedef struct RaceTaPositionSample {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mAngle;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ s32 mKind;
    /* 14 */ s32 mPriority;
} RaceTaPositionSample;

// The mushroom boost points kept for one Time Attack kart: three positions with their priorities and age samples.
typedef struct RaceTaKinokoBoostPoints {
    /* 00 */ s32 mPointCount;
    /* 04 */ Vec3 mPositions[3];
    /* 28 */ s32 mPriorities[3];
    /* 34 */ s32 mAgeSamples[3];
} RaceTaKinokoBoostPoints;

// The Time Attack position display: per kart the sampled positions, the mushroom boost points and the rotations.
typedef struct RaceTaPositions {
    /* 000 */ s32 mVisible;
    /* 004 */ s32 mKartVisible[2];
    /* 00c */ s32 mSampleFrames;
    /* 010 */ RaceTaPositionSample mSamples[2][0x28];
    /* 790 */ RaceTaKinokoBoostPoints mKinokoBoostPoints[2];
    /* 810 */ MtxFx22 mRotations[16];
} RaceTaPositions;

// The link level of the race HUD: the link and Wi-Fi link level and whether a friend is on.
typedef struct RaceLinkLevel {
    /* 00 */ s32 mLinkLevel;
    /* 04 */ s32 mWiFiLinkLevel;
    /* 08 */ s32 mFriendOnFrames;
    /* 0c */ s32 mPrevFriendOn;
    /* 10 */ s32 mFriendOn;
} RaceLinkLevel;

// The lap number of the race HUD: the current, previous and last lap index and the blink state.
typedef struct RaceLapNumber {
    /* 00 */ s32 mLapIndex;
    /* 04 */ s32 mPrevLapIndex;
    /* 08 */ s32 mLastLapIndex;
    /* 0c */ s32 mBlinkFrames;
    /* 10 */ s32 mBlinkShown;
} RaceLapNumber;

// The second hand of the race HUD sub screen: the objects it is made of, three angles and its draw and end positions.
typedef struct RaceHudSubScreenSecondHand {
    /* 00 */ struct Vehicle **mObjects;
    /* 04 */ s32 mCreatedObjectCount;
    /* 08 */ s32 mObjectCount;
    /* 0c */ u16 mAngles[3];
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ IntPair mDrawPositions[3];
    /* 2c */ IntPair mEndPositions[3];
} RaceHudSubScreenSecondHand;

// The kart icons of the race HUD sub screen: per kart visibility, position, scale, angle, draw order and mCells.
typedef struct RaceHudSubScreenKarts {
    /* 000 */ s32 mVisible[8];
    /* 020 */ s32 mSpriteHidden[8];
    /* 040 */ s32 mXlu[8];
    /* 060 */ IntPair mScreenPos[8];
    /* 0a0 */ Vec3 mScale[8];
    /* 100 */ u16 mAngle[8];
    /* 110 */ s32 mNonNormalStateFrames[8];
    /* 130 */ s32 mDrawOrder[8];
    /* 150 */ s32 mPriority[8];
    /* 170 */ s32 mStarFrames[8];
    /* 190 */ RaceHudSubScreenCells *mCells;
} RaceHudSubScreenKarts;

extern u16 gMapObjectLastPolygonId;
extern u16 gWrappingPolygonId;
extern u16 gWrappingPolygonIdBase;
extern u16 gMapObjectFirstPolygonId;
extern u16 gNextPolygonId;
extern GrpconfTblRow *gGrpconfTbl;
extern MapObject **gFoundMapObjects;
struct ItemObject;

// The canvas of the on-screen keyboard: its font, background chars and screen map, size, top bits and glyph color.
typedef struct KeyboardCanvas {
    /* 00 */ struct NNSG2dFont *mFont;
    /* 04 */ void *mBg2Char;
    /* 08 */ void *mMarkedBg2Char;
    /* 0c */ u16 *mBg2Scr;
    /* 10 */ s32 mScreenMapWidth;
    /* 14 */ s32 mScreenMapHeight;
    /* 18 */ s32 mScreenMapTopBits;
    /* 1c */ s32 mScreenMapTileBase;
    /* 20 */ s32 mGlyphColor;
} KeyboardCanvas;

struct BmgEntryOffsetSection;
struct BmgBodySection;
struct Nclr;
struct NNSG2dCellDataBank;
extern struct Nclr *gPlayerCharacterNclr[2];
extern struct Ncgr *gPlayerCharacterNcgr[2];
extern struct NNSG2dCellDataBank *gPlayerCharacterNcer[2];
extern void *gPlayerCharacterBncl[2];
extern struct Nclr *gPlayerCharacterShyguyNclr[2];
extern struct NNSG2dFont *gFontTable[3];
extern struct NNSG2dFont gLCFontS;
extern struct NNSG2dFont gLCFontM;
extern struct NNSG2dFont gMarioFont;
extern RaceHudSubScreenCells *gRaceHudSubScreenItemBoxCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenDossunCells;

static inline RaceHudSubScreenCell *GetRaceHudSubScreenDossunCell(u32 cellIndex) {
    return &gRaceHudSubScreenDossunCells->mCells[cellIndex];
}
// Which model the Jg shows: its row in gJgKindRows (the lap_count, lap_final, jg_reverse and jg_flag models; none).
extern s32 gJgKind;
#define JG_KIND_LAP_COUNT 0
#define JG_KIND_LAP_FINAL 1
#define JG_KIND_REVERSE 2
#define JG_KIND_FLAG 3 // shown when the entry kart has reached the goal (not in mission run mode)
#define JG_KIND_NONE 4
extern s32 gJgSnapUntilPushFlip;
extern s32 gJgCheckpointFlagFrames;
extern s32 gJgVisible;
extern s32 gJgLapKindActive;

// gJgStateMachine.mState values, in the order of gJgStateTable. OFF is the idle state; REVERSE, LAP and FLAG follow
// the kart with the model of that kind (the jg_reverse and jg_flag files, the lap model); FOLLOW_KART waits at the
// kart; LEAVE rises out of view and ends in OFF; ARRIVE lowers in from above and picks LAP, FLAG or LEAVE by kind.
enum {
    JG_STATE_OFF,
    JG_STATE_REVERSE,
    JG_STATE_LAP,
    JG_STATE_FLAG,
    JG_STATE_FOLLOW_KART,
    JG_STATE_LEAVE,
    JG_STATE_ARRIVE,
};

extern StateMachine gJgStateMachine;
extern void **gFoundCollisionSlotObjects;
extern s16 gFoundCollisionSlotCount;
extern u16 *gFoundCollisionSlotFlags;
extern s16 gFirstFreeCollisionSlot;
extern s16 gCollisionSlotCount;
extern struct CollisionSlotEnd *gCollisionSlotHighEnds;
extern struct CollisionSlot *gCollisionSlots;
extern struct CollisionSlotEnd *gCollisionSlotLowEnds;
extern s16 *gCollisionSlotNextFree;
extern s16 *gFoundCollisionSlotIndices;
extern s32 gJgStateCounter;
extern u16 gJgFinalLap;
extern u16 gJgLapFrameCount;
extern u16 gJgKartIndex;
extern u16 gJgProbeStep;
extern u16 gJgHighestLap;
extern s32 gJgShiftSpeedX;
extern s32 gJgShiftX;
extern s32 gJgHeightOffsetSpeed;
extern s32 gJgHeightOffset;
extern s32 gJgInView;
extern s32 gJgNearKart;
extern s32 gJgReverseAngleActive;
extern s32 gJgStartSideNotFlipped;
extern s32 gJgLapAndReverseEnabled;
extern u16 *gJgKartCourseColor;
extern Vec3 gJgTargetPos;
extern Vec3 gJgProbeCenter;
extern Vec3 gJgPreviousCollisionCenter;
extern Vec3 gJgCollisionCenter;
extern Vec3 gJgPreviousPos;
extern Vec3 gJgPos;
extern Vec3 gJgEasedPos;
extern Vec3 gJgKartMove;
extern Vec3 gJgVelocity;
extern Vec3 gJgPoints[];
extern s16 *gJgCloudOffsetYTable;
extern s16 *gJgMainRotationSineTable;
extern s16 *gJgMainRotationCosineTable;
extern s16 *gJgCloudScaleYTable;
extern s16 *gJgCloudScaleXTable;
extern s32 gJgTableIndex;
// Entries of each Jg cloud and rotation table; gJgTableIndex wraps at this count.
#define JG_TABLE_LENGTH 0x3c
extern Vec3 gJgArriveLocalTargetPos;
extern s32 gJgArriveSpeed;
extern s32 gJgArriveHeightOffset;
extern s32 gJgLeaveHeightOffset;
extern s32 gJgLeaveSpeed;
extern s32 gJgVelocityFactorX;
// Copy of the kart's position, y minus the kart's hop height (JG_STATE_FOLLOW_KART stores it without that, only while
// gJgStateCounter is 0).
extern Vec3 gJgKartPos;
extern Vec3 gJgNoModelOffset;
extern Vec3 gJgLapOffset;
extern Vec3 gJgLeaveLocalTargetPos;
extern Vec3 *gJgPointPointers[4];
extern u16 gJgAlpha;
extern u16 gJgAngle;
extern Vec3 gJgFlagOffset;
extern Vec3 gJgReverseOffset;
extern void *gSphereHitObjects[16];
extern s32 gJgOffsetY;
extern s32 gJgOffsetX;
extern s32 gJgFarFromKart;
extern u32 gJgCourseHitBits;
extern s32 gGessoBlockTimer;
// Number of items in gItemSlotPossibleItems: the items with a non-zero weight in some row of
// gItemSlotHumanGhostPeerTable or gItemSlotCpuTable. Set by CreateItemSlotTables.
extern u16 gItemSlotPossibleItemCount;
// Length of gItemSlotSpinItems; 0 means the spin uses gItemSlotPossibleItems.
extern u16 gItemSlotSpinItemCount;
extern u8 gItemDataDelayedFreeHead[];
extern u8 gItemDataQueueUsedHead[];
extern u8 gItemDataQueueFreeHead[];
extern u8 gItemDataDelayedUsedHead[];
extern MapObjectModel *gIronBall;
