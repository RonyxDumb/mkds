/* Decompiled C draft; module arm9; ROM address 02008310. No matching claim. */
#include "types.h"
#include "deps/02008310_func_02008310.h"

undefined4 func_02008310(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_1c;
  
  local_1c = 0xff;
  uVar4 = Os_DisableIrq();
  iVar5 = func_02009958();
  if (iVar5 == 0) {
    Os_RestoreIrq(uVar4);
    return 0;
  }
  iVar5 = *piRam020084b8;
  if (0x10 < *(byte *)(iVar5 + iRam020084bc) + 1) {
    Os_RestoreIrq(uVar4);
    return 0;
  }
  uVar7 = 0;
  do {
    iVar6 = iVar5 + iRam020084c4 * uVar7;
    if (*(int *)(iVar6 + iRam020084c8) == param_1) {
      Os_RestoreIrq(uVar4);
      return 0;
    }
    uVar3 = uVar7;
  } while ((*(char *)(iVar6 + iRam020084c0) != '\0') &&
          (uVar7 = uVar7 + 1 & 0xff, uVar3 = local_1c, uVar7 < 0x10));
  local_1c = uVar3;
  if (uVar7 != 0x10) {
    iVar6 = iRam020084c4 * local_1c;
    *(int *)(iVar5 + iVar6 + iRam020084c8) = param_1;
    iVar5 = *piRam020084b8 + iRam020084cc + iVar6;
    func_020082b4((undefined4 *)(uintptr_t)(iVar5),param_2);
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 + 0x1c),(uint *)(uintptr_t)(iVar5 + 0xc4),0x20);
    iVar5 = func_020080e8(*piRam020084b8 + iRam020084d0 + iVar6,iVar5);
    if (iVar5 != 0) {
      func_02009828(*piRam020084b8 + iRam020084d4 + iVar6,param_1,*piRam020084b8 + iRam020084d8);
      piVar2 = piRam020084b8;
      *(char *)(*piRam020084b8 + iVar6 + iRam020084dc) = (char)local_1c;
      func_020096f4(*piVar2 + iRam020084d4 + iVar6);
      cVar1 = *pcRam020084e0;
      *pcRam020084e0 = cVar1 + '\x01';
      piVar2 = piRam020084b8;
      *(char *)(*piRam020084b8 + iVar6 + iRam020084e4) = cVar1;
      *(undefined2 *)(*piVar2 + iVar6 + iRam020084e8) = 1;
      *(int *)(*piVar2 + iVar6 + iRam020084ec) = param_2;
      iVar5 = iRam020084f4;
      *(int *)(*piVar2 + iVar6 + iRam020084f4) = param_2 + iRam020084f0;
      *(int *)(*piVar2 + iVar6 + iRam020084fc) = param_2 + iRam020084f8;
      if ((*(int *)(*(int *)(*piVar2 + iVar6 + iVar5) + 0x6c) != 0) &&
         (iVar5 = IsGlobalANSet_from_thumb(), iVar5 == 0)) {
        StructANN_Create_from_thumb(*piRam020084b8 + iRam02008500);
        InitializeSetGlobalAN_from_thumb(*piRam020084b8 + iRam02008504,uRam02008508);
      }
      piVar2 = piRam020084b8;
      *(undefined1 *)(*piRam020084b8 + iVar6 + iRam020084c0) = 1;
      *(char *)(*piVar2 + iRam020084bc) = *(char *)(*piVar2 + iRam020084bc) + '\x01';
      Os_RestoreIrq(uVar4);
      return 1;
    }
    Os_RestoreIrq(uVar4);
    return 0;
  }
  Os_RestoreIrq(uVar4);
  return 0;
}

