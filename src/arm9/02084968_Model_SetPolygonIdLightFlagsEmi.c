/* Decompiled C draft; module arm9; ROM address 02084968. No matching claim. */
#include "types.h"
#include "deps/02084968_Model_SetPolygonIdLightFlagsEmi.h"

void Model_SetPolygonIdLightFlagsEmi
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  ModelBlock_SetPolygonId(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  ModelBlock_SetLight(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_3);
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  ModelBlock_SetEmi(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_4);
  return;
}

