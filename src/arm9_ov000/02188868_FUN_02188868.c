/* Decompiled C draft; module arm9_ov000; ROM address 02188868. No matching claim. */
#include "types.h"
#include "deps/02188868_FUN_02188868.h"

undefined4 FUN_02188868(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  
  uVar1 = (*(code *)*param_1)(1,0x18);
  *DAT_02188988 = uVar1;
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(uVar1),0x18);
  puVar3 = (undefined4 *)*DAT_02188988;
  *puVar3 = *param_1;
  puVar3[1] = param_1[1];
  *(undefined1 *)((int)puVar3 + 9) = 1;
  *(undefined1 *)((int)puVar3 + 0x16) = 1;
  *(undefined1 *)(puVar3 + 2) = 1;
  iVar2 = FUN_021886c4(0x10,DAT_0218898c);
  *DAT_02188990 = iVar2;
  uVar1 = FUN_021886c4(2,DAT_02188994);
  *DAT_02188998 = uVar1;
  uVar1 = FUN_021886c4(4,0x58);
  *DAT_0218899c = uVar1;
  uVar1 = FUN_021886c4(8,0xc);
  *DAT_021889a0 = uVar1;
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(*DAT_02188990),DAT_0218898c);
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(*DAT_02188998),DAT_02188994);
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(*DAT_0218899c),0x58);
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(*DAT_021889a0),0xc);
  iVar2 = *DAT_02188990;
  *(undefined1 *)(iVar2 + DAT_021889a4) = *(undefined1 *)(param_1 + 2);
  *(byte *)(iVar2 + DAT_021889a8) =
       *(byte *)(iVar2 + DAT_021889a8) & 0xfc | *(byte *)((int)param_1 + 9) & 3;
  puVar3 = (undefined4 *)*DAT_021889a0;
  *puVar3 = *param_1;
  puVar3[1] = param_1[1];
  puVar3[2] = 0;
  pbVar4 = (byte *)(iVar2 + DAT_021889ac);
  *pbVar4 = *pbVar4 & 0xf0 | *(byte *)((int)param_1 + 10) & 0xf;
  *pbVar4 = *pbVar4 & 0xcf | (byte)((*(byte *)((int)param_1 + 0xb) & 3) << 4);
  func_0x021519a8();
  iVar2 = FUN_021a6470(*DAT_02188998,DAT_02188994);
  if ((iVar2 != 1) && (iVar2 < 4)) {
    return 1;
  }
  FUN_021885ec();
  return 0;
}

