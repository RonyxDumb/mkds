/* Decompiled C draft; module arm9; ROM address 020777ac. No matching claim. */
#include "types.h"
#include "deps/020777ac_CreateAnotherGlobalHD_from_thumb.h"

void CreateAnotherGlobalHD_from_thumb(undefined2 param_1)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  iVar5 = Mem_AllocateHeap(uVar4,uRam02077910);
  *piRam02077914 = iVar5;
  StructHD_SomeFn();
  piVar1 = piRam02077914;
  *(undefined2 *)(*piRam02077914 + iRam02077918) = param_1;
  iVar5 = iRam0207791c;
  *(undefined4 *)(*piVar1 + iRam0207791c) = 0;
  *(undefined4 *)(*piVar1 + iRam02077920) = 0;
  *(undefined4 *)(*piVar1 + iRam02077924) = 1;
  if (*(int *)(*piRam02077928 + 0xc) == 6) {
    *(undefined4 *)(*piVar1 + iVar5) = *(undefined4 *)(*piRam0207792c + 0x7c);
  }
  piVar2 = piRam0207792c;
  iVar5 = iRam0207791c;
  piVar1 = piRam02077914;
  if ((*(int *)(*piRam02077928 + 8) == 2) &&
     (*(undefined4 *)(*piRam02077914 + iRam0207791c) = *(undefined4 *)(*piRam0207792c + 0xd0),
     *(int *)(*piVar1 + iVar5) != 0)) {
    uVar6 = 0;
    uVar9 = 0xffffffff;
    uVar7 = 0;
    iVar5 = *piVar2;
    if (*(short *)(iVar5 + 0x80) != 0) {
      do {
        if (*(short *)(*(int *)(iVar5 + 0x7c) + uVar7 * 0x4c + 0x3e) == 7) {
          uVar6 = uVar6 + 1 & 0xffff;
        }
        uVar7 = uVar7 + 1 & 0xffff;
      } while (uVar7 < *(ushort *)(iVar5 + 0x80));
    }
    *puRam02077930 = (short)uVar6;
    uVar4 = Mem_AllocateHeap(uVar4,uVar6 * 0x88);
    *(undefined4 *)(*piRam02077914 + iRam02077934) = uVar4;
    iVar8 = *(int *)(*piRam02077914 + iRam0207791c);
    uVar3 = 0;
    uVar6 = 0;
    iVar5 = *piRam0207792c;
    if (*(short *)(iVar5 + 0x80) != 0) {
      do {
        if ((uVar9 != 0xffffffff) &&
           (iVar8 = *(int *)(iVar5 + 0x7c) + (uVar9 & 0xffff) * 0x4c,
           iVar8 == *(int *)(*piRam02077914 + iRam0207791c))) break;
        if (*(short *)(iVar8 + 0x3e) == 7) {
          func_02077750((int *)(uintptr_t)(*(int *)(*piRam02077914 + iRam02077934) + uVar6 * 0x88),iVar8);
          uVar6 = uVar6 + 1 & 0xffff;
          uVar9 = (uint)*(short *)(iVar8 + 0x48);
        }
        uVar3 = uVar3 + 1;
        iVar5 = *piRam0207792c;
      } while (uVar3 < *(ushort *)(iVar5 + 0x80));
    }
    piVar1 = piRam02077914;
    *(undefined4 *)(*piRam02077914 + iRam02077938) = *(undefined4 *)(*piRam02077914 + iRam02077934);
    *(undefined2 *)(*piVar1 + iRam0207793c) = 0;
    *(undefined4 *)(*piVar1 + iRam02077924) = 3;
    *puRam02077940 = 1;
  }
  return;
}

