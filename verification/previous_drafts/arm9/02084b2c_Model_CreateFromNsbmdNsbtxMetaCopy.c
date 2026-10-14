/* Decompiled C draft; module arm9; ROM address 02084b2c. No matching claim. */
#include "types.h"
#include "deps/02084b2c_Model_CreateFromNsbmdNsbtxMetaCopy.h"

uint Model_CreateFromNsbmdNsbtxMetaCopy
               (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  uint uVar8;
  
  uVar2 = Nsbmd_GetMDL0Block(param_3);
  iVar3 = Nsbtx_GetTEX0Block(param_4);
  *(undefined4 *)(param_2 + 0x68) = 0;
  uVar4 = uRam02084c4c;
  *(undefined4 *)(param_2 + 100) = 0;
  IntrusiveListWrapper_InsertLast(uVar4,param_2 + 0x5c);
  *(undefined4 *)(param_2 + 100) = param_3;
  if (iVar3 != 0) {
    *(ushort *)(iVar3 + 0x10) = *(ushort *)(iVar3 + 0x10) & 0xfffe;
    *(ushort *)(iVar3 + 0x20) = *(ushort *)(iVar3 + 0x20) & 0xfffe;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(ushort *)(iVar3 + 0x32) = *(ushort *)(iVar3 + 0x32) & 0xfffe;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    Tex0Block_MaybePrepareFields(iVar3);
    *(int *)(param_2 + 0x68) = iVar3;
    if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == uRam02084c50) {
      func_02010168(uVar2,iVar3);
    }
  }
  iVar3 = Nsbmd_GetMDL0Block(param_3);
  uVar2 = iVar3 + (uint)*(ushort *)(iVar3 + 0xe) + 0xc;
  uVar7 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  StructML_MaybeInnerLoadModel(param_2,iVar3 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20),1);
  uVar2 = param_2 + 0x68U & 3;
  uVar7 = *(uint *)(param_2 + 0x68U & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar2 = param_2 + 4U & 3;
  uVar7 = *(uint *)(param_2 + 4U & 0xfffffffc);
  if (uVar8 != 0) {
    uVar1 = uVar8 + 0x14 & 3;
    uVar5 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
    uVar6 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    uVar4 = Mem_AllocateHeap(param_1,uVar6);
    *(undefined4 *)(param_2 + 0x68) = uVar4;
    uVar1 = param_2 + 0x68U & 3;
    uVar5 = *(uint *)(param_2 + 0x68U & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)(uVar8),(uint *)(uintptr_t)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20),uVar6);
  }
  return uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
}

