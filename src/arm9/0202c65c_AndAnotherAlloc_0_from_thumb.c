/* Decompiled C draft; module arm9; ROM address 0202c65c. No matching claim. */
#include "types.h"
#include "deps/0202c65c_AndAnotherAlloc_0_from_thumb.h"

void AndAnotherAlloc_0_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar2 = Mem_CreateOrphanChildHeap();
  iVar3 = Mem_AllocateHeap(uVar2,uRam0202c7fc);
  *piRam0202c800 = iVar3;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar3),uRam0202c7fc);
  piVar1 = piRam0202c800;
  *(undefined4 *)(*piRam0202c800 + 0x3c) = uVar2;
  *(undefined4 *)(*piVar1 + 0x38) = param_2;
  if (*psRam0202c804 == 2) {
    *piRam0202c80c = iRam0202c808;
    *piRam0202c814 = iRam0202c810;
    *puRam0202c81c = uRam0202c818;
    *puRam0202c824 = uRam0202c820;
  }
  else {
    *piRam0202c80c = iRam0202c828;
    *piRam0202c814 = iRam0202c82c;
    *puRam0202c81c = uRam0202c830;
    *puRam0202c824 = uRam0202c834;
  }
  iVar3 = func_02148cb8();
  iVar5 = *piRam0202c800;
  if (*psRam0202c804 == 2) {
    func_02025b20(iVar5,uRam0202c844,uRam0202c848,uRam0202c84c,uRam0202c838,uRam0202c83c,0,
                  uRam0202c840);
  }
  else {
    func_02025b20(iVar5,uRam0202c85c,uRam0202c860,uRam0202c864,uRam0202c850,uRam0202c854,0,
                  uRam0202c858);
  }
  func_02124ed0(*(undefined4 *)(*piRam0202c800 + 0x3c),*(undefined4 *)(iVar5 + 0xc),
                *(undefined4 *)(iVar5 + 0x14),(undefined4 *)(uintptr_t)(iVar5 + 0x18));
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar4 = func_02025a00(0,*(undefined4 *)(*piRam0202c800 + 0x3c),iVar5,(short *)(uintptr_t)(*piRam0202c814 + iVar6),
                          iVar3);
    piVar1 = piRam0202c80c;
    iVar3 = iVar3 - iVar4;
    iVar6 = iVar6 + 8;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  iVar3 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + (uint)*(ushort *)(*piVar1 + iVar6 + 4) * 0x40) = 0;
    iVar7 = *piVar1 + iVar6;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + (uint)*(ushort *)(iVar7 + 2) * 0x40) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + (uint)*(ushort *)(iVar7 + 4) * 0x40);
    iVar6 = iVar6 + 6;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  func_0202cbf4();
  func_02025f80(*piRam0202c800 + iRam0202c868,0,10,0xffffffc0,0);
  func_02025f80(*piRam0202c800 + iRam0202c86c,3,10,0x60,0);
  func_02025f80(*piRam0202c800 + iRam0202c870,3,10,0x40,0);
  if (*psRam0202c804 != 2) {
    func_02025b20(*piRam0202c800 + 0x1c,uRam0202c878,uRam0202c87c,0,uRam0202c874,0,0,uRam0202c858);
  }
  piVar1 = piRam0202c800;
  *(undefined4 *)(*piRam0202c800 + iRam0202c880) = 1;
  func_02036820(*(undefined4 *)(*piVar1 + 0x3c));
  return;
}

