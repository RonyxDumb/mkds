/* Decompiled C draft; module arm9; ROM address 0205d7c8. No matching claim. */
#include "types.h"
#include "deps/0205d7c8_func_0205d7c8.h"

void func_0205d7c8(undefined2 *param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_2 & 0xff) * 10 +
          param_3 * 0x50 +
          (*(uint *)(uRam0205d814 & 0xfffffffc) >> (uRam0205d814 & 3) * 8 |
          *(uint *)(uRam0205d814 & 0xfffffffc) << (uRam0205d814 & 3) * -8 + 0x20);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(iVar1 + 8);
  *(undefined1 *)((int)param_1 + 3) = *(undefined1 *)(iVar1 + 9);
  *param_1 = *(undefined2 *)(iVar1 + 6);
  return;
}

