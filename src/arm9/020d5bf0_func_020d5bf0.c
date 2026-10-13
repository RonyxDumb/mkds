/* Decompiled C draft; module arm9; ROM address 020d5bf0. No matching claim. */
#include "types.h"
#include "deps/020d5bf0_func_020d5bf0.h"

void func_020d5bf0(ushort *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  func_020d7d4c((int)(uintptr_t)(param_1 + 0x52),param_2,uRam020d5d20,(int)*(short *)(param_2 + 0x2a));
  *(int *)(param_1 + 0x6e) = (int)*(short *)(param_2 + 0x28);
  uVar1 = func_020d8654(param_2);
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  iVar2 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_2 + 0x26),0);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)((int)param_1 + iRam020d5d24) = *(undefined4 *)(param_1 + 0x10);
  iVar2 = (int)*(short *)(param_2 + 0x2e);
  if (iVar2 < 1) {
    uVar1 = FUN_02132440(iVar2 << 0xc);
    func_021329f8(uVar1,uRam020d5d28);
  }
  else {
    uVar1 = FUN_02132440(iVar2 << 0xc);
    func_02131234(uRam020d5d28,uVar1);
  }
  uVar1 = func_021322c8();
  uVar1 = _s32_div_f(uVar1,uRam020d5d2c);
  *(undefined4 *)((int)param_1 + iRam020d5d30) = uVar1;
  iVar2 = (int)*(short *)(param_2 + 0x30);
  if (iVar2 < 1) {
    uVar1 = FUN_02132440(iVar2 << 0xc);
    func_021329f8(uVar1,uRam020d5d28);
  }
  else {
    uVar1 = FUN_02132440(iVar2 << 0xc);
    func_02131234(uRam020d5d28,uVar1);
  }
  uVar1 = func_021322c8();
  iVar2 = _s32_div_f(uVar1,uRam020d5d34);
  *(int *)((int)param_1 + iRam020d5d3c) = iVar2 + iRam020d5d38;
  func_020d5dd0((int)(uintptr_t)(param_1));
  *(undefined2 *)((int)param_1 + iRam020d5d40) = 0;
  *(int *)(param_1 + 0x70) = (int)*(short *)(param_2 + 0x32);
  if (*(int *)(param_1 + 0x70) == 0) {
    param_1[1] = param_1[1] & 0xfffd;
    param_1[1] = param_1[1] & 0xfff7;
    param_1[0x33] = 0x1f;
  }
  else {
    param_1[1] = param_1[1] | *puRam020d5d44;
    param_1[1] = param_1[1] | *puRam020d5d48;
  }
  uVar1 = _s32_div_f((int)*(short *)(param_2 + 0x2c) << 0xc,100);
  *(undefined4 *)((int)param_1 + iRam020d5d4c) = uVar1;
  if (*param_1 == uRam020d5d50) {
    func_020d278c((int)(uintptr_t)(param_1));
  }
  else {
    func_020d27fc((int)(uintptr_t)(param_1));
  }
  param_1[1] = param_1[1] | *puRam020d5d54;
  return;
}

