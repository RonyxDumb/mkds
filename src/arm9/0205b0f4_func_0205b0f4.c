/* Decompiled C draft; module arm9; ROM address 0205b0f4. No matching claim. */
#include "types.h"
#include "deps/0205b0f4_func_0205b0f4.h"

void func_0205b0f4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = uRam0205b318;
  uVar9 = 0;
  do {
    uVar7 = 1 << uVar9;
    if ((((*(byte *)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                     *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x749) & uVar7) !=
          0) && (uVar2 = func_0x0219bb50(), uVar9 != uVar2)) &&
       (uVar2 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20,
       (*(byte *)(uVar2 + 0x748) & uVar7) == 0)) {
      uVar6 = 300;
      iVar3 = uVar2 + uVar9 * 2;
      if (*(char *)(uVar9 * 0x38 + uVar2 + 0x48) == '\0') {
        uVar6 = 600;
      }
      *(short *)(iVar3 + 0x740) = *(short *)(iVar3 + 0x740) + 1;
      uVar2 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
      if (uVar6 < *(ushort *)(uVar2 + uVar9 * 2 + 0x740)) {
        *(byte *)(uVar2 + 0x748) = *(byte *)(uVar2 + 0x748) | (byte)uVar7;
      }
    }
    uVar7 = uRam0205b318;
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 4);
  uVar9 = 0;
  uVar8 = (uint)*(byte *)((*(uint *)(uRam0205b318 & 0xfffffffc) >> (uRam0205b318 & 3) * 8 |
                          *(uint *)(uRam0205b318 & 0xfffffffc) << (uRam0205b318 & 3) * -8 + 0x20) +
                         0x748);
  do {
    if (((((uint)*(byte *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                           *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x749) &
          1 << uVar9) != 0) && (uVar2 = func_0x0219bb50(), uVar9 != uVar2)) &&
       (uVar2 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20,
       ((uint)*(byte *)(uVar2 + 0x748) & 1 << uVar9) == 0)) {
      uVar8 = uVar8 & ((uint)*(byte *)(uVar2 + uVar9 + 0x74a) | 1 << uVar9 & 0xffU);
    }
    uVar1 = uRam0205b31c;
    uVar2 = uRam0205b318;
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 4);
  if (uVar8 != 0) {
    uVar9 = 0;
    do {
      uVar7 = 1 << uVar9;
      if ((((uVar8 & uVar7) != 0) &&
          ((*(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x749) & uVar7) !=
           0)) && (uVar5 = uVar1 & 3, uVar4 = *(uint *)(uVar1 & 0xfffffffc),
                  uVar5 = (uint)*(char *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + uVar9
                                         + 6), uVar5 != 0xffffffff)) {
        func_0203c2e4(uVar5 & 0xffff);
        uVar5 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        *(byte *)(uVar5 + 0x749) = *(byte *)(uVar5 + 0x749) & ~(byte)uVar7;
      }
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 4);
    uVar8 = Math_CountPopulation
                      (*(undefined1 *)
                        ((*(uint *)(uRam0205b318 & 0xfffffffc) >> (uRam0205b318 & 3) * 8 |
                         *(uint *)(uRam0205b318 & 0xfffffffc) << (uRam0205b318 & 3) * -8 + 0x20) +
                        0x749));
    if (uVar8 < 2) {
      uVar2 = *(uint *)(uRam0205b320 & 0xfffffffc) >> (uRam0205b320 & 3) * 8 |
              *(uint *)(uRam0205b320 & 0xfffffffc) << (uRam0205b320 & 3) * -8 + 0x20;
      uVar9 = *(uint *)(uRam0205b324 & 0xfffffffc) >> (uRam0205b324 & 3) * 8 |
              *(uint *)(uRam0205b324 & 0xfffffffc) << (uRam0205b324 & 3) * -8 + 0x20;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar7 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      uVar8 = uVar7 + 0x48;
      uVar9 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      if (*(short *)(uVar2 + 0x16) != 0) {
        uVar9 = (int)((*(byte *)(uVar2 + 0x1f54) - 1) * 0x1000000) >> 0x18;
        if (0 < (int)uVar9) {
          if (uVar8 < uVar9) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 - uVar9;
          }
        }
        *(uint *)(uVar7 + 0x48) = uVar8;
        WriteSaveDataSectionHeaderToSaveData_from_thumb();
        WaitForWorkerTask();
        uVar8 = (*(uint *)(uRam0205b328 & 0xfffffffc) >> (uRam0205b328 & 3) * 8 |
                *(uint *)(uRam0205b328 & 0xfffffffc) << (uRam0205b328 & 3) * -8 + 0x20) + 0xc;
        uVar9 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        if (uVar8 >> uVar9 * 8 != 0 || uVar8 << uVar9 * -8 + 0x20 != 0) {
          func_02145d38();
        }
      }
      func_021208e8(2);
      return;
    }
    return;
  }
  return;
}

