/* Decompiled C draft; module arm9_ov000; ROM address 021ae984. No matching claim. */
#include "types.h"
#include "deps/021ae984_FUN_021ae984.h"

void FUN_021ae984(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_021af090();
  if (puVar2 != (undefined4 *)0x0) {
    cVar1 = *(char *)(puVar2 + 2);
    if (cVar1 == '\x04') {
      puVar2[9] = puVar2[9] + 1;
      FUN_021aefa8(puVar2,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x15);
      *(undefined1 *)(puVar2 + 2) = 6;
      return;
    }
    if (cVar1 == '\a') {
      puVar2[9] = puVar2[9] + 1;
      FUN_021aefb4(puVar2,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x13);
      *(undefined1 *)(puVar2 + 2) = 9;
      return;
    }
    if (cVar1 == '\b') {
      puVar2[9] = puVar2[9] + 1;
      FUN_021aefb4(puVar2,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x14);
      *(undefined1 *)(puVar2 + 2) = 0;
      if (puVar2[1] == 2) {
        puVar2[1] = 0;
        func_0x0200df68(*puVar2);
        return;
      }
    }
    else {
      FUN_021aeed8(param_1,param_2,param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x16);
    }
  }
  return;
}

