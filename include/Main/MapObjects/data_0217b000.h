#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx22, NNSG3dResMatData
#include "Main/MapObjects/data_02165000.h" // BattleKartAiParams
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h" // ResFileEntry
#include "code_0212d214.h"
#include "Main/System/time_digits.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "ITCM/sphere_collision.h" // CourseCollision
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/data_0209bc74.h" // MapObjectModel
#include "Main/MapObjects/data_02158000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Menu/data_0217d000.h" // NNSG2dCharCanvas
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Graphics/code_02089fa0.h" // StemSet
#include "code_0214a748.h" // MtxFx44

struct RandomState64;
struct MapObjects;
struct Water;
struct MenuScene;
struct Nscr;
struct Ncgr;
struct Nclr;
struct NNSG2dFont;
struct KartBalloons;

// Element of 0x14 bytes of the table behind gBoxRotations.
typedef struct BoxRotation {
    /* 00 */ s32 mCosine;
    /* 04 */ s32 mSine;
    /* 08 */ s32 mCosineSquared;
    /* 0c */ s32 mSineSquared;
    /* 10 */ s32 mCosineSineProduct;
} BoxRotation;

// Element of 8 bytes of the table behind gQuestionRotations.
typedef struct QuestionRotation {
    /* 00 */ s32 mCosine;
    /* 04 */ s32 mSine;
} QuestionRotation;

// UnkPair020b502c of code_020b502c.h is this type.
typedef struct IntPair {
    /* 00 */ s32 mFirst;
    /* 04 */ s32 mSecond;
} IntPair;

// Priority stored for a sub-screen cell whose position is inside the box.
#define RACE_HUD_PRIORITY_INSIDE_BOX 3
// Priority stored for a sub-screen cell whose position is outside the box.
#define RACE_HUD_PRIORITY_OUTSIDE_BOX 2
typedef struct RaceHudSubScreenCell {
    /* 00 */ IntPair mDrawPos;
    /* 08 */ struct NNSG2dCellDataWithBR *mCell;
    /* 0c */ u16 mPriority;
    // Non-zero draws the cell translucent; the flipper cells use it as the mirror flag.
    /* 0e */ u16 mXlu;
    /* 10 */ u16 mAngle;
    /* 12 */ u8 mUnk_12[2];
} RaceHudSubScreenCell;

// Shared by the gRaceHudSubScreenItemBoxCells..gRaceHudSubScreenFireball2Cells lists and the ov001 pointers.
typedef struct RaceHudSubScreenCells {
    /* 00 */ MapObject **mObjects;
    /* 04 */ s32 mCellCount;
    /* 08 */ s32 mObjectCount;
    // One pair per object: its course position, or in the scaled lists a scale and a frame counter.
    /* 0c */ IntPair *mObjectPairs;
    /* 10 */ RaceHudSubScreenCell *mCells;
} RaceHudSubScreenCells;

// Halfwords from 0x02 of RaceHudSubScreenBgColors read by UpdateRaceHudSubScreenBgPalette when gRaceSetup.mCourseId is
// COURSE_ID_KOOPA: six, two rows of three and two.
typedef struct RaceHudSubScreenKoopaBgColors {
    /* 00 */ u16 mSecondObjectColors[6];
    /* 0c */ u16 mFirstObjectColors[2][3];
    /* 18 */ u16 mKoopaBlockColors[2];
} RaceHudSubScreenKoopaBgColors;

// The halfwords from 0x02 of RaceHudSubScreenBgColors as UpdateRaceHudSubScreenBgPalette and
// CopyRaceHudSubScreenBgColors index them for gRaceSetup.mCourseId: a run of 0x15 (TOWN, BEACH, MINI_STAGE3), nine
// rows of three (OLD_NOKO_SFC), five rows of four (CLOCK) and the KOOPA colours.
typedef union RaceHudSubScreenBgColorSets {
    u16 mColorList[0x15];
    u16 mFrameColors[9][3];
    u16 mGearColors[5][4];
    RaceHudSubScreenKoopaBgColors mKoopaColors;
} RaceHudSubScreenBgColorSets;

// Object behind gRaceHudSubScreenBgColors, 0x38 bytes (allocated by InitRaceHudSubScreenBgColors).
typedef struct RaceHudSubScreenBgColors {
    /* 00 */ u16 mUnk_00;
    /* 02 */ RaceHudSubScreenBgColorSets mColors;
} RaceHudSubScreenBgColors;

