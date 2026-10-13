/* Decompiled C draft; module arm9; ROM address 0201d8f8. No matching claim. */
#include "types.h"
#include "deps/0201d8f8_func_0201d8f8.h"

void func_0201d8f8(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  
  local_20 = *psRam0201db7c;
  local_1e = psRam0201db7c[1];
  local_1c = psRam0201db7c[2];
  uVar1 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x18) >> 0x1e;
  if (uVar1 == 0) {
    local_1a = 0;
    local_18 = 0;
    local_16 = 0x1000;
  }
  else if (uVar1 == 1) {
    local_1a = 0;
    local_18 = 0x1000;
    local_16 = 0;
  }
  else if (uVar1 == 2) {
    local_1a = 0x1000;
    local_18 = 0;
    local_16 = 0;
  }
  else {
    VecFx16_Normalize(param_1 + 0x50,&local_1a);
  }
  iVar3 = VecFx16_DotProduct(&local_20,&local_1a);
  if ((iVar3 == 0x1000) || (iVar3 == -0x1000)) {
    local_20 = 0x1000;
    local_1e = 0;
    local_1c = 0;
  }
  *(short *)(param_1 + 0x84) =
       (short)((int)local_18 * (int)local_1c + 0x800U >> 0xc) -
       (short)((int)local_16 * (int)local_1e + 0x800U >> 0xc);
  *(short *)(param_1 + 0x86) =
       (short)((int)local_16 * (int)local_20 + 0x800U >> 0xc) -
       (short)((int)local_1a * (int)local_1c + 0x800U >> 0xc);
  *(short *)(param_1 + 0x88) =
       (short)((int)local_1a * (int)local_1e + 0x800U >> 0xc) -
       (short)((int)local_18 * (int)local_20 + 0x800U >> 0xc);
  *(short *)(param_1 + 0x8a) =
       (short)((int)local_18 * (int)*(short *)(param_1 + 0x88) + 0x800U >> 0xc) -
       (short)((int)local_16 * (int)*(short *)(param_1 + 0x86) + 0x800U >> 0xc);
  *(short *)(param_1 + 0x8c) =
       (short)((int)local_16 * (int)*(short *)(param_1 + 0x84) + 0x800U >> 0xc) -
       (short)((int)local_1a * (int)*(short *)(param_1 + 0x88) + 0x800U >> 0xc);
  *(short *)(param_1 + 0x8e) =
       (short)((int)local_1a * (int)*(short *)(param_1 + 0x86) + 0x800U >> 0xc) -
       (short)((int)local_18 * (int)*(short *)(param_1 + 0x84) + 0x800U >> 0xc);
  VecFx16_Normalize(param_1 + 0x84,param_1 + 0x84);
  VecFx16_Normalize(param_1 + 0x8a,param_1 + 0x8a);
  return;
}

