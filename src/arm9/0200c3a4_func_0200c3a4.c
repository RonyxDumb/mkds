/* Decompiled C draft; module arm9; ROM address 0200c3a4. No matching claim. */
#include "types.h"
#include "deps/0200c3a4_func_0200c3a4.h"

undefined1 * func_0200c3a4(undefined1 *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + 1;
  *param_2 = *param_1;
  switch(*param_1) {
  default:
    return (undefined1 *)0x0;
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
    break;
  case 4:
    *puVar2 = (char)*(undefined2 *)(param_1 + 2);
    bVar1 = (byte)((uint)DAT_0200c3f8 >> 8);
    param_2[2] = (byte)((ushort)*(undefined2 *)(param_1 + 2) >> 8) & bVar1;
    param_2[3] = (char)*(undefined2 *)(param_1 + 4);
    puVar2 = param_2 + 5;
    param_2[4] = (byte)((ushort)*(undefined2 *)(param_1 + 4) >> 8) & bVar1;
  }
  return puVar2;
}

