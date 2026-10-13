/* Decompiled C draft; module arm9; ROM address 0205c470. No matching claim. */
#include "types.h"
#include "deps/0205c470_E7FnList4_Fn8.h"

void E7FnList4_Fn8(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = uRam0205c58c;
  uVar2 = *(uint *)(uRam0205c58c & 0xfffffffc) >> (uRam0205c58c & 3) * 8 |
          *(uint *)(uRam0205c58c & 0xfffffffc) << (uRam0205c58c & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) | 2;
  uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) & 0xffdf;
  uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) & 0xfdff;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x728) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x73a) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x73d) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x73b) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x73e) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x72c) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x738) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x758) = 2;
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x754;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),0,0x6c);
  uVar2 = uRam0205c590;
  uVar3 = uRam0205c58c;
  uVar7 = 0;
  do {
    uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    if (((((uint)*(byte *)(uVar6 + 0xfc) & 1 << uVar7) != 0) &&
        (((uint)*(byte *)(uVar6 + 0x749) & 1 << uVar7) == 0)) &&
       (uVar6 = uVar2 & 3, uVar4 = *(uint *)(uVar2 & 0xfffffffc),
       cVar1 = *(char *)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + uVar7 + 6), -1 < cVar1)
       ) {
      iVar5 = func_0205d27c(cVar1);
      *(uint *)(uVar7 * 0x88 +
                (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x184) =
           iVar5 - 1U | 0x700000;
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 4);
  return;
}

