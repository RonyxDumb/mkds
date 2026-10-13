/* Decompiled C draft; module arm9; ROM address 0204e928. No matching claim. */
#include "types.h"
#include "deps/0204e928_func_0204e928.h"

void func_0204e928(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(*piRam0204e9e8 + iRam0204e9ec) = param_1;
  uVar3 = Const5F20_from_thumb();
  iVar2 = iRam0204e9f8;
  piVar1 = piRam0204e9e8;
  if ((*psRam0204e9f0 != 2) && (uVar3 < uRam0204e9f4)) {
    uVar3 = uRam0204e9f4;
  }
  *(uint *)(*piRam0204e9e8 + iRam0204e9f8) = uVar3;
  uVar4 = Mem_AllocateHeapAligned(param_1,*(undefined4 *)(*piVar1 + iVar2),0x20);
  piVar1 = piRam0204e9e8;
  *(undefined4 *)(*piRam0204e9e8 + iRam0204e9fc) = uVar4;
  if (*psRam0204e9f0 == 2) {
    *(undefined4 *)(*piVar1 + iRam0204ea00) = 0;
    *(undefined4 *)(*piVar1 + iRam0204ea08) = 0;
    *(undefined4 *)(*piVar1 + iRam0204ea10) = 0;
  }
  else {
    uVar4 = ComputeRomBinarySize_from_thumb(0);
    iVar2 = iRam0204ea00;
    piVar1 = piRam0204e9e8;
    *(undefined4 *)(*piRam0204e9e8 + iRam0204ea00) = uVar4;
    if (uRam0204ea04 < *(uint *)(*piVar1 + iVar2)) {
      *(uint *)(*piVar1 + iVar2) = uRam0204ea04;
    }
    uVar4 = Mem_AllocateHeapAligned(param_1,*(undefined4 *)(*piRam0204e9e8 + iRam0204ea00),0x20);
    *(undefined4 *)(*piRam0204e9e8 + iRam0204ea08) = uVar4;
    SetGlobalBAN_from_thumb(param_3);
    uVar4 = Mem_AllocateHeapAligned(param_1,uRam0204ea0c,0x20);
    *(undefined4 *)(*piRam0204e9e8 + iRam0204ea10) = uVar4;
  }
  StructBin_SomeFn_from_thumb(*piRam0204e9e8 + iRam0204ea08);
  return;
}

