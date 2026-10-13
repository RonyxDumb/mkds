/* Decompiled C draft; module arm9; ROM address 020f8148. No matching claim. */
#include "types.h"
#include "deps/020f8148_func_020f8148.h"

byte * func_020f8148(uint *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  
  uVar7 = (uint)*param_2;
  pbVar8 = param_2 + 2;
  bVar1 = param_2[1];
  *param_1 = uVar7;
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar3,(uVar7 + 1) * 0x24);
  param_1[1] = uVar4;
  uVar4 = param_1[1];
  iVar10 = 0;
  if (bVar1 != 0) {
    iVar6 = 0;
    do {
      iVar9 = 0;
      if (uVar7 != 0) {
        puVar5 = (ushort *)(uVar4 + iVar6);
        do {
          bVar2 = *pbVar8;
          pbVar8 = pbVar8 + 1;
          *puVar5 = (ushort)bVar2;
          puVar5 = puVar5 + 0x12;
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar7);
      }
      *(short *)(iVar6 + uVar4 + iVar9 * 0x24) = (short)uRam020f81b4;
      iVar6 = iVar6 + 2;
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)(uint)bVar1);
  }
  return pbVar8;
}

