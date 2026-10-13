/* Decompiled C draft; module arm9_ov000; ROM address 021a3eb0. No matching claim. */
#include "types.h"
#include "deps/021a3eb0_FUN_021a3eb0.h"

void FUN_021a3eb0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  char local_20 [4];
  char local_1c;
  char local_1b;
  uint local_18;
  
  pcVar2 = local_20;
  local_20[0] = *DAT_021a3f64;
  local_20[1] = DAT_021a3f64[1];
  local_20[2] = DAT_021a3f64[2];
  local_20[3] = DAT_021a3f64[3];
  local_1c = DAT_021a3f64[4];
  local_1b = DAT_021a3f64[5];
  bVar1 = true;
  if (param_3 < 10) {
    bVar1 = false;
  }
  else {
    iVar3 = 0;
    do {
      if (*pcVar2 != *(char *)(param_2 + iVar3)) {
        bVar1 = false;
        break;
      }
      pcVar2 = pcVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  if (bVar1) {
    local_18 = *(uint *)(param_2 + 6);
    if (*(code **)(param_1 + 0xa0) != (code *)0x0) {
      (**(code **)(param_1 + 0xa0))
                ((local_18 & DAT_021a3f68 >> 0x18) << 0x18 |
                 (local_18 & DAT_021a3f6c >> 8) << 8 |
                 local_18 >> 0x18 | local_18 >> 8 & DAT_021a3f70,
                 *(undefined4 *)(param_1 + DAT_021a3f74));
      return;
    }
  }
  else if (*(code **)(param_1 + 0xa4) != (code *)0x0) {
    (**(code **)(param_1 + 0xa4))(param_2,param_3,*(undefined4 *)(param_1 + DAT_021a3f74));
  }
  return;
}

