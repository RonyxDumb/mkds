/* Decompiled C draft; module arm9; ROM address 02011074. No matching claim. */
#include "types.h"
#include "deps/02011074_func_02011074.h"

void func_02011074(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  uVar6 = uRam020111ac;
  uVar5 = uRam020111a8;
  uVar4 = uRam020111a4;
  uVar3 = uRam020111a0;
  uVar2 = uRam0201119c;
  puVar1 = puRam02011198;
  *puRam02011198 = uRam02011194;
  puVar1[1] = 0;
  puVar1[0x12] = 2;
  puVar1[0x1f] = uVar2;
  puVar1[0x24] = uVar3;
  puVar1[0x29] = uVar4;
  puVar1[0x2e] = uVar5;
  Matrix4x3_Identity((undefined4 *)(uintptr_t)(uVar6));
  func_02147954((undefined4 *)(uintptr_t)(uRam020111b0));
  uVar10 = uRam020111d8;
  uVar9 = uRam020111d4;
  uVar8 = uRam020111d0;
  uVar7 = uRam020111cc;
  uVar6 = uRam020111c8;
  uVar5 = uRam020111c4;
  uVar4 = uRam020111c0;
  uVar3 = uRam020111bc;
  uVar2 = uRam020111b4;
  puVar1 = puRam02011198;
  puRam02011198[0x21] = uRam020111b8;
  puVar1[0x20] = uVar3;
  uVar3 = uRam020111dc;
  puVar1[0x22] = uVar4;
  puVar1[0x23] = uVar5;
  puVar1[0x25] = uVar2;
  puVar1[0x26] = uVar2;
  puVar1[0x27] = uVar6;
  puVar1[0x28] = uVar7;
  puVar1[0x2a] = uVar8;
  puVar1[0x2b] = 0x4000001f;
  puVar1[0x2c] = uVar9;
  puVar1[0x2d] = uVar10;
  puVar1[0x38] = 0;
  puVar1[0x39] = 0;
  puVar1[0x3a] = 0;
  MTX_Identity33_((undefined4 *)(uintptr_t)(uVar3));
  puVar1 = puRam02011198;
  puRam02011198[0x3b] = 0x1000;
  puVar1[0x3c] = 0x1000;
  puVar1[0x3d] = 0x1000;
  puVar1[0x3e] = 0;
  puVar1[0x3f] = 0;
  puVar1[0x92] = 0;
  puVar1[0x91] = 0;
  puVar1[0x90] = 0;
  puVar1[0x95] = 0;
  puVar1[0x93] = 0;
  puVar1[0x94] = 0x1000;
  puVar1[0x97] = 0;
  puVar1[0x96] = 0;
  puVar1[0x98] = 0xfffff000;
  return;
}

