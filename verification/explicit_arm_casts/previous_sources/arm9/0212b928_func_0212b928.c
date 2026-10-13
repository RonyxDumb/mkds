/* Decompiled C draft; module arm9; ROM address 0212b928. No matching claim. */
#include "types.h"
#include "deps/0212b928_func_0212b928.h"

void func_0212b928(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)Mem_AllocateHeap(param_1,0x90);
  piVar1 = piRam0212b9e0;
  *piRam0212b9e0 = (int)puVar3;
  *puVar3 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(char *)(*piVar1 + 8) = (char)param_3;
  *(undefined4 *)(*piVar1 + 0x8c) = 1;
  Mem_CpuCopy8(*(int *)(param_2 + 0xc) + param_3 * 0x20,*piVar1 + 10,0x20);
  piVar1 = piRam0212b9e0;
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar4 = (uint)*(ushort *)(*piVar1 + iVar6 + 0x14);
    *(uint *)(*piVar1 + iVar5 + 0x2c) = uVar4 & 0x1f;
    *(int *)(*piVar1 + iVar5 + 0x30) = (int)(uVar4 & uRam0212b9e4) >> 5;
    *(int *)(*piVar1 + iVar5 + 0x34) = (int)(uVar4 & uRam0212b9e8) >> 10;
    piVar2 = piRam0212b9e0;
    iVar6 = iVar6 + 2;
    iVar5 = iVar5 + 0xc;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  iVar5 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    uVar4 = (uint)*(ushort *)(*piVar2 + iVar7 + 0x1c);
    *(uint *)(*piVar2 + iVar6 + 0x5c) = uVar4 & 0x1f;
    *(int *)(*piVar2 + iVar6 + 0x60) = (int)(uVar4 & uRam0212b9e4) >> 5;
    *(int *)(*piVar2 + iVar6 + 100) = (int)(uVar4 & uRam0212b9e8) >> 10;
    iVar7 = iVar7 + 2;
    iVar6 = iVar6 + 0xc;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  return;
}

