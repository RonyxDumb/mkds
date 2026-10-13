/* Decompiled C draft; module arm9; ROM address 0202d720. No matching claim. */
#include "types.h"
#include "deps/0202d720_func_0202d720.h"

void func_0202d720(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  short extraout_r1;
  short extraout_r1_00;
  short extraout_r1_01;
  short extraout_r1_02;
  short local_1c;
  short local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = *piRam0202d828;
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar1 + 0xac),0x56);
  func_0212426c(1,0xe,*(undefined4 *)(iVar1 + 0x80),uVar2,*(undefined4 *)(iVar1 + 0x78),
                *(undefined4 *)(iVar1 + 0x84));
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d828 + 0xac),0x57);
  func_0212426c(1,0xf,*(undefined4 *)(iVar1 + 0x80),uVar2,*(undefined4 *)(iVar1 + 0x78),
                *(undefined4 *)(iVar1 + 0x84));
  iVar3 = func_0202ddb0();
  if (iVar3 < 10) {
    local_1c = 0x20;
  }
  else {
    uVar2 = _s32_div_f(iVar3,10);
    _s32_div_f(uVar2,10);
    local_1c = extraout_r1 + 0x30;
  }
  _s32_div_f(iVar3,10);
  local_1a = extraout_r1_00 + 0x30;
  local_18 = 0x2f;
  local_16 = 0x33;
  local_14 = 0x32;
  local_12 = 0;
  func_02124224(1,0x10,*(undefined4 *)(iVar1 + 0x80),&local_1c,*(undefined4 *)(iVar1 + 0x78),
                *(undefined4 *)(iVar1 + 0x84),6);
  iVar3 = func_0202dd9c();
  if (iVar3 < 10) {
    local_1c = 0x20;
  }
  else {
    uVar2 = _s32_div_f(iVar3,10);
    _s32_div_f(uVar2,10);
    local_1c = extraout_r1_01 + 0x30;
  }
  _s32_div_f(iVar3,10);
  local_1a = extraout_r1_02 + 0x30;
  local_18 = 0x2f;
  local_16 = 0x31;
  local_14 = 0x30;
  local_12 = 0;
  func_02124224(1,0x11,*(undefined4 *)(iVar1 + 0x80),&local_1c,*(undefined4 *)(iVar1 + 0x78),
                *(undefined4 *)(iVar1 + 0x84),6);
  return;
}

