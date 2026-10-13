/* Decompiled C draft; module arm9_ov000; ROM address 02180e58. No matching claim. */
#include "types.h"
#include "deps/02180e58_FUN_02180e58.h"

void FUN_02180e58(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_10 [8];
  
  iVar2 = func_0x02125f88();
  if (iVar2 != 0) {
    if (*(char *)(*DAT_02180f74 + 0x28) == '\0') {
      if (*(int *)(*DAT_02180f78 + 0xc) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*DAT_02180f78 + 0x10);
      }
    }
    else {
      iVar2 = 1;
    }
    if (iVar2 == 0) {
      func_ov000_021806e0(*(undefined4 *)(*DAT_02180f7c + 0xc));
      return;
    }
  }
  iVar2 = func_0x02125fa4();
  if (iVar2 != 0) {
    iVar2 = func_0x0211fd68();
    if (iVar2 == -1) {
      uVar3 = thunk_EXT_FUN_021205f4();
      piVar1 = DAT_02180f7c;
      *(undefined4 *)(*DAT_02180f7c + 0x18) = uVar3;
      iVar2 = *(int *)(*piVar1 + 0x18);
      if (iVar2 < 0) {
        *(int *)(*piVar1 + 0x18) = -iVar2;
      }
      uVar3 = FUN_0218151c(*(undefined4 *)(*DAT_02180f7c + 0x18),0,(uint *)(void *)(auStack_10));
      piVar1 = DAT_02180f7c;
      *(undefined4 *)(*DAT_02180f7c + 4) = 8;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),uVar3);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02180f7c + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      *(undefined4 *)(*DAT_02180f7c + 0x10) = 0;
      func_0x021089f4();
      return;
    }
    if (iVar2 != 0) {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = func_ov000_021806a0();
      piVar1 = DAT_02180f7c;
      if (iVar2 != 0) {
        iVar2 = *DAT_02180f7c;
        if (*(int *)(iVar2 + 0x14) == 0) {
          *(undefined4 *)(iVar2 + 0xc) = 2;
          func_0x02125fc0();
        }
        else {
          *(undefined4 *)(iVar2 + 4) = 5;
          uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x1e);
          uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02180f7c + 0x3c),6);
          func_0x02126570(uVar3,uVar4);
          *(undefined4 *)(*DAT_02180f7c + 0x10) = 0;
        }
      }
      func_0x02108b78();
    }
  }
  return;
}

