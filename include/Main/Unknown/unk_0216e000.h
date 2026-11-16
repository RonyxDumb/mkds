#pragma once

#include "types.h"
#include "code_02134398.h"
#include "output_effect.h" // CallbackInfo

// Objects whose layout isn't known yet.
extern const char *gTrophyIconNcgrName;
extern const char *gTrophyIconNcerName;
extern const char *gTrophyIconBnclName;
extern const char *gTrophyIconNclrName;
extern const char *data_0216e124;
extern const char *data_0216e128;
extern const char *data_0216e12c;
extern const char *data_0216e130;
extern const char *data_0216e134;
extern const char aKeyboard_s_10key_bnbl[];
extern const char aKeyboard_s_10key_bncl[];
extern const char aKeyboard_s_10key_bnll[];
extern const char aKeyboard_s_bnbl[];
extern const char aKeyboard_s_bncl[];
extern const char aKeyboard_s_bnll[];
extern const char aKeyboard_s_o_nce_ncgr[];
extern const char aKeyboard_s_o_nce_ncer[];
extern const char aKeyboard_s_o_nclr[];
extern const char aKeyboard_s_b_flame_ncgr[];
extern const char aKeyboard_s_b_flame02_nscr[];
extern const char aKeyboard_s_b_flame01_nscr[];
extern const char aKeyboard_s_b_nclr[];
extern CallbackInfo sCallbackInfo;

// Walked by __flush_line_buffered_output_files; fwrite compares its argument with entries 1 and 2; printf passes entry 1
// to fwide and __pformatter.
extern FILE __files[3];
extern u32 gRandValue;
extern char aCommon_bmg_24[];
extern char aCommon_bmg_20[];
extern char aCommon_bmg_19[];
extern char aEnding_staffroll_b_00_nclr[];
extern char aStaffroll_bmg[];
extern const char aTxt_system__12[];
extern const char aTxt_system__13[];
extern const char aTxt_system__14[];
extern const char aTxt_system__15[];
extern const char aTxt_system__16[];
extern const char aTxt_system__17[];
extern const char aTxt_system__18[];
extern const char aTxt_system__19[];
extern const char aTxt_system__20[];
extern const char aTxt_system__21[];
extern const char aTxt_system__22[];
extern const char aTxt_system__23[];
extern const char aTxt_system__24[];
extern const char aSelect_chois_2[];
extern const char aSelect_chois_3[];
extern const char aSelect_chois_4[];
