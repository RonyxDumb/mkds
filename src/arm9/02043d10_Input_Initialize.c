/* Decompiled C draft; module arm9; ROM address 02043d10. No matching claim. */
#include "types.h"
#include "deps/02043d10_Input_Initialize.h"

void Input_Initialize(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  Input_MaybeInitializeTouch();
  CreateGlobal59C4(param_1);
  iVar7 = 0;
  iVar6 = iRam02043f10;
  do {
    AllocateInputRecord((undefined4 *)(uintptr_t)(iVar6 + 0x28),param_1);
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 0x5c;
  } while (iVar7 < 2);
  if (iVar7 < 10) {
    iVar6 = iVar7 * 0x5c + iRam02043f10;
    do {
      StructCYB_ResetInputRecord((undefined4 *)(uintptr_t)(iVar6 + 0x28));
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x5c;
    } while (iVar7 < 10);
  }
  uVar4 = Mem_AllocateHeap(param_1,0x10);
  iVar7 = 0;
  *puRam02043f14 = uVar4;
  uVar4 = uRam02043f18;
  iVar6 = iRam02043f10;
  uVar1 = (undefined2)uRam02043f1c;
  do {
    iVar8 = iVar7 * 0x5c + iVar6;
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar8));
    StructCY_SomeFn_0(iVar8,uVar4,0x1e,10);
    *(undefined4 *)(iVar8 + 0x3c) = 0;
    *(undefined2 *)(iVar8 + 0x40) = 0;
    *(undefined4 *)(iVar8 + 0x44) = 0;
    *(undefined2 *)(iVar8 + 0x42) = uVar1;
    StructCYB_SomeFn(iVar8 + 0x28);
    StructCYA_SomeFn((undefined2 *)(uintptr_t)(iVar8 + 0x48));
    puVar3 = puRam02043f14;
    iVar8 = iRam02043f10;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 10);
  uVar2 = (uint)puRam02043f14 & 3;
  uVar5 = *(uint *)((uint)puRam02043f14 & 0xfffffffc);
  *(undefined4 *)(iRam02043f10 + 0x31c) = 5;
  *(undefined4 *)(iVar8 + 0x378) = 6;
  iVar6 = 0;
  *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 8) = 0;
  uVar2 = (uint)puVar3 & 3;
  uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0xc) = 0;
  uVar4 = uRam02043f18;
  do {
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar8));
    *(undefined2 *)(iVar8 + 0x40) = 0;
    StructCY_SomeFn_0(iVar8,uVar4,0x1e,10);
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 0x5c;
  } while (iVar6 < 10);
  if ((int)(*puRam02043f20 & 0x8000) >> 0xf == 0) {
    *(ushort *)
     ((*(uint *)((uint)puRam02043f14 & 0xfffffffc) >> ((uint)puRam02043f14 & 3) * 8 |
      *(uint *)((uint)puRam02043f14 & 0xfffffffc) << ((uint)puRam02043f14 & 3) * -8 + 0x20) + 2) =
         ((*puRam02043f24 | *puRam02043f20) ^ (ushort)uRam02043f1c) & (ushort)uRam02043f1c;
  }
  else {
    *(undefined2 *)
     ((*(uint *)((uint)puRam02043f14 & 0xfffffffc) >> ((uint)puRam02043f14 & 3) * 8 |
      *(uint *)((uint)puRam02043f14 & 0xfffffffc) << ((uint)puRam02043f14 & 3) * -8 + 0x20) + 2) = 0
    ;
  }
  func_02046d7c();
  if ((int)(*puRam02043f20 & 0x8000) >> 0xf == 0) {
    *(ushort *)
     ((*(uint *)((uint)puRam02043f14 & 0xfffffffc) >> ((uint)puRam02043f14 & 3) * 8 |
      *(uint *)((uint)puRam02043f14 & 0xfffffffc) << ((uint)puRam02043f14 & 3) * -8 + 0x20) + 2) =
         ((*puRam02043f24 | *puRam02043f20) ^ (ushort)uRam02043f1c) & (ushort)uRam02043f1c;
  }
  else {
    *(undefined2 *)
     ((*(uint *)((uint)puRam02043f14 & 0xfffffffc) >> ((uint)puRam02043f14 & 3) * 8 |
      *(uint *)((uint)puRam02043f14 & 0xfffffffc) << ((uint)puRam02043f14 & 3) * -8 + 0x20) + 2) = 0
    ;
  }
  func_02046d7c();
  return;
}

