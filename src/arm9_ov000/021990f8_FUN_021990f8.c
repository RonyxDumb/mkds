/* Decompiled C draft; module arm9_ov000; ROM address 021990f8. No matching claim. */
#include "types.h"
#include "deps/021990f8_FUN_021990f8.h"

undefined4 FUN_021990f8(int param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_20 = *(undefined4 *)(param_1 + 0x58);
  local_18 = (uint)param_2;
  local_1c = param_3;
  local_14 = FUN_0218e8c4();
  iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x60)));
  FUN_0218dbc0((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x60)),(undefined4)(uintptr_t)(&local_20));
  iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x60)));
  if (iVar1 + 1 == iVar2) {
    return 1;
  }
  return 0;
}

