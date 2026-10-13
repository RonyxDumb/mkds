/* Decompiled C draft; module arm9; ROM address 02033ab8. No matching claim. */
#include "types.h"
#include "deps/02033ab8_func_02033ab8.h"

void func_02033ab8(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *piRam02033b70;
  iVar3 = iVar1 + 0x48 + param_1 * 0x1c;
  if (param_4 == 1) {
    puVar2 = (undefined4 *)(iVar1 + 0x80);
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x9c);
  }
  iVar1 = *(int *)(*piRam02033b74 + (param_2 & 0xffff) * 0x30 + 0x68);
  func_0212463c(iVar1,puVar2[2],*puVar2,puVar2[1],puVar2[3],param_1,param_3,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc));
  if (iVar1 == 0xc) {
    if (param_4 == 1) {
      iVar1 = *(int *)(*piRam02033b70 + 0xc0);
    }
    else {
      iVar1 = *(int *)(*piRam02033b70 + 0xc4);
    }
    iVar3 = func_02124a68(param_3,*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc));
    iVar1 = *(int *)(iVar1 + 0xc) + *(int *)(*piRam02033b78 + param_2 * 4 + iRam02033b7c) * 0x20;
    if (param_1 == 0) {
      AllocateReserveTEQSub(0xe,iVar3 << 5,iVar1,0x20);
      return;
    }
    AllocateReserveTEQSub(0x1e,iVar3 << 5,iVar1,0x20);
  }
  return;
}

