/* Decompiled C draft; module arm9; ROM address 02010884. No matching claim. */
#include "types.h"
#include "deps/02010884_Tex0_CleanGetKeys.h"

void Tex0_CleanGetKeys(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xfffe;
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xfffe;
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *param_2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *param_3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

