/* Decompiled C draft; module arm9; ROM address 0200c16c. No matching claim. */
#include "types.h"
#include "deps/0200c16c_func_0200c16c.h"

undefined1 * func_0200c16c(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = param_2 + 1;
  *param_2 = *param_1;
  switch(*param_1) {
  default:
    return (undefined1 *)0x0;
  case 7:
    *puVar1 = param_1[2];
    if (DAT_0200c204[1] < (int)(uint)(byte)param_1[2]) {
      return (undefined1 *)0x0;
    }
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 3),(uint *)(void *)(param_2 + 2),*DAT_0200c204);
    puVar1 = param_2 + 2 + *DAT_0200c204;
    break;
  case 8:
  case 10:
  case 0xb:
    break;
  case 9:
    *puVar1 = (char)*(undefined2 *)(param_1 + 2);
    param_2[2] = (byte)((ushort)*(undefined2 *)(param_1 + 2) >> 8) & (byte)((uint)DAT_0200c208 >> 8)
    ;
    Mem_CpuCopy8((ushort *)(void *)(param_1 + 4),(uint *)(void *)(param_2 + 3),*DAT_0200c204);
    puVar1 = param_2 + 3 + *DAT_0200c204;
  }
  return puVar1;
}

