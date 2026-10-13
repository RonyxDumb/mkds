/* Decompiled C draft; module arm9; ROM address 02151868. No matching claim. */
#include "types.h"
#include "deps/02151868_StructDW_SomeFn_0_from_thumb.h"

undefined4 StructDW_SomeFn_0_from_thumb(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *piRam021518fc;
  StructDW_SomeFn_2_from_thumb();
  SomeHashing(param_2 + iRam02151900,uRam02151904);
  iVar3 = iRam02151908;
  iVar5 = 0;
  do {
    iVar2 = func_0215122c(iVar4,iVar3,param_2);
    if (iVar2 == 0) {
      Os_Terminate();
      return 0;
    }
    Mem_CpuCopy8(uRam0215190c,param_2 + 0xf0,0xe);
    uVar1 = func_020205e8(param_2 + iRam02151900,param_2,0xfe);
    *(undefined2 *)(param_2 + 0xfe) = uVar1;
    do {
      func_021511d8(iVar4,iVar3,param_2);
      iVar2 = StructDC_SomeFn_5_from_thumb(param_2,iVar4,iVar3,param_2 + iVar3);
    } while (iVar2 == 0);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + iVar3;
  } while (iVar5 < 2);
  iVar3 = func_02151154();
  if (iVar3 != 0) {
    return 1;
  }
  return 0;
}

