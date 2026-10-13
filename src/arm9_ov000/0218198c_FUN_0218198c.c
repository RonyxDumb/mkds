/* Decompiled C draft; module arm9_ov000; ROM address 0218198c. No matching claim. */
#include "types.h"
#include "deps/0218198c_FUN_0218198c.h"

void FUN_0218198c(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = func_ov000_021806c4();
  if (iVar3 == -1) {
    if ((*(int *)(*DAT_02181aa8 + 0x10) == 10) && (iVar3 = func_0x0211fd68(), iVar3 != 1)) {
      func_ov000_021806b8(0);
    }
    else if (*(int *)(*DAT_02181aa8 + 0x10) == 0xd) {
      *(undefined4 *)(*DAT_02181aac + 0x20) = 4;
      func_ov000_021806b8(0xc);
    }
  }
  piVar1 = DAT_02181aa8;
  *(int *)(*DAT_02181aa8 + 0xc) = *(int *)(*DAT_02181aa8 + 0xc) + 1;
  if (*(int *)(*piVar1 + 0xc) < 0xb) {
    uVar2 = func_0x020ae4c0(1,0xdc,0,10 - *(int *)(*piVar1 + 0xc),10);
  }
  else {
    uVar2 = 0xdc;
  }
  piVar1 = DAT_02181aa8;
  iVar6 = 0;
  piVar4 = DAT_02181ab4;
  iVar3 = DAT_02181ab0;
  do {
    iVar5 = 0;
    if (0 < *piVar4) {
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar3 + iVar5) * 0x40 + 4) =
             uVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *piVar4);
    }
    iVar3 = iVar3 + 5;
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  if ((9 < *(int *)(*DAT_02181aa8 + 0xc)) &&
     (((iVar3 = *(int *)(*DAT_02181aa8 + 0x10), iVar3 != 10 && (iVar3 != 0xd)) ||
      (iVar3 = func_0x02128274(), iVar3 != 0)))) {
    iVar3 = func_ov000_021806c4();
    if (iVar3 == -1) {
      if ((*(int *)(*DAT_02181aa8 + 0x10) == 8) &&
         (iVar3 = thunk_EXT_FUN_02061250(), piVar1 = DAT_02181aa8, iVar3 == 0)) {
        *(undefined4 *)(*DAT_02181aa8 + 4) = 8;
        *(undefined4 *)(*piVar1 + 0x10) = 0xffffffff;
        func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x12);
        func_0x021266e4();
        *(undefined4 *)(*DAT_02181aa8 + 0xc) = 0;
        func_0x021281c8(0xe);
        return;
      }
      func_ov000_021806e0(*(undefined4 *)(*DAT_02181aa8 + 0x10));
    }
  }
  return;
}

