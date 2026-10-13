/* Decompiled C draft; module arm9; ROM address 0206c2b4. No matching claim. */
#include "types.h"
#include "deps/0206c2b4_func_0206c2b4.h"

void func_0206c2b4(int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = (ulonglong)uRam0206c350 * (ulonglong)*(uint *)(param_2 + 0x3b0);
  lVar3 = (ulonglong)uRam0206c350 * (ulonglong)*(uint *)(param_2 + 0x3b8);
  iVar1 = ((int)*(uint *)(param_2 + 0x3b8) >> 0x1f) * uRam0206c350;
  *(uint *)(param_1 + 0x40) =
       (uint)lVar2 >> 0xc |
       (((int)*(uint *)(param_2 + 0x3b0) >> 0x1f) * uRam0206c350 + (int)((ulonglong)lVar2 >> 0x20))
       * 0x100000;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(uint *)(param_1 + 0x48) =
       (uint)lVar3 >> 0xc | (iVar1 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
  return;
}

