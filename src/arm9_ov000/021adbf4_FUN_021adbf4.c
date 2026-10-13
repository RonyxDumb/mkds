/* Decompiled C draft; module arm9_ov000; ROM address 021adbf4. No matching claim. */
#include "types.h"
#include "deps/021adbf4_FUN_021adbf4.h"

int FUN_021adbf4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(DAT_021adc60 + 4) + 0xa4);
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(iVar3 + 0x60) != 0) {
    uVar1 = FUN_021adc64(*(undefined4 *)(iVar3 + 0x5c),*(int *)(iVar3 + 0x60),param_1,param_2);
    uVar2 = *(uint *)(iVar3 + 0x60);
    if (uVar1 < uVar2) {
      func_0x02134df8((uint *)(uintptr_t)(*(int *)(iVar3 + 0x5c)),(uint *)(uintptr_t)(*(int *)(iVar3 + 0x5c) + uVar1),uVar2 - uVar1);
      *(uint *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) - uVar1;
      return 0;
    }
    *(undefined4 *)(iVar3 + 0x60) = 0;
    return uVar1 - uVar2;
  }
  iVar3 = FUN_021adc64();
  return iVar3;
}

