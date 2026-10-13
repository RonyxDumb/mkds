/* Decompiled C draft; module arm9; ROM address 0205d818. No matching claim. */
#include "types.h"
#include "deps/0205d818_func_0205d818.h"

void func_0205d818(uint param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(ushort *)
           ((*(uint *)(uRam0205d884 & 0xfffffffc) >> (uRam0205d884 & 3) * 8 |
            *(uint *)(uRam0205d884 & 0xfffffffc) << (uRam0205d884 & 3) * -8 + 0x20) + 0x60) - 1;
  iVar2 = iVar1 >> 0x1f;
  iVar2 = (param_1 & 0xff) * 10 +
          (((uint)(iVar1 * 0x40000000 + iVar2) >> 0x1e | iVar2 << 2) - iVar2 & 0xff) * 0x50 +
          (*(uint *)(uRam0205d888 & 0xfffffffc) >> (uRam0205d888 & 3) * 8 |
          *(uint *)(uRam0205d888 & 0xfffffffc) << (uRam0205d888 & 3) * -8 + 0x20);
  *(undefined1 *)(iVar2 + 8) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)(iVar2 + 9) = *(undefined1 *)((int)param_2 + 3);
  *(undefined2 *)(iVar2 + 6) = *param_2;
  return;
}

