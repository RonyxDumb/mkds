/* Decompiled C draft; module arm9; ROM address 0205ab78. No matching claim. */
#include "types.h"
#include "deps/0205ab78_func_0205ab78.h"

void func_0205ab78(void)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  uVar2 = uRam0205ac34;
  uVar6 = 0;
  do {
    uVar5 = uVar2 & 3;
    uVar4 = *(uint *)(uVar2 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    puVar3 = (undefined4 *)(uVar6 * 0xc + uVar5 + 0x324);
    if ((*(char *)((int)puVar3 + 9) != '\x0f') && (cVar1 = *(char *)(puVar3 + 2), cVar1 != '\0')) {
      if (cVar1 == '\x01') {
        uVar4 = uVar5 + 0x728 & 3;
        uVar5 = *(uint *)(uVar5 + 0x728 & 0xfffffffc);
        if ((*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) <
            (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) {
          *(undefined1 *)(puVar3 + 2) = 2;
        }
      }
      else if ((cVar1 == '\x02') &&
              (uVar4 = uVar5 + 0x728 & 3, uVar5 = *(uint *)(uVar5 + 0x728 & 0xfffffffc),
              (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) + 0x1e <
              (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
        *(undefined1 *)(puVar3 + 2) = 0;
        *puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 9) = 0xf;
        *(undefined1 *)((int)puVar3 + 10) = 0;
        *(undefined1 *)((int)puVar3 + 0xb) = 0;
        uVar5 = (uint)(puVar3 + 1) & 3;
        uVar4 = *(uint *)((uint)(puVar3 + 1) & 0xfffffffc);
        Mem_CpuFill8((uint *)(uintptr_t)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),0,0x14);
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 0x10);
  return;
}