// Pair of numbers "course number, course count" drawn on the main screen before start-sequence frame 0xb4, only in mode
// 5 and in mode 3 with gRaceSetup.mUnk_1c == 2 (DrawRaceMNumberPair), one record behind gRaceMNumberPair (0x28
// bytes, InitRaceMNumberPair); mUnk_08 .. mUnk_20 are the slide-in animation state. mUnk_18 points into mUnk_08.
typedef struct RaceMNumberPair {
    // Copy of gRaceSetup.mCourseNumber taken in InitRaceMNumberPair.
    /* 00 */ s32 mCourseNumber;
    // Number of courses of the run: 4 in mode 5, gRaceSetup.mUnk_3d8 in mode 3 with mUnk_1c == 2, else 0 (not
    // drawn). mUnk_3d8 has another meaning (score threshold) in mode 2 and for mUnk_1c == 1; this member never copies
    // that one.
    /* 04 */ s32 mCourseCount;
    /* 08 */ MtxFx22 mScaleMatrix;
    /* 18 */ MtxFx22 *mCellMatrix;
    /* 1c */ s32 mScale;
    /* 20 */ u16 mMatrixIndex;
    /* 22 */ u8 mUnk_22[2];
    // X added to every sprite of the pair: 0, or eased by InterpolateS16 (SetRaceMNumberPairAnimation) for the
    // slide-in.
    /* 24 */ s32 mOffsetX;
} RaceMNumberPair;

typedef struct WaterEfct WaterEfct;

// Object at gViewFrustum: six vectors between words at 0x00/0x04 and 0x50/0x54.
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

