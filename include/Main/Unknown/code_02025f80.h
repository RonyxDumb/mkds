#pragma once

#include "types.h"

typedef struct Interpolation Interpolation;

int menucs_render(void);
void menucs_init(void *parentHeap, s32 mode, void *mainOam, void *subOam);

extern char aSelect_character_gp_m_nce_ncgr[];
extern char aSelect_character_gp_m_nce_ncer[];
extern char aSelect_character_gp_m_o_nclr[];
extern char aSelect_character_s_nce_ncgr[];
extern char aSelect_character_s_nce_ncer[];
extern char aSelect_character_s_o_nclr[];
extern char aSelect_character_gp_name_m_nce_ncgr[];
extern char aSelect_character_gp_name_m_nce_ncer[];
extern char aSelect_character_gp_title_m_nce_ncgr[];
extern char aSelect_character_gp_title_m_nce_ncer[];

void interp_init(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue);
void func_02025f90(void);
void menucs_2026058(void);
void ReleaseSelectCharacter(void);
void func_02027084(void);
u32 func_020270d0(void);
void func_020270fc(s32 previousTableIndex);
void func_02027188(void);
