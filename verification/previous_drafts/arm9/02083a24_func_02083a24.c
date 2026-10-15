/* Decompiled C draft; module arm9; ROM address 02083a24. No matching claim. */
#include "types.h"
#include "deps/02083a24_func_02083a24.h"

undefined4 func_02083a24(int param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = uRam02083adc;
  uVar3 = uRam02083ad8;
  uVar2 = uRam02083ad4;
  iVar7 = (uint)*(ushort *)(param_3 + 0x74) * 0x58 +
          (*(uint *)(uRam02083ad4 & 0xfffffffc) >> (uRam02083ad4 & 3) * 8 |
          *(uint *)(uRam02083ad4 & 0xfffffffc) << (uRam02083ad4 & 3) * -8 + 0x20);
  uVar6 = iVar7 + 0x20;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0) &&
     (uVar6 = iVar7 + 0x24, uVar1 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0)) {
    uVar6 = 0;
    do {
      uVar1 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      iVar7 = func_0208b7bc(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,uVar3);
      uVar1 = uVar2 & 3;
      uVar5 = *(uint *)(uVar2 & 0xfffffffc);
      *(int *)((uint)*(ushort *)(param_3 + 0x74) * 0x58 +
               (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + uVar6 * 4 + 0x20) = iVar7;
      *(int *)(iVar7 + 0x94) = param_3;
      *(char *)(iVar7 + 0x9b) = (char)uVar6;
      *(undefined1 *)(iVar7 + 0x98) = param_2;
      uVar6 = uVar6 + 1 & 0xffff;
      *(undefined4 *)(iVar7 + 0x90) = uVar4;
    } while (uVar6 < 2);
    return 1;
  }
  return 0;
}

