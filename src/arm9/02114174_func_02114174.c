/* Decompiled C draft; module arm9; ROM address 02114174. No matching claim. */
#include "types.h"
#include "deps/02114174_func_02114174.h"

void func_02114174(int param_1)

{
  int iVar1;
  
  func_020607b0(*(ushort *)(*(int *)(*piRam021141bc + 4) + param_1 * 2) & 0xff);
  do {
    if (*(char *)(*piRam021141c0 + 0x28) == '\0') {
      if (*(int *)(*piRam021141c4 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*piRam021141c4 + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
  } while (iVar1 != 0);
  func_021143f4();
  return;
}

