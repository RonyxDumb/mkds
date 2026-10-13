/* Decompiled C draft; module arm9; ROM address 0200b200. No matching claim. */
#include "types.h"
#include "deps/0200b200_func_0200b200.h"

void func_0200b200(void)

{
  int iVar1;
  undefined1 local_38 [2];
  undefined1 local_36;
  undefined1 auStack_35 [17];
  undefined4 local_24;
  undefined1 auStack_20 [22];
  undefined2 local_a;
  undefined1 local_8;
  
  iVar1 = *DAT_0200b328;
  switch(*(undefined2 *)(iVar1 + DAT_0200b32c)) {
  default:
    local_38[0] = 0;
    func_0200c16c(local_38,iVar1 + DAT_0200b33c);
    func_0200bc78(8,DAT_0200b340,*DAT_0200b328 + DAT_0200b33c);
    break;
  case 5:
    local_24 = *(undefined4 *)(iVar1 + DAT_0200b330);
    local_a = 1;
    local_8 = (undefined1)*(undefined2 *)(iVar1 + DAT_0200b334);
    Mem_CpuCopy8(iVar1 + DAT_0200b338,auStack_20,0x16);
    local_38[0] = 7;
    local_36 = func_0200c12c(auStack_35,&local_24);
    iVar1 = func_0200c16c(local_38,*DAT_0200b328 + DAT_0200b33c);
    if (iVar1 != 0) {
      func_0200bc78(8,DAT_0200b340,*DAT_0200b328 + DAT_0200b33c);
      return;
    }
    break;
  case 7:
    local_38[0] = 8;
    func_0200c16c(local_38,iVar1 + DAT_0200b33c);
    func_0200bc78(8,DAT_0200b340,*DAT_0200b328 + DAT_0200b33c);
    return;
  case 8:
    break;
  case 9:
    local_38[0] = 10;
    func_0200c16c(local_38,iVar1 + DAT_0200b33c);
    func_0200bc78(8,DAT_0200b340,*DAT_0200b328 + DAT_0200b33c);
    return;
  case 10:
    local_38[0] = 0xb;
    func_0200c16c(local_38,iVar1 + DAT_0200b33c);
    func_0200bc78(8,DAT_0200b340,*DAT_0200b328 + DAT_0200b33c);
    return;
  }
  return;
}

