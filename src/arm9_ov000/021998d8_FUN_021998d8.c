/* Decompiled C draft; module arm9_ov000; ROM address 021998d8. No matching claim. */
#include "types.h"
#include "deps/021998d8_FUN_021998d8.h"

undefined4
FUN_021998d8(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
            undefined4 *param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined2 local_1c;
  
  iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)));
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),iVar4);
      if (*(ushort *)(iVar3 + 0xc) == param_3) {
        *param_6 = 0;
        return 1;
      }
      iVar3 = FUN_0219a014((uint)*(ushort *)(iVar3 + 0xc),param_3);
    } while ((iVar3 < 1) && (iVar4 = iVar4 + 1, iVar4 < iVar2));
  }
  iVar4 = FUN_02197e58(param_1 + 0x44);
  if (iVar4 < param_5) {
    *param_6 = 1;
    return 1;
  }
  local_28 = *(undefined4 *)(param_1 + 0x4c);
  local_24 = param_5;
  local_1c = (undefined2)param_3;
  local_20 = param_2;
  FUN_0218daf8((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),(undefined4)(uintptr_t)(&local_28),DAT_021999fc);
  iVar4 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)));
  if (iVar2 + 1 != iVar4) {
    *param_6 = 1;
    return 1;
  }
  FUN_02197d84((int *)(uintptr_t)(param_1 + 0x44),param_4,param_5);
  if (iVar2 == 0) {
    iVar2 = FUN_02198ba8(param_1,*(undefined2 *)(param_1 + 0x66),param_3 - 1 & 0xffff);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar4 = FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),iVar2);
    if (*(ushort *)(iVar4 + 0xc) == param_3) {
      iVar2 = FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),iVar2 + -1);
      uVar1 = FUN_0219a014(param_3,*(undefined2 *)(iVar2 + 0xc));
      if ((1 < uVar1) &&
         (iVar2 = FUN_02198ba8(param_1,*(short *)(iVar2 + 0xc) + 1,param_3 - 1 & 0xffff), iVar2 == 0
         )) {
        return 0;
      }
    }
  }
  *param_6 = 0;
  return 1;
}

