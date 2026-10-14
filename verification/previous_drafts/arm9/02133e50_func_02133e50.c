/* Decompiled C draft; module arm9; ROM address 02133e50. No matching claim. */
#include "types.h"
#include "deps/02133e50_func_02133e50.h"

void func_02133e50(void)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = Os_Mutex_TryLock(uRam02133f68);
  piVar1 = piRam02133f74;
  if (iVar2 == 0) {
    uVar6 = iRam02133f6c + 8U & 3;
    uVar5 = *(uint *)(iRam02133f6c + 8U & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x6c;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *puRam02133f70 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    *piVar1 = 1;
  }
  else {
    uVar6 = iRam02133f6c + 8U & 3;
    uVar5 = *(uint *)(iRam02133f6c + 8U & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x6c;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((*(uint *)((uint)puRam02133f70 & 0xfffffffc) >> ((uint)puRam02133f70 & 3) * 8 |
        *(uint *)((uint)puRam02133f70 & 0xfffffffc) << ((uint)puRam02133f70 & 3) * -8 + 0x20) ==
        (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) {
      *piRam02133f74 =
           (*(uint *)((uint)piRam02133f74 & 0xfffffffc) >> ((uint)piRam02133f74 & 3) * 8 |
           *(uint *)((uint)piRam02133f74 & 0xfffffffc) << ((uint)piRam02133f74 & 3) * -8 + 0x20) + 1
      ;
    }
    else {
      Os_Mutex_Lock(uRam02133f68);
      piVar1 = piRam02133f74;
      uVar6 = iRam02133f6c + 8U & 3;
      uVar5 = *(uint *)(iRam02133f6c + 8U & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x6c;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *puRam02133f70 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      *piVar1 = 1;
    }
  }
  iVar2 = iRam02133f7c;
  piVar1 = piRam02133f78;
  uVar6 = *(uint *)((uint)piRam02133f78 & 0xfffffffc) >> ((uint)piRam02133f78 & 3) * 8 |
          *(uint *)((uint)piRam02133f78 & 0xfffffffc) << ((uint)piRam02133f78 & 3) * -8 + 0x20;
  while (0 < (int)uVar6) {
    iVar4 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
            *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) - 1;
    uVar6 = iVar2 + iVar4 * 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *piVar1 = iVar4;
    (*(code *)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20))();
    uVar6 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
            *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  }
  iVar2 = (*(uint *)((uint)piRam02133f74 & 0xfffffffc) >> ((uint)piRam02133f74 & 3) * 8 |
          *(uint *)((uint)piRam02133f74 & 0xfffffffc) << ((uint)piRam02133f74 & 3) * -8 + 0x20) - 1;
  *piRam02133f74 = iVar2;
  if (iVar2 == 0) {
    Os_Mutex_Unlock(uRam02133f68);
  }
  pcVar3 = (code *)(*(uint *)((uint)puRam02133f80 & 0xfffffffc) >> ((uint)puRam02133f80 & 3) * 8 |
                   *(uint *)((uint)puRam02133f80 & 0xfffffffc) <<
                   ((uint)puRam02133f80 & 3) * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
    *puRam02133f80 = 0;
  }
  func_021349c4(0);
  func_02142590();
  return;
}

