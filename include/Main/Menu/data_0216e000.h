#pragma once
#include "types.h"
#include "code_02134398.h"
#include "output_effect.h" // CallbackInfo

// Objects whose layout isn't known yet.
extern const char *gTrophyIconNcgrName;

extern const char *gTrophyIconNcerName;

extern const char *gTrophyIconBnclName;

extern const char *gTrophyIconNclrName;

extern const char *gSelectRaceRuleWaitBnclName;

extern const char *gSelectRaceRuleWaitNcerName;

extern const char *gSelectRaceRuleWaitBnllName;

extern const char *gSelectRaceRuleWaitNclrName;

extern const char *gSelectRaceRuleWaitNcgrName;

extern const char gKeyboardS10KeyBnblName[];

extern const char gKeyboardS10KeyBnclName[];

extern const char gKeyboardS10KeyBnllName[];

extern const char gKeyboardSBnblName[];

extern const char gKeyboardSBnclName[];

extern const char gKeyboardSBnllName[];

extern const char gKeyboardSONceNcgrName[];

extern const char gKeyboardSONceNcerName[];

extern const char gKeyboardSONclrName[];

extern const char gKeyboardSBFlameNcgrName[];

extern const char gKeyboardSBFlame02NscrName[];

extern const char gKeyboardSBFlame01NscrName[];

extern const char gKeyboardSBNclrName[];

extern CallbackInfo sCallbackInfo;

// Walked by FflushAll; fwrite compares its argument with entries 1 and 2; printf passes entry 1
// to fwide and FormatWithPutFunc.
extern FILE data_0216eb7c[3];

extern char data_0216e09c[];

extern char data_0216ea60[];

extern char data_0216ea6c[];

extern char gEndingStaffRollB00NclrName[];

extern char gStaffRollBmgName[];

extern const char gTxtSystemB00NcgrName[];

extern const char gTxtSystemBg00NscrName[];

extern const char gTxtSystemB00NclrName[];

extern const char data_0216e750[];

extern const char gTxtSystemB01NcgrName[];

extern const char data_0216e780[];

extern const char gTxtSystemBg002NscrName[];

extern const char gTxtSystemBg012NscrName[];

extern const char gTxtSystemBg01NscrName[];

extern const char gTxtSystemBg02NscrName[];

extern const char gTxtSystemBg022NscrName[];

extern const char gTxtSystemBg023NscrName[];

extern const char data_0216e828[];

extern const char gSelectChoisesSBNcgrName[];

extern const char gSelectChoisesSBgNscrName[];

extern const char gSelectChoisesSBNclrName[];
