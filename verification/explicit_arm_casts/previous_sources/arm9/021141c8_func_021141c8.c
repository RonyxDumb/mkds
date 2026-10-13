/* Decompiled C draft; module arm9; ROM address 021141c8. No matching claim. */
#include "types.h"
#include "deps/021141c8_func_021141c8.h"

void func_021141c8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  func_0205ec14(*(undefined4 *)(*piRam02114250 + 8),
                *(ushort *)(*(int *)(*piRam02114250 + 4) + param_1 * 2) & 0xff);
  do {
    if (*(char *)(*piRam02114254 + 0x28) == '\0') {
      if (*(int *)(*piRam02114258 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*piRam02114258 + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
  } while (iVar1 != 0);
  iVar1 = func_0205eca4(*(undefined4 *)(*piRam02114250 + 8),
                        *(ushort *)(*(int *)(*piRam02114250 + 4) + param_1 * 2) & 0xff,param_2);
  if ((iVar1 == 0) || (*(char *)(param_2 + iRam0211425c) == '\0')) {
    *(undefined1 *)(param_2 + iRam0211425c) = 1;
    MIi_CpuCopyFast(*(undefined4 *)(*piRam02114250 + 0xc),param_2);
  }
  func_020ac2fc(param_2,param_3,0x20);
  return;
}

