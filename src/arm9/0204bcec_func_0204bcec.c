/* Decompiled C draft; module arm9; ROM address 0204bcec. No matching claim. */
#include "types.h"
#include "deps/0204bcec_func_0204bcec.h"

void func_0204bcec(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = uRam0204be04;
  uVar1 = Os_DisableIrq();
  if (*(uint *)((uint)puRam0204be08 & 0xfffffffc) >> ((uint)puRam0204be08 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam0204be08 & 0xfffffffc) << ((uint)puRam0204be08 & 3) * -8 + 0x20 != 0) {
    uVar8 = uVar6 + 0x20 & 3;
    uVar7 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (uVar8 != 0) {
      if (uVar8 != 0) {
        uVar2 = Os_DisableIrq();
        uVar7 = uVar6 + 0x18 & 3;
        uVar3 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
        uVar4 = uVar6 + 0x14 & 3;
        uVar5 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
        (*(code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))
                  (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,0,uVar8);
        Os_RestoreIrq(uVar2);
      }
      *(undefined4 *)(uVar6 + 0x20) = 0;
      *(undefined4 *)(uVar6 + 0x24) = 0;
    }
    uVar7 = uRam0204be04;
    *(undefined4 *)(uVar6 + 0xc) = 0;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) {
      uVar8 = uVar6 + 0x1c & 3;
      uVar7 = *(uint *)(uVar6 + 0x1c & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if (uVar8 != 0) {
        uVar8 = uVar8 + 8;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(undefined4 *)(uVar6 + 0x1c) = 0;
        Fs_Archive_NotifyAsyncEnded(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,5);
      }
      uVar8 = uVar6 + 0xf3c & 3;
      uVar6 = *(uint *)(uVar6 + 0xf3c & 0xfffffffc);
      uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      if (uVar6 != 0) {
        uVar2 = Os_DisableIrq();
        uVar8 = uRam0204be04 + 0x18 & 3;
        uVar4 = *(uint *)(uRam0204be04 + 0x18 & 0xfffffffc);
        uVar7 = uRam0204be04 + 0x14 & 3;
        uVar3 = *(uint *)(uRam0204be04 + 0x14 & 0xfffffffc);
        (*(code *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20))
                  (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20,0,uVar6);
        Os_RestoreIrq(uVar2);
      }
    }
    else {
      func_0204ba8c();
    }
    func_02006974();
    func_0214358c(*(undefined2 *)(uRam0204be04 + 0x30),0,0);
    *puRam0204be08 = 0;
  }
  Os_RestoreIrq(uVar1);
  return;
}

