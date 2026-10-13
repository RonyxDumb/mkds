/* Decompiled C draft; module arm9; ROM address 0203ad58. No matching claim. */
#include "types.h"
#include "deps/0203ad58_SetGlobalDisplayConfigForDisplayMode.h"

void SetGlobalDisplayConfigForDisplayMode(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(DAT_0203afd8 & 0xfffffffc) >> (DAT_0203afd8 & 3) * 8 |
          *(uint *)(DAT_0203afd8 & 0xfffffffc) << (DAT_0203afd8 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = DAT_0203afdc + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = CreateDisplayConfig(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  DisplayConfig_SetSwapBufferValues(iVar2,1,1);
  DisplayEngineConfig_SetBg0Config((undefined2 *)(uintptr_t)(iVar2 + 0x28),1,0,0,1,0,0,0);
  uVar3 = (*(uint *)(DAT_0203afd8 & 0xfffffffc) >> (DAT_0203afd8 & 3) * 8 |
          *(uint *)(DAT_0203afd8 & 0xfffffffc) << (DAT_0203afd8 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
  case 0:
    goto LAB_0203ade0;
  case 1:
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x28,1,0,0,0,7,0);
    DisplayEngineConfig_SetBg0Config((undefined2 *)(uintptr_t)(iVar2 + 0x70),0,0,0,0,0xd,0,0);
    DisplayEngineConfig_SetBg1Config(iVar2 + 0x70,1,0,0,0,0xe,0,0);
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x70,2,0,0,0,0xf,0);
    func_02056114(0);
    break;
  case 2:
    goto LAB_0203ade0;
  case 3:
    goto LAB_0203af28;
  case 4:
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x28,1,0,0,0,7,0);
    func_02056114(0);
    break;
  case 5:
LAB_0203af28:
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x28,1,0,0,0,7,0);
    DisplayEngineConfig_SetBg2Config(iVar2 + 0x70,0,0,1,0,0);
    DisplayConfig_SetBottomEngineObjVramModeBmp(iVar2,0x20);
    func_02056114(1);
    break;
  case 6:
LAB_0203ade0:
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x28,1,0,0,0,7,0);
    DisplayEngineConfig_SetBg0Config((undefined2 *)(uintptr_t)(iVar2 + 0x70),0,0,0,0,0xd,0,0);
    DisplayEngineConfig_SetBg1Config(iVar2 + 0x70,1,0,0,0,0xe,0,0);
    DisplayEngineConfig_SetBg2Config2(iVar2 + 0x70,2,0,0,0,0xf,0);
    func_02056114(0);
  }
  SetGlobalDisplayConfig(iVar2);
  func_02055f68();
  *DAT_0203afe0 = *DAT_0203afe0 & 0xfffc | 2;
  return;
}

