/* Decompiled C draft; module arm9; ROM address 0202c960. No matching claim. */
#include "types.h"
#include "deps/0202c960_func_0202c960.h"

void func_0202c960(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_24;
  undefined4 local_1c;
  
  iVar6 = *piRam0202caec;
  uVar2 = (uint)*(ushort *)(*(int *)(iVar6 + 0xc) + 6);
  if (*psRam0202caf0 != 2) {
    func_02025edc((int *)(uintptr_t)(iVar6 + iRam0202caf4));
    uVar1 = func_02025ebc(*piRam0202caec + iRam0202caf4);
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202caf8) = uVar1;
    func_02025edc((int *)(uintptr_t)(*piRam0202caec + iRam0202cafc));
    uVar1 = func_02025ebc(*piRam0202caec + iRam0202cafc);
    iVar3 = iRam0202cb00;
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb00) = uVar1;
    iVar4 = iRam0202cb04;
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb04) =
         *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar3);
    iVar3 = iRam0202cb08;
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb08) =
         *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar4);
    iVar4 = iRam0202cb0c;
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb0c) =
         *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar3);
    iVar3 = iRam0202cb10;
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb10) =
         *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar4);
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + iRam0202cb14) =
         *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar3);
  }
  func_02025edc((int *)(uintptr_t)(*piRam0202caec + iRam0202cb18));
  uVar1 = func_02025ebc(*piRam0202caec + iRam0202cb18);
  iVar3 = func_0202cc78();
  *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar3 * 0x40 + 4) = uVar1;
  iVar4 = func_0202cc8c();
  *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar4 * 0x40 + 4) =
       *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar3 * 0x40 + 4);
  func_02025edc((int *)(uintptr_t)(*piRam0202caec + iRam0202cb1c));
  func_0202cba4();
  local_24 = 0;
  local_1c = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar5 = *piRam0202caec + local_1c;
    uVar1 = ComputeValueInterpolation_from_thumb
                      (1,(int)*(short *)(iRam0202cb20 + *(int *)(iVar5 + 0x58) * 2),
                       (int)*(short *)(iRam0202cb20 + *(int *)(iVar5 + 0x5c) * 2),
                       *(undefined4 *)(iVar5 + 0x50),10);
    *(undefined2 *)
     (*(int *)(iVar6 + 0x18) + (uVar2 + (int)*(short *)(*piRam0202cb24 + iVar4)) * 0x40 + 4) = uVar1
    ;
    *(undefined2 *)
     (*(int *)(iVar6 + 0x18) + (uint)*(ushort *)(*piRam0202cb28 + iVar3 + 4) * 0x40 + 4) =
         *(undefined2 *)
          (*(int *)(iVar6 + 0x18) + (uVar2 + (int)*(short *)(*piRam0202cb24 + iVar4)) * 0x40 + 4);
    *(undefined2 *)
     (*(int *)(iVar6 + 0x18) + (uint)*(ushort *)(*piRam0202cb28 + iVar3 + 2) * 0x40 + 4) =
         *(undefined2 *)
          (*(int *)(iVar6 + 0x18) + (uint)*(ushort *)(*piRam0202cb28 + iVar3 + 4) * 0x40 + 4);
    *(undefined2 *)(*(int *)(iVar6 + 0x18) + (uint)*(ushort *)(*piRam0202cb28 + iVar3) * 0x40 + 4) =
         *(undefined2 *)
          (*(int *)(iVar6 + 0x18) + (uint)*(ushort *)(*piRam0202cb28 + iVar3 + 2) * 0x40 + 4);
    if (local_24 == *(int *)(*piRam0202caec + 0x44)) {
      iVar5 = func_0202cca0();
      *(undefined2 *)(*(int *)(iVar6 + 0x18) + iVar5 * 0x40 + 4) = uVar1;
    }
    local_1c = local_1c + 0x2c;
    iVar4 = iVar4 + 8;
    iVar3 = iVar3 + 6;
    local_24 = local_24 + 1;
  } while (local_24 < 8);
  return;
}

