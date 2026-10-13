/* Decompiled C draft; module arm9; ROM address 020061d8. No matching claim. */
#include "types.h"
#include "deps/020061d8_func_020061d8.h"

void func_020061d8(int param_1,int param_2,uint param_3,undefined2 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + DAT_02006284);
  iVar1 = param_1 + DAT_02006288 + param_3 * 0x68;
  if ((param_2 == 0xd) || (*(char *)(iVar1 + 2) != *(char *)(iVar1 + 3))) {
    *puVar2 = 0xc;
    *(short *)((int)puVar2 + 10) = (short)(1 << (param_3 & 0xff));
    *(undefined1 *)(iVar1 + 3) = *(undefined1 *)(iVar1 + 2);
    *(undefined1 *)((int)puVar2 + 0xd) = *(undefined1 *)(iVar1 + 2);
    *(undefined2 *)((int)puVar2 + 0xe) = param_4;
    if (param_2 < 3) {
      if (param_2 == 2) {
        *(undefined2 *)(puVar2 + 5) = *(undefined2 *)(iVar1 + 10);
        *(undefined2 *)((int)puVar2 + 0x16) = *(undefined2 *)(iVar1 + 6);
        *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(iVar1 + 4);
      }
    }
    else {
      switch(param_2) {
      case 8:
        puVar2[5] = *(undefined4 *)(iVar1 + 0x10);
        break;
      case 10:
        if (*(byte *)(iVar1 + 0xd) < 10) {
          *(byte *)((int)puVar2 + 0x1d) = *(byte *)(iVar1 + 0xd);
          Mem_CpuCopy8((ushort *)(uintptr_t)(*(undefined4 *)(iVar1 + 0x20)),puVar2 + 5,*(undefined1 *)((int)puVar2 + 0x1d))
          ;
        }
        else {
          *(undefined1 *)((int)puVar2 + 0x1d) = 0;
        }
      }
    }
    puVar2[1] = param_2;
    if ((code *)puVar2[4] != (code *)0x0) {
      (*(code *)puVar2[4])(puVar2);
    }
  }
  return;
}

