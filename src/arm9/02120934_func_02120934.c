/* Decompiled C draft; module arm9; ROM address 02120934. No matching claim. */
#include "types.h"
#include "deps/02120934_func_02120934.h"

void func_02120934(int param_1,int param_2)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    *(undefined4 *)
     ((*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
      *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x18e8) = 4;
    return;
  }
  if (param_2 == 0) {
    *(undefined1 *)
     ((*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
      *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x1f55) = 0;
    uVar2 = func_0x0219bb68();
    uVar1 = uRam02120a60;
    uVar5 = 0;
    *(undefined1 *)
     ((*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
      *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x1f52) = uVar2;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    *(undefined1 *)(uVar3 + 0x1f53) = *(undefined1 *)(uVar3 + 0x1f52);
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    if (*(char *)(uVar3 + 0x1f53) != '\0') {
      do {
        *(byte *)(uVar3 + 0x1f55) = *(byte *)(uVar3 + 0x1f55) | (byte)(1 << uVar5);
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < *(byte *)(uVar3 + 0x1f53));
    }
    Mem_CpuFill8((uint *)(uintptr_t)(uVar3 + 0x21c),0,0x910);
    iVar4 = func_0x0219bb50();
    StructTK_SomeFn_from_thumb
              (iVar4 * 0x244 +
               (*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
               *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x228);
    func_02123a48(0);
    *(undefined4 *)
     ((*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
      *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x18e8) = 3;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02120a60 & 0xfffffffc) >> (uRam02120a60 & 3) * 8 |
    *(uint *)(uRam02120a60 & 0xfffffffc) << (uRam02120a60 & 3) * -8 + 0x20) + 0x18e8) = 2;
  return;
}

