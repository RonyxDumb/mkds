/* Decompiled C draft; module arm9; ROM address 02033b80. No matching claim. */
#include "types.h"
#include "deps/02033b80_func_02033b80.h"

void func_02033b80(int param_1)

{
  undefined4 uVar1;
  short extraout_r1;
  short extraout_r1_00;
  short extraout_r1_01;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short local_1e [5];
  
  iVar3 = *piRam02033c78;
  iVar2 = iVar3 + param_1 * 0xc;
  iVar6 = *(int *)(iVar2 + 0xec);
  iVar7 = *(int *)(iVar2 + 0xe8);
  iVar2 = *piRam02033c7c;
  if (((*(int *)(iVar2 + 8) == 2) && (*(char *)(iVar2 + 0x58) != '\0')) &&
     (*(int *)(iVar2 + 0x1c) == 1)) {
    *(undefined4 *)(*(int *)(iVar3 + 0x7c) + (iVar6 + 0x38) * 0x40) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0x7c) + (iVar6 + 0x48) * 0x40) = 0;
    return;
  }
  Mem_CpuFill16(0,local_1e,8);
  if (99 < iVar7) {
    uVar1 = _s32_div_f(iVar7,100);
    _s32_div_f(uVar1,10);
    local_1e[0] = extraout_r1 + 0x30;
  }
  uVar4 = (uint)(99 < iVar7);
  uVar5 = uVar4;
  if (9 < iVar7) {
    uVar1 = _s32_div_f(iVar7,10);
    _s32_div_f(uVar1,10);
    uVar5 = uVar4 + 1;
    local_1e[uVar4] = extraout_r1_00 + 0x30;
  }
  _s32_div_f(iVar7,10);
  local_1e[uVar5] = extraout_r1_01 + 0x30;
  local_1e[uVar5 + 1] = 0;
  func_02124224(1,iVar6 + 8,*(undefined4 *)(iVar3 + 0x78),local_1e,*(undefined4 *)(iVar3 + 0x70),
                *(undefined4 *)(iVar3 + 0x7c),6);
  *(undefined4 *)(*(int *)(iVar3 + 0x7c) + (iVar6 + 0x38) * 0x40) = 1;
  func_02025c48(iVar6 + 0x38,*(int *)(*piRam02033c78 + param_1 * 0xc + 0xe4) + 0x40,
                *(undefined4 *)(iVar3 + 0x70));
  return;
}

