/* Decompiled C draft; module arm9; ROM address 021189f4. No matching claim. */
#include "types.h"
#include "deps/021189f4_func_021189f4.h"

uint func_021189f4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar3 = 0;
  switch(*(undefined4 *)(*DAT_02118b38 + 0x3c)) {
  case 0:
  case 2:
    switch(param_1) {
    case 0:
    case 1:
    case 4:
    case 5:
      uVar3 = 1;
      break;
    default:
      iVar2 = func_0202967c();
      if (iVar2 == 0) {
        iVar2 = func_0202969c();
        uVar3 = CheckSavedSecretFlag_from_thumb
                          (*(undefined4 *)
                            (*(int *)(DAT_02118b44 + iVar2 * 4) * 4 + DAT_02118b40 + param_1 * 0xc))
        ;
      }
      else {
        uVar3 = CheckSavedSecretFlag_from_thumb(*(undefined4 *)(DAT_02118b3c + param_1 * 4));
      }
    }
    break;
  case 1:
    switch(param_1) {
    case 0:
    case 1:
    case 4:
    case 5:
      uVar3 = 1;
      break;
    default:
      uVar3 = 0;
      iVar2 = 0;
      puVar4 = (undefined4 *)(DAT_02118b40 + param_1 * 0xc);
      puVar5 = (undefined4 *)(DAT_02118b3c + param_1 * 4);
      do {
        if (iVar2 == 3) {
          uVar1 = CheckSavedSecretFlag_from_thumb(*puVar5);
        }
        else {
          uVar1 = CheckSavedSecretFlag_from_thumb(*puVar4);
        }
        uVar3 = uVar3 | uVar1;
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
    }
    break;
  case 3:
    if ((param_1 == 0) || (param_1 == 4)) {
      uVar3 = 1;
    }
    break;
  case 4:
    switch(param_1) {
    case 0:
    case 1:
    case 4:
    case 5:
      uVar3 = 1;
      break;
    default:
      iVar2 = func_0202967c();
      if (iVar2 == 0) {
        iVar2 = func_0202969c();
        uVar3 = CheckSecretFlag(*(undefined4 *)
                                 (*(int *)(DAT_02118b44 + iVar2 * 4) * 4 +
                                 DAT_02118b40 + param_1 * 0xc));
      }
      else {
        uVar3 = CheckSecretFlag(*(undefined4 *)(DAT_02118b3c + param_1 * 4));
      }
    }
  }
  return uVar3;
}

