/* Decompiled C draft; module arm9_ov000; ROM address 02197220. No matching claim. */
#include "types.h"
#include "deps/02197220_FUN_02197220.h"

int FUN_02197220(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *DAT_021972a8 = DAT_021972a4;
  FUN_021971ec();
  func_0x0213a2d0(param_1 + param_2,DAT_021972ac);
  puVar1 = DAT_021972b0;
  if (0 < param_2 + 7) {
    do {
      iVar2 = FUN_0218e420(*puVar1,param_1 + iVar3,(param_2 + 7) - iVar3,0);
      if (iVar2 == -1) {
        iVar2 = FUN_0218e368(*puVar1);
        if (((iVar2 != -6) && (iVar2 != -0x4c)) && (iVar2 != -0x1a)) {
          return iVar2;
        }
      }
      else {
        if (iVar2 == 0) {
          return -1;
        }
        iVar3 = iVar3 + iVar2;
      }
    } while (iVar3 < param_2 + 7);
  }
  return iVar3;
}

