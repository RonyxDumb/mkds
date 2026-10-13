/* Decompiled C draft; module arm9; ROM address 02042c3c. No matching claim. */
#include "types.h"
#include "deps/02042c3c_func_02042c3c.h"

void func_02042c3c(undefined4 param_1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  
  iVar7 = *piRam02042d30;
  puVar2 = *(ushort **)(iVar7 + 0x6c);
  piVar6 = (int *)(iVar7 + 0xa0);
  uVar1 = Mem_AllocateHeap(param_1,(uint)*(ushort *)(iVar7 + 0x68) * 0x28);
  *(undefined4 *)(iVar7 + 0xa0) = uVar1;
  *(uint *)(iVar7 + 0xa4) = *(int *)(iVar7 + 0xa0) + (uint)*puVar2 * 0x28;
  iVar10 = 0;
  iVar3 = *piRam02042d30;
  if (*(short *)(iVar3 + 0x68) != 0) {
    iVar5 = 0;
    do {
      puVar8 = (undefined4 *)(*piVar6 + iVar5);
      iVar3 = 0;
      puVar4 = puVar8;
      do {
        puVar4[3] = 0;
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      *(undefined2 *)(puVar8 + 9) = 0;
      *(undefined2 *)((int)puVar8 + 0x26) = 0;
      puVar8[6] = 0;
      puVar8[8] = 0;
      puVar8[7] = 0;
      iVar5 = iVar5 + 0x28;
      iVar10 = iVar10 + 1;
      iVar3 = *piRam02042d30;
    } while (iVar10 < (int)(uint)*(ushort *)(iVar3 + 0x68));
  }
  iVar10 = (uint)*(byte *)((int)puVar2 + 7) * 0xc;
  iVar3 = ((uint)*(ushort *)(*(int *)(iVar3 + 0x6c) + iVar10) +
           (uint)*(ushort *)(*(int *)(iVar3 + 0x6c) + iVar10 + 2) + -1) * 0x28;
  *(int *)(iVar7 + 0xa8) = *piVar6 + iVar3;
  func_02042d34((int *)(uintptr_t)(*piVar6 + iVar3),puVar2,*puVar2);
  uVar9 = 0;
  iVar3 = *piRam02042d30;
  if (*(short *)(iVar3 + 0x70) != 0) {
    do {
      iVar7 = (uVar9 & 0xffff) * 0xc;
      if (*(short *)(*piVar6 + (uint)*(ushort *)(*(int *)(iVar3 + 0x6c) + iVar7) * 0x28 + 0x24) == 0
         ) {
        func_02042d34(0,*(int *)(iVar3 + 0x6c) + iVar7);
      }
      uVar9 = uVar9 + 1;
      iVar3 = *piRam02042d30;
    } while ((int)uVar9 < (int)(uint)*(ushort *)(iVar3 + 0x70));
  }
  return;
}

