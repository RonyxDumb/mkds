/* Decompiled C draft; module arm9; ROM address 02008e10. No matching claim. */
#include "types.h"
#include "deps/02008e10_func_02008e10.h"

void func_02008e10(undefined4 param_1,int param_2,undefined2 param_3)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int iVar4;
  
  func_02008dbc();
  func_02008d68(param_2);
  func_02008d30(param_2);
  iVar4 = *piRam02008ed0 + 0x10 + iRam02008ed4 * param_2;
  if (*(char *)(iVar4 + iRam02008ed8) == *(char *)(*piRam02008edc + 7)) {
    pbVar2 = (byte *)(iVar4 + iRam02008ee0);
    *pbVar2 = *pbVar2 + 1;
    if (3 < *pbVar2) {
      *(undefined2 *)(iVar4 + iRam02008ee4) = 0;
      func_02008cbc(iVar4 + iRam02008ee8);
      return;
    }
  }
  else {
    *(undefined1 *)(iVar4 + iRam02008ee0) = 0;
  }
  piVar1 = piRam02008edc;
  *(undefined1 *)(iVar4 + iRam02008ed8) = *(undefined1 *)(*piRam02008edc + 7);
  *(short *)(iVar4 + iRam02008ee4) = (short)uRam02008eec;
  puVar3 = (undefined4 *)(iVar4 + iRam02008ef0);
  *puVar3 = *(undefined4 *)*piVar1;
  *(byte *)(iVar4 + iRam02008ef4) = *(byte *)(*piVar1 + 4) >> 2;
  *(undefined2 *)(iVar4 + iRam02008ef8) = param_3;
  func_020091e0(iVar4 + iRam02008efc,*puVar3);
  if ((*(byte *)(*piRam02008edc + 4) & 3) == 2) {
    func_02008aa0(param_2);
    return;
  }
  func_02008c08(param_2);
  return;
}

