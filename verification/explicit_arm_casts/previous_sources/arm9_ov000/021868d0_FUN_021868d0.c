/* Decompiled C draft; module arm9_ov000; ROM address 021868d0. No matching claim. */
#include "types.h"
#include "deps/021868d0_FUN_021868d0.h"

undefined4 FUN_021868d0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  uVar1 = func_0x0213a434(param_2);
  if (0x7f < uVar1) {
    return 0;
  }
  func_0x0213a228(param_1 + 0x28,param_2,0x80);
  iVar2 = func_0x0213a434(param_2);
  iVar3 = func_0x0213a434(param_1 + 0x28);
  if (iVar2 != iVar3) {
    return 0;
  }
  iVar2 = func_0x02139f70(param_1 + 0x28,DAT_0218698c);
  if (iVar2 == 0) {
    iVar2 = func_0x02139f70(param_1 + 0x28,DAT_02186990);
    if (iVar2 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xa8) = iVar2 + 8;
    *(undefined4 *)(param_1 + 0xb0) = 1;
  }
  else {
    *(int *)(param_1 + 0xa8) = param_1 + 0x2f;
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  puVar4 = (undefined1 *)func_0x02139f70(*(undefined4 *)(param_1 + 0xa8),DAT_02186994);
  if (puVar4 == (undefined1 *)0x0) {
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  else {
    *puVar4 = 0;
    *(undefined1 **)(param_1 + 0xac) = puVar4 + 1;
  }
  return 1;
}

