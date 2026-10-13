/* Decompiled C draft; module arm9; ROM address 02042e0c. No matching claim. */
#include "types.h"
#include "deps/02042e0c_func_02042e0c.h"

void func_02042e0c(undefined4 param_1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  
  iVar7 = *piRam02042ebc;
  puVar2 = *(ushort **)(iVar7 + 0x5c);
  piVar6 = (int *)(iVar7 + 0xac);
  uVar1 = Mem_AllocateHeap(param_1,(uint)*(ushort *)(iVar7 + 0x58) * 0x28);
  *(undefined4 *)(iVar7 + 0xac) = uVar1;
  *(uint *)(iVar7 + 0xb0) = *(int *)(iVar7 + 0xac) + (uint)*puVar2 * 0x28;
  iVar9 = 0;
  iVar3 = *piRam02042ebc;
  if (*(short *)(iVar3 + 0x58) != 0) {
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
      *(undefined1 *)(puVar8 + 8) = 0;
      puVar8[7] = 0;
      iVar5 = iVar5 + 0x28;
      iVar9 = iVar9 + 1;
      iVar3 = *piRam02042ebc;
    } while (iVar9 < (int)(uint)*(ushort *)(iVar3 + 0x58));
  }
  iVar9 = (uint)*(byte *)((int)puVar2 + 7) * 0xc;
  iVar3 = ((uint)*(ushort *)(*(int *)(iVar3 + 0x5c) + iVar9) +
           (uint)*(ushort *)(*(int *)(iVar3 + 0x5c) + iVar9 + 2) + -1) * 0x28;
  *(int *)(iVar7 + 0xb4) = *piVar6 + iVar3;
  func_02042ec0((int *)(uintptr_t)(*piVar6 + iVar3),puVar2,*puVar2);
  return;
}

