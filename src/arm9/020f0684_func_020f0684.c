/* Decompiled C draft; module arm9; ROM address 020f0684. No matching claim. */
#include "types.h"
#include "deps/020f0684_func_020f0684.h"

void func_020f0684(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_28;
  uint uVar10;
  
  iVar2 = iRam020f0754;
  if (param_3 <= param_2) {
    return;
  }
  uStack_28 = 0;
  do {
    iVar7 = param_2 + -1;
    uVar9 = param_1 + iVar7 * 4;
    uVar3 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar10 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
    uVar9 = param_1 + param_2 * 4;
    uVar3 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar8 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
    uVar9 = uVar10 + 0x74 & 3;
    uVar3 = *(uint *)(uVar10 + 0x74 & 0xfffffffc);
    if (((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0x180000) == 0) {
      iVar4 = func_020f9c08(uVar10);
      if (iVar4 == 0) {
        iVar4 = func_020f9c08(uVar8);
        if (iVar4 != 0) {
          *(uint *)(param_1 + iVar7 * 4) = uVar8;
          *(uint *)(param_1 + param_2 * 4) = uVar10;
        }
      }
      else {
        iVar4 = func_020f9c08(uVar8);
        if (iVar4 != 0) {
          uVar9 = uVar8 + 0xfc & 3;
          uVar3 = *(uint *)(uVar8 + 0xfc & 0xfffffffc);
          iVar4 = uStack_28;
          do {
            uVar6 = iVar2 + iVar4 * 4;
            uVar1 = uVar6 & 3;
            uVar6 = *(uint *)(uVar6 & 0xfffffffc);
            uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
            if (((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & uVar6) != 0) break;
            uVar1 = uVar10 + 0xfc & 3;
            uVar5 = *(uint *)(uVar10 + 0xfc & 0xfffffffc);
            if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & uVar6) != 0) {
              *(uint *)(param_1 + iVar7 * 4) = uVar8;
              *(uint *)(param_1 + param_2 * 4) = uVar10;
              break;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 0xd);
        }
      }
    }
    param_2 = param_2 + param_4;
    if (param_3 <= param_2) {
      return;
    }
  } while( true );
}

