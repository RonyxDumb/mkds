/* Decompiled C draft; module arm9_ov003; ROM address 021ce7c0. No matching claim. */
#include "types.h"
#include "deps/021ce7c0_FUN_021ce7c0.h"

void FUN_021ce7c0(short *param_1)

{
  char *pcVar1;
  
  if (param_1[1] == 0) {
    pcVar1 = (char *)(*DAT_021ce828 + DAT_021ce82c);
    if (*pcVar1 == '\0') {
      if (*param_1 == 0x26) {
        if (param_1[4] == 4) {
          FUN_021ce8ec();
          return;
        }
        if (param_1[4] == 5) {
          if (*(char *)(*DAT_021ce828 + DAT_021ce830) == '\0') {
            FUN_021ce6ac();
          }
          else {
            FUN_021ce5b8();
          }
          FUN_021ce8ec();
          return;
        }
        func_0x0200fd1c();
      }
    }
    else if (*param_1 == 2) {
      *pcVar1 = '\x02';
      return;
    }
  }
  return;
}

