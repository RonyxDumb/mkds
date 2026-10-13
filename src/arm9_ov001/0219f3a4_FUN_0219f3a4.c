/* Decompiled C draft; module arm9_ov001; ROM address 0219f3a4. No matching claim. */
#include "types.h"
#include "deps/0219f3a4_FUN_0219f3a4.h"

void FUN_0219f3a4(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  
  bVar1 = true;
  local_24 = 0;
  *(undefined2 *)(*DAT_0219f42c + 0x4a) = 0;
  local_20 = 1;
  local_1c = 0;
  do {
    iVar3 = local_1c;
    uVar4 = local_20;
    do {
      uVar2 = func_0x0205fd78(local_24 + 1U & 0xff,iVar3 + 1U & 0xff,&local_18);
      uVar4 = uVar4 & uVar2;
      if ((uVar4 == 0) || (local_18 < 5)) {
        bVar1 = false;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 9);
    if (uVar4 != 0) {
      if (local_24 == 5) {
        if (bVar1) {
          *(short *)(*DAT_0219f42c + 0x4a) = (short)local_24 + 1;
        }
      }
      else {
        *(short *)(*DAT_0219f42c + 0x4a) = (short)local_24 + 1;
      }
    }
    local_24 = local_24 + 1;
  } while (local_24 < 7);
  return;
}

