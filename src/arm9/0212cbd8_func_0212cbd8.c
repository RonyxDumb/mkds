/* Decompiled C draft; module arm9; ROM address 0212cbd8. No matching claim. */
#include "types.h"
#include "deps/0212cbd8_func_0212cbd8.h"

void func_0212cbd8(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  bool bVar8;
  uint uVar6;
  
  puVar1 = puRam0212cccc;
  if (*(uint *)((uint)puRam0212cccc & 0xfffffffc) >> ((uint)puRam0212cccc & 3) * 8 != 0 ||
      *(uint *)((uint)puRam0212cccc & 0xfffffffc) << ((uint)puRam0212cccc & 3) * -8 + 0x20 != 0) {
    uVar6 = (uint)(puRam0212cccc + 0xb) & 3;
    uVar5 = *(uint *)((uint)(puRam0212cccc + 0xb) & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    bVar8 = -1 < (int)uVar6;
    if (bVar8) {
      param_3 = 1 << (uVar6 & 0xff);
    }
    uVar6 = (uint)(puRam0212cccc + 9) & 3;
    uVar2 = *(uint *)((uint)(puRam0212cccc + 9) & 0xfffffffc);
    uVar5 = (uint)(puRam0212cccc + 10) & 3;
    uVar7 = *(uint *)((uint)(puRam0212cccc + 10) & 0xfffffffc);
    if (!bVar8) {
      param_3 = 0;
    }
    SND_StopTimer(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,
                  uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,param_3,0);
    if (bVar8) {
      uVar3 = func_02021114();
      Sound_FlushCommand(1);
      func_02021154(uVar3);
      uVar3 = uRam0212ccd0;
      do {
        iVar4 = Os_ReceiveMessage(uVar3,0,0);
      } while (iVar4 != 0);
    }
    uVar6 = (uint)(puVar1 + 10) & 3;
    uVar5 = *(uint *)((uint)(puVar1 + 10) & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
      func_0212bbe0();
    }
    uVar6 = (uint)(puVar1 + 8) & 3;
    uVar5 = *(uint *)((uint)(puVar1 + 8) & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
      func_0212bc20();
    }
    if (bVar8) {
      uVar6 = (uint)(puVar1 + 0xb) & 3;
      uVar5 = *(uint *)((uint)(puVar1 + 0xb) & 0xfffffffc);
      func_0212bb7c(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    }
    uVar6 = (uint)(puVar1 + 1) & 3;
    uVar5 = *(uint *)((uint)(puVar1 + 1) & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 1) {
      func_02020930(0,0,0,0);
    }
    *puVar1 = 0;
    return;
  }
  return;
}

