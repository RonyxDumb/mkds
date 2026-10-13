/* Decompiled C draft; module arm9; ROM address 02108598. No matching claim. */
#include "types.h"
#include "deps/02108598_SomeAudioInit.h"

void SomeAudioInit(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int unaff_r4;
  int iVar9;
  int iVar10;
  int unaff_r6;
  
  *piRam021086f0 = param_1;
  uVar4 = uRam02108708;
  puVar2 = puRam02108704;
  iVar10 = iRam021086f8;
  if (((param_1 != 0) && (iVar10 = iRam021086fc, param_1 != 1)) && (iVar10 = unaff_r6, param_1 == 2)
     ) {
    iVar10 = iRam021086f4;
  }
  uVar1 = uRam02108700 + 4 & 3;
  uVar6 = *(uint *)(uRam02108700 + 4 & 0xfffffffc);
  *puRam02108704 =
       *(uint *)(uRam02108700 & 0xfffffffc) >> (uRam02108700 & 3) * 8 |
       *(uint *)(uRam02108700 & 0xfffffffc) << (uRam02108700 & 3) * -8 + 0x20;
  puVar2[1] = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  func_0210e4ec((undefined4 *)(uintptr_t)(uVar4));
  uVar4 = Sound_InitializeContext(param_2,iVar10);
  puVar3 = puRam02108710;
  *puRam0210870c = uVar4;
  *puVar3 = 0;
  param_2 = param_2 + iVar10;
  iVar10 = iRam02108718;
  if (((param_1 != 0) && (iVar10 = iRam02108714, param_1 != 1)) && (iVar10 = 0, param_1 == 2)) {
    iVar10 = iRam02108714;
  }
  CreateSetGlobalCX(param_2,iVar10);
  if (param_1 == 2) {
    iVar5 = 0xaf000;
  }
  else {
    iVar5 = 0xc400;
  }
  if (param_1 == 0) {
    iVar7 = 0xc8000;
  }
  else {
    iVar7 = 0xaf000;
  }
  *piRam0210871c = param_2;
  iVar9 = iRam021086f8;
  if (((param_1 != 0) && (iVar9 = iRam021086fc, param_1 != 1)) && (iVar9 = unaff_r4, param_1 == 2))
  {
    iVar9 = iRam021086f4;
  }
  iVar8 = iRam02108718;
  if (((param_1 != 0) && (iVar8 = iRam02108714, param_1 != 1)) && (iVar8 = 0, param_1 == 2)) {
    iVar8 = iRam02108714;
  }
  uVar4 = Sound_InitializeContext(param_2 + iVar10,((iVar7 - iVar5) - iVar9) - iVar8);
  *puRam02108710 = uVar4;
  func_0210e8f8(param_1 == 1);
  return;
}

