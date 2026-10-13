/* Decompiled C draft; module arm9; ROM address 0211f4b0. No matching claim. */
#include "types.h"
#include "deps/0211f4b0_func_0211f4b0.h"

void func_0211f4b0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar2 = Mem_AllocateHeap(param_1,0x28);
  piVar1 = piRam0211f58c;
  *piRam0211f58c = iVar2;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  *(undefined4 *)(*piVar1 + 0x18) = param_2;
  func_0211f61c();
  iVar2 = *piRam0211f58c;
  func_02124ed0(param_1,*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0xc),(undefined4 *)(uintptr_t)(iVar2 + 0x10));
  uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0211f590);
  *(undefined4 *)(*piRam0211f58c + 0x14) = uVar3;
  uVar3 = func_02148ca0();
  puVar5 = (undefined4 *)*piRam0211f58c;
  func_021243ac(param_1,0xe,puVar5[3],200,0xd,0,*puVar5,puVar5[1],puVar5[4],uVar3);
  iVar2 = *piRam0211f58c;
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar2 + 0x14),0x79);
  func_0212426c(1,0xe,*(undefined4 *)(*piRam0211f58c + 0xc),uVar3,*(undefined4 *)(iVar2 + 4),
                *(undefined4 *)(iVar2 + 0x10));
  piVar1 = piRam0211f58c;
  iVar2 = 0;
  uVar4 = (uint)*(ushort *)(*(int *)(*piRam0211f58c + 4) + 6);
  if (uVar4 != 0) {
    iVar6 = 0;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x10) + iVar6) = 0;
      iVar6 = iVar6 + 0x40;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar4);
  }
  piVar1 = piRam0211f58c;
  *(undefined4 *)(*(int *)(*piRam0211f58c + 0x10) + iRam0211f594) = 1;
  func_02116dd4(param_1,*(undefined4 *)*piVar1,((undefined4 *)*piVar1)[1],0x2a,0xe,1);
  func_0211f5e4();
  func_0211f5d0();
  func_0211f39c();
  return;
}

