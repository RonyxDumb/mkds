#pragma once

#include "types.h"

typedef struct Bg1Files Bg1Files;

// Object whose halfword at 0x04 logo_render clears.
typedef struct SceneNumbersView {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 mNextScene;
} SceneNumbersView;

extern const char aLogo_r_ninte_1[];
extern const char aLogo_r_ninte_2[];
extern const char aLogo_r_nintend[];
extern const char aAllrightsres_1[];
extern const char aAllrightsres_2[];
extern const char aAllrightsreser[];
extern const char aCommon_bmg[];

void logo_fadeInStateUpdate(void);
void logo_fadeInStateInit(void);
void logo_render(SceneNumbersView *sceneNumbers);
void logo_vblank(void);
void logo_finish(void);
void logo_create(void *heap);
void logo_loadBg(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);
