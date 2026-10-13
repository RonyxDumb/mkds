/* Decompiled C draft; module arm9; ROM address 02042894. No matching claim. */
#include "types.h"
#include "deps/02042894_NkmHandler_KTPJ_from_thumb.h"

undefined4
NkmHandler_KTPJ_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam02042980;
  *(undefined2 *)(*piRam02042980 + 0x28) = uVar2;
  *(undefined4 *)(*piVar1 + 0x24) = local_10;
  if (*(int *)(*piRam02042984 + 8) == 2) {
    uVar8 = (uint)*(ushort *)(*piVar1 + 0x28);
    uVar3 = Mem_AllocateHeap(uVar3,uVar8 << 1);
    piVar1 = piRam02042980;
    *(undefined4 *)(*piRam02042980 + 0xf8) = uVar3;
    iVar7 = 0;
    *(undefined2 *)(*piVar1 + iRam02042988) = 0;
    if (uVar8 != 0) {
      iVar5 = 0;
      do {
        *(short *)(*(int *)(*piVar1 + 0xf8) + iVar5) = (short)iVar7;
        iVar5 = iVar5 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)uVar8);
    }
  }
  else {
    iVar7 = *piVar1;
    if (*(short *)(iVar7 + 0x28) != 0) {
      iVar5 = 0;
      iVar6 = 0;
      if (*(short *)(iVar7 + 0x28) != 0) {
        iVar4 = *(int *)(iVar7 + 0x24);
        do {
          if (iVar5 < *(short *)(iVar4 + 0x1c)) {
            iVar5 = (int)*(short *)(iVar4 + 0x1c);
          }
          iVar4 = iVar4 + 0x20;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(uint)*(ushort *)(iVar7 + 0x28));
      }
      uVar3 = Mem_AllocateHeap(uVar3,(iVar5 + 1) * 2);
      piVar1 = piRam02042980;
      *(undefined4 *)(*piRam02042980 + 0xf8) = uVar3;
      uVar3 = uRam0204298c;
      iVar7 = 0;
      if (0 < iVar5 + 1) {
        iVar6 = 0;
        do {
          *(short *)(*(int *)(*piVar1 + 0xf8) + iVar6) = (short)uVar3;
          iVar6 = iVar6 + 2;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5 + 1);
      }
      piVar1 = piRam02042980;
      iVar7 = 0;
      if (*(short *)(*piRam02042980 + 0x28) != 0) {
        iVar5 = 0;
        do {
          iVar6 = *piVar1;
          *(short *)(*(int *)(iVar6 + 0xf8) + *(short *)(*(int *)(iVar6 + 0x24) + iVar5 + 0x1c) * 2)
               = (short)iVar7;
          iVar5 = iVar5 + 0x20;
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*(ushort *)(*piVar1 + 0x28));
      }
    }
  }
  return 1;
}