// Object behind gEmblemChoises, 0x6c bytes (InitEmblemChoises allocates it); DrawEmblemChoises calls the function at
// 0x0c.
typedef struct EmblemChoises {
    /* 00 */ s32 mShown;
    /* 04 */ s32 mDrawnShown;
    /* 08 */ BOOL mGraphicsUploadRequested;
    /* 0c */ UnkFunc *mHideCallback;
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

// 16-byte rows of the table behind gGrpconfTbl (CreateMapObject reads the halfwords).
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

// Objects whose layout isn't known yet.
struct SPLManager;
struct KartAi;
struct KartAiItemUse;

// Object behind gKartPhysicalParamTable (0x14 bytes), made once per race: the per-slot records (mKartParams) and
// character rows (mCharParams) and the two loaded files. mFirstBaseSpeedLimit is a copy of file word 0x10.
typedef struct KartPhysicalParamTable {
    /* 00 */ struct KartPhysicalParam *mKartParams;
    /* 04 */ s32 *mCharParams;
    /* 08 */ s32 mFirstBaseSpeedLimit;
    /* 0c */ struct KartPhysicalParam *mKartParamFile;
    /* 10 */ s32 *mCharParamFile;
} KartPhysicalParamTable;

struct ModelEffect;

// The ModelEffect pools: an active list, one free list per kind, and the next polygon id (10 to 13).
typedef struct ModelEffects {
    /* 00 */ NNSFndList mActiveList;
    /* 0c */ NNSFndList mFreeLists[5];
    /* 48 */ struct ModelEffect **mObjects[5];
    /* 5c */ u16 mNextPolygonId;
    /* 5e */ u8 mUnk_5e[2];
} ModelEffects;

// The strip pool, 0x38 bytes: the active strips, the free strips, the free points and the texture file.
typedef struct PosStrips {
    // [0] active strips, [1] free strips, [2] free points.
    /* 00 */ NNSFndList mLists[3];
    /* 24 */ ResFileEntry mEffectFileEntry;
    /* 34 */ s32 mPolygonAttrBits;
} PosStrips;

// The 0x10 bytes at 0x784 of StemSets; the callbacks at 0x794 and 0x798 get their address.
typedef struct TimedQuad {
    /* 00 */ s16 mTimer;
    /* 02 */ s16 mAlpha;
    /* 04 */ u16 mColor;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ BOOL mEnabled;
    /* 0c */ u8 mUnk_0c[4];
} TimedQuad;

// Object behind gStemSets, 0x79c bytes.
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

// Value of KartStanding.mNotNormalEndPending and mObjectsSkipEndPending when no hit end is waiting (s32).
#define KART_STANDING_HIT_END_NONE -2
// One kart's entry of Standings (0x70 bytes, indexed by kart index): its count, rank, side id, elimination status and
// last position, and the hit tracking of the kart (those members keep their address names). Slots past the kart count
// are unused: status 2, count -1.
typedef struct KartStanding {
    /* 00 */ BOOL mNotNormalOrFlaggedSeen;
    /* 04 */ BOOL mObjectsSkipSeen;
    // 0 in play, 1 just eliminated (the update calls the kart handler once and sets 2), 2 eliminated and handled;
    // unused slots start at 2. Only compared, never switched on.
    /* 08 */ s32 mEliminationStatus;
    // Copy of the kart's position, refreshed every update while the kart's count is above 0 and no winner is decided.
    /* 0c */ Vec3 mPos;
    /* 18 */ s32 mNotNormalEndPending;
    /* 1c */ s32 mObjectsSkipEndPending;
    /* 20 */ BOOL mSkipNotNormalEnd;
    /* 24 */ s32 mHitSeenFromKart[8];
    /* 44 */ u16 mHitByKartIndex;
    // Id of the side the kart plays for: the entry's team index 0 gives 1, 1 gives 3, any other value gives the kart's
    // own index; an unused slot gets the kart count. The winner test compares it between the karts still in play.
    /* 46 */ u16 mTeamId;
    // Position in the order by count, 0 = first. Starts as the kart's own index; a count step swaps it with neighbours
    // (karts still in play stay ahead of eliminated ones).
    /* 48 */ u16 mRankIndex;
    /* 4a */ u8 mUnk_4a[2];
    // The kart's count: balloons held where the balloon object exists (mode 2 with RaceSetup.mUnk_18 == 0, and mode
    // 4), shines held in the shine mode (mode 2 with mUnk_18 == 1). -1 for an unused slot and for a kart eliminated in
    // mode 2; 0 at the start; changed in steps of +1 / -1. The rank order is sorted by it.
    /* 4c */ s32 mBalloonOrShineCount;
    /* 50 */ u16 mBalloonsLeftToMake;
    /* 52 */ u8 mUnk_52[0x12];
    /* 64 */ s32 mMicInflateTimer;
    /* 68 */ s32 mSelectKeyInflate;
    /* 6c */ s32 mInflatingBalloon;
} KartStanding;

// Per-kart table of the modes that play with kart counts (modes 2 and 4): the one object behind gStandings, made by
// InitStandings from InitRace and stepped once per UpdateRace call. It ranks the karts by count (mKarts), keeps who is
// eliminated, the winning side, the end timer and its callbacks. The name covers only the ranking and winner part: the
// kart-to-kart hit tracking, the four hit callbacks that act on a hit, a time-limit step and a random course point are
// in the same object too (those members keep their address names). 0x3c0 bytes, the allocation size.
typedef struct Standings {
    // One KartStanding per kart index; the entries past the kart count are unused slots.
    /* 000 */ KartStanding mKarts[8];
    // Called when a kart touches another kart in Battle and only the other kart has attacked, with the hit kart index
    // and the other kart index; set by the balloon object, its result is returned to the collision code.
    /* 380 */ s32 (*mKartHitByKartCallback)(s32, s32);
    // Called when two karts touch in Battle and both have attacked, with both kart indices; set by the balloon object.
    /* 384 */ void (*mKartsHitEachOtherCallback)(s32, s32);
    // Called with the hit kart index and the index of the kart that hit it (8 when none) when a hit of the kart ends,
    // and for a kart that hit itself; set by the balloon object and the shine mode, which take a balloon or shine from
    // the first kart.
    /* 388 */ s32 (*mKartHitCallback)(u16, u16);
    // Called with the kart index at the start of an elimination. Set by the balloon object (releases the kart's
    // balloons) and by the shine mode (drops the kart's shines).
    /* 38c */ void (*mKartEliminatedCallback)(u16);
    // Called when mEndTimer runs out and by the mode 4 end step. Set by the balloon object, the shine mode and the
    // overlay 1 objects.
    /* 390 */ void (*mEndCallback)(void);
    /* 394 */ u8 mUnk_394[8];
    // Called in Battle with the kart index and the address of a Vec3 when a kart is placed or pushed: the position
    // change of a kart set to a checkpoint position, the position change in ResetKartAtRaceEnd, and the push vector of
    // a map object that a kart pushed; set by the balloon object, which adds that Vec3 to the positions of the kart's
    // balloons.
    /* 39c */ void (*mKartOffsetCallback)(u16, Vec3 *);
    // Number of Shine16 objects placed and not yet finished: AddShineCount changes it (+1 placed, -1 finished); the
    // spawner stops placing at 3. Parking every shine at once, as the shine mode's end callback does, does not
    // subtract.
    /* 3a0 */ u16 mShineCount;
    /* 3a2 */ u16 mTimeLimitSeconds;
    /* 3a4 */ u16 mTimeLimitIndex;
    /* 3a6 */ u8 mUnk_3a6[2];
    // Frames left before mEndCallback runs once a winner is decided: mode 2 stores 0x5a and counts it down; at 0 it
    // becomes -1 and the callback runs. A value below 0 means the end is reached. Mode 4 stores 0 and ends through the
    // race-progress end step, which sets -1 and runs the callback.
    /* 3a8 */ s32 mEndTimer;
    // Highest KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort (the two functions that
    // swap ranks recompute it; AddBalloonOrShineCountAndMoveRank, which adds to a count, does not).
    /* 3ac */ s32 mHighestBalloonOrShineCount;
    // Lowest non-negative KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort; 0xffff when no
    // kart has a non-negative count.
    /* 3b0 */ s32 mLowestBalloonOrShineCount;
    // Side id (KartStanding.mTeamId) of the winning side, -1 until a winner is decided. Set once every kart still in
    // play has the id of the rank 0 kart. In mode 4 the ids are kart indices (it is compared with the local entry
    // index).
    /* 3b4 */ s32 mWinnerTeamId;
    /* 3b8 */ u16 mBattlePointIndex;
    /* 3ba */ u8 mUnk_3ba[2];
    // Pointer to entry 0 of the kind 0x69 object's KartBalloons array; set once by InitKartBalloons.
    /* 3bc */ struct KartBalloons *mKartBalloons;
} Standings;

// The Standings object, allocated by InitStandings in modes 2 and 4.
extern Standings *gStandings;

static inline KartStanding *GetStandingsKart(u16 kartIndex) {
    return &gStandings->mKarts[kartIndex];
}
// 8-byte entries of the tables KeyboardKeys points to (FindKeyboardRectByValue returns one).
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

// Set up by SetupKeyboardLayout (at 0x1c of KeyboardKeys, which mUnk_2c then points to); mUnk_08 is called with the
// KeyboardKeys (AsciiLayoutCallback is one).
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

// Four halfwords at 0x34 of KeyboardKeys (IsRepeatCounterFiring, AdvanceRepeatCounter).
typedef struct RepeatCounter {
    /* 00 */ u16 mRepeatFrames;
    /* 02 */ u16 mFirstFireFrame;
    /* 04 */ u16 mRepeatFireFrame;
    /* 06 */ u16 mFired;
} RepeatCounter;

// Object at gKeyboardKeyRepeat: an RepeatCounter followed by two halfwords (AdvanceKeyboardKeyRepeat,
// SetupKeyboardKeyRepeat).
typedef struct KeyboardKeyRepeat {
    /* 00 */ RepeatCounter mCounter;
    /* 08 */ u16 mKeyMask;
    /* 0a */ u16 mRepeatKeys;
} KeyboardKeyRepeat;

// Object at gKeyboardKeys, 0x54 bytes.
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
// Object at gKeyboardInput, 0x28 bytes (AdvanceKeyboardInput updates it, ClearKeyboardInput clears it).
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
// Object behind gKeyboardTextEntry, 0x78 bytes, allocated in InitKeyboardTextEntry. UploadKeyboardBg2Data passes the
// pointers at 0x00 and 0x04 to DC_FlushRange with the words at 0x08 and 0x0c.
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
typedef struct TitleStateHandlers {
    /* 00 */ UnkFunc *mWriteRegisters;
    /* 04 */ void (*mUpdate)(s32);
} TitleStateHandlers;

struct LayoutTableEntry;
struct LayoutEntryTable;

// Entries of the title menu in row order; all but the first are named after the scene each one starts (SCENE_*).
enum {
    TITLE_ENTRY_FIRST,
    TITLE_ENTRY_WL_MENU,
    TITLE_ENTRY_WIFI_MENU,
    TITLE_ENTRY_OPTION,
    TITLE_ENTRY_RECORD,
};

// TitleScene.mState, in the order of gTitleStateHandlers.
#define TITLE_STATE_BLEND_IN 0
#define TITLE_STATE_SLIDE_IN 1
#define TITLE_STATE_MENU_INPUT 2
#define TITLE_STATE_SLIDE_OUT 3
// The pressed entry moves for 10 frames, then the table slides out.
#define TITLE_STATE_SELECT_PRESS 4
#define TITLE_STATE_NOP 5
#define TITLE_STATE_REQUEST_NICKNAME_SCENE 6

// 0x8bc bytes.
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
    /* 05c */ BOOL mPreferEntry4;
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
// icons placed over the whole course, the map turning with the camera or kart heading, the map with north fixed that
// scrolls, and the map placed by the course map sub screen view. The goal pages list the finished karts or the teams;
// the last is the new-record page.
typedef enum {
    RACE_HUD_SUB_SCREEN_KART_ICONS,
    RACE_HUD_SUB_SCREEN_MAP_TURNING,
    RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL,
    RACE_HUD_SUB_SCREEN_MAP_VIEW,
    RACE_HUD_SUB_SCREEN_GOAL_KARTS,
    RACE_HUD_SUB_SCREEN_GOAL_TEAMS,
    RACE_HUD_SUB_SCREEN_NEW_RECORD
} RaceHudSubScreenState;

// On-screen display of the race, one record behind gRaceHud (0x914 bytes, allocated by InitRaceHud on the scene heap,
// set NULL by the release slot ReleaseRaceHud, never freed). It holds the two 0x400-byte sprite entry buffers the
// element draws append to (mUnk_004 for the main screen, mSubOam for the sub screen, copied to 0x07000000 /
// 0x07000400), the loaded graphics, the sub-screen page (mSubScreenState) and the goal-background delay; the elements
// themselves (time digits, number pair, goal page, new-record page) are separate objects. It does not exist in kinds 3,
// 5 and 6 of gRaceSetup.mRaceKind (the scene slots run RaceStartGp / EndingStaffRoll there).
// Words from 0x828 to 0x910 are read and written by UpdateRaceHudSubScreen. The pointers at 0x80c to 0x824 are written
// through LoadNclrData, LoadNcgrData and LoadNscrData.
typedef struct RaceHud {
    // Calls of the step UpdateRaceHud that ran its body (not in kinds 3, 5, 6, not before mEnabled); wraps to 0 at
    // 0xc00. An animation clock: read by the upload slot (value / 6 = scroll of the sub-screen page 0) and by
    // GetRaceHudUpdateFrames (value / 32).
    /* 000 */ s32 mUpdateFrames;
    /* 004 */ RaceHudOamBuffer mMainOam;
    /* 408 */ RaceHudOamBuffer mSubOam;
    /* 80c */ struct Nclr *mNclrs[2];
    /* 814 */ struct Ncgr *mNcgrs[2];
    /* 81c */ struct Nscr *mNscrs[3];
    // RaceHudSubScreenState page of the sub screen (reg_GXS_DB_* / reg_G2S_DB_* = sub engine), switched on by the step,
    // the draw and the upload slot; assigned by UpdateRaceHudSubScreen (per mode and race state),
    // RequestRaceHudSubScreenState5 (RaceGoalS teams) and RequestRaceHudSubScreenState6 (RaceNewRecordTa). The player
    // switches the icons page and the first map page with sounds 0x18 / 0x17.
    /* 828 */ s32 mSubScreenState;
    // Gate of the sub screen's page update and page upload.
    /* 82c */ BOOL mSubScreenEnabled;
    // Set when the state-5 page is requested; the upload loads its graphics once and clears it.
    /* 830 */ BOOL mSubScreenState5LoadPending;
    // Set when the state-6 page is requested; the upload loads its graphics once and clears it.
    /* 834 */ BOOL mSubScreenState6LoadPending;
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
    // Set once in InitRaceHud: 1 only in mode 1 with more than one kart; gates StartRaceHudLapTimeDisplay (the
    // computation) and the draw of the time difference.
    /* 8e4 */ s32 mUseTimeDifference;
    // ComputeTimeDifference's return: non-zero when the entry's summed lap times (GetKartLapTime) are >= the summed
    // reference times (gRaceSetup.mGhostLapTimes); the draw picks one of two sprites by it. Which sprite is plus or
    // minus is not named.
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
// 8-byte elements at the start of RaceRankList.
typedef struct RaceRankListPos {
    /* 00 */ s32 mX;
    /* 04 */ s32 mY;
} RaceRankListPos;

// 0xc-byte elements from 0xfc of RaceRankList.
typedef struct RaceRankListItemInUse {
    /* 00 */ s32 mInUseFrames;
    /* 04 */ s32 mItemInfoIndex;
    /* 08 */ s32 mObjectCount;
} RaceRankListItemInUse;

// Object behind gRaceRankList, 0x15c bytes, allocated by InitRaceRankList.
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

// Object behind gRaceHudSubScreenCellGroups, 0x25c bytes, allocated by InitRaceHudSubScreenCellGroups.
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
// SECOND and LAST are the three stages, each drawn with its own cell (LAST blinks); LAST is also reached directly from
// LEAVE_FIRST when the wifi pick is locked. LEAVE_END is the slide out before HIDDEN.
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

// Object behind gRaceGoalS, 0x20e4 bytes, allocated by InitRaceGoalS.
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
    /* 00b8 */ struct Nclr *mRaceGoalSBNclr;
    /* 00bc */ struct Ncgr *mRaceGoalSBNcgr;
    /* 00c0 */ struct Nscr *mRaceGoalSNscrs[6];
    /* 00d8 */ u16 mRaceGoalSSpaceNscrCopies[2][0x800];
    /* 20d8 */ s32 mOffsetState;
    /* 20dc */ s32 mOffsetStateFrames;
    /* 20e0 */ s32 mOffset;
} RaceGoalS;

extern RaceGoalS *gRaceGoalS;
extern struct MenuScene *gMenuScene;
// The same pointer as gWaterEfct, stored by SetCourseWaterEfct (the last call of CreateWaterEfct) and set to NULL in
// InitMapObjects; the water_efct getters and the level getter read this one.
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

// Object behind gRaceModeCount, 0xc bytes, allocated by InitRaceModeCount. The word at 0 is also read and written as
// two halfwords.
typedef struct RaceModeCount {
    /* 00 */ union {
        s32 mNumber;
        u16 mNumberHalves[2];
    };
    /* 04 */ s32 mMissionRunCountLimit;
    // 1 from init; cleared by DrawRaceModeCount once the time attack key recording is full; IsRaceKeyRecordingNotFull
    // reads it.
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

// Object behind gRaceItemSlot, 0x2c bytes, allocated by InitRaceItemSlot.
typedef struct RaceItemSlot {
    /* 00 */ s32 mScrollY;
    /* 04 */ s32 mSlotFrames;
    /* 08 */ s32 mUpperItem;
    /* 0c */ s32 mLowerItem;
    /* 10 */ BOOL mSlotRunning;
    /* 14 */ BOOL mPrevSlotRunning;
    /* 18 */ RaceItemSlotScale mScale;
} RaceItemSlot;

// Object behind gRaceTimeDigits, 0x38 bytes, allocated by InitRaceTimeDigits.
typedef struct RaceTimeDigits {
    /* 00 */ TimeDigits mTime;
    /* 1c */ BOOL mUseLastSecondsSound;
    /* 20 */ s32 mLastSecondsReached[6];
} RaceTimeDigits;

// 0x18-byte elements of the tables at member 0x10 of RaceTaPositions.
typedef struct RaceTaPositionSample {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mAngle;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ s32 mKind;
    /* 14 */ s32 mPriority;
} RaceTaPositionSample;

// 0x40-byte elements of the table at member 0x790 of RaceTaPositions.
typedef struct RaceTaKinokoBoostPoints {
    /* 00 */ s32 mPointCount;
    /* 04 */ Vec3 mPositions[3];
    /* 28 */ s32 mPriorities[3];
    /* 34 */ s32 mAgeSamples[3];
} RaceTaKinokoBoostPoints;

// Object behind gRaceTaPositions, 0x910 bytes, allocated by InitRaceTaPositions.
typedef struct RaceTaPositions {
    /* 000 */ s32 mVisible;
    /* 004 */ s32 mKartVisible[2];
    /* 00c */ s32 mSampleFrames;
    /* 010 */ RaceTaPositionSample mSamples[2][0x28];
    /* 790 */ RaceTaKinokoBoostPoints mKinokoBoostPoints[2];
    /* 810 */ MtxFx22 mRotations[16];
} RaceTaPositions;

// Object behind gRaceLinkLevel.
typedef struct RaceLinkLevel {
    /* 00 */ s32 mLinkLevel;
    /* 04 */ s32 mWiFiLinkLevel;
    /* 08 */ s32 mFriendOnFrames;
    /* 0c */ s32 mPrevFriendOn;
    /* 10 */ s32 mFriendOn;
} RaceLinkLevel;

// Object behind gRaceLapNumber.
typedef struct RaceLapNumber {
    /* 00 */ s32 mLapIndex;
    /* 04 */ s32 mPrevLapIndex;
    /* 08 */ s32 mLastLapIndex;
    /* 0c */ s32 mBlinkFrames;
    /* 10 */ s32 mBlinkShown;
} RaceLapNumber;

// Object behind gRaceHudSubScreenSecondHand, 0x44 bytes allocated by CreateRaceHudSubScreenSecondHand: a table of
// object pointers and two counts (as in RaceHudSubScreenCells), three halfwords and two arrays of three pairs.
typedef struct RaceHudSubScreenSecondHand {
    /* 00 */ struct Vehicle **mObjects;
    /* 04 */ s32 mCreatedObjectCount;
    /* 08 */ s32 mObjectCount;
    /* 0c */ u16 mAngles[3];
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ IntPair mDrawPositions[3];
    /* 2c */ IntPair mEndPositions[3];
} RaceHudSubScreenSecondHand;

// Object behind gRaceHudSubScreenKarts, 0x194 bytes allocated by CreateRaceHudSubScreenKarts: arrays of eight entries
// and an RaceHudSubScreenCells pointer at 0x190.
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

// Object at gKeyboardCanvas, 0x24 bytes.
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
// Which model the Jg shows and its row in gJgKindRows: 0 lap_count, 1 lap_final, 2 jg_reverse, 3 jg_flag, 4 none.
extern s32 gJgKind;
extern s32 gJgSnapUntilPushFlip;
extern s32 gJgAgainstCheckpointFrames;
extern s32 gJgVisible;
extern s32 gJgSnapActive;

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
extern u16 gJgState2FrameCount;
extern u16 gJgKartIndex;
extern u16 gJgProbeStep;
extern u16 gJgHighestLap;
extern s32 gJgShiftSpeedX;
extern s32 gJgShiftX;
extern s32 gJgHeightOffsetSpeed;
extern s32 gJgHeightOffset;
extern s32 gJgInView;
extern s32 gJgNearKart;
extern s32 gJgState1AngleActive;
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
extern Vec3 gJgState6LocalTargetPos;
extern s32 gJgState6Speed;
extern s32 gJgState6HeightOffset;
extern s32 gJgState5HeightOffset;
extern s32 gJgState5Speed;
extern s32 gJgVelocityFactorX;
// Copy of the kart's position, y minus the kart's hop height (state 4 stores it without that).
extern Vec3 gJgKartPos;
extern Vec3 gJgKind4Offset;
extern Vec3 gJgLapOffset;
extern Vec3 gJgState5LocalTargetPos;
extern Vec3 *gJgPointPointers[4];
extern u16 gJgAlpha;
extern u16 gJgAngle;
extern Vec3 gJgKind3Offset;
extern Vec3 gJgKind2Offset;
extern void *gSphereHitObjects[16];
extern s32 gJgOffsetY;
extern s32 gJgOffsetX;
extern s32 gJgFarFromKart;
extern u32 gJgCourseHitBits;
extern s32 gGessoBlockTimer;
// Items the spin may show after a roll with a forced row: the items with a non-zero weight in that row plus the one
// picked. Written by PickItem, cleared by CreateItemSlotTables.
extern u16 gItemSlotPossibleItemCount;
// Length of gItemSlotSpinItems; 0 means the spin uses gItemSlotPossibleItems.
extern u16 gItemSlotSpinItemCount;
extern u8 gItemDataDelayedFreeHead[];
extern u8 gItemDataQueueUsedHead[];
extern u8 gItemDataQueueFreeHead[];
extern u8 gItemDataDelayedUsedHead[];
extern MapObjectModel *gIronBall;
