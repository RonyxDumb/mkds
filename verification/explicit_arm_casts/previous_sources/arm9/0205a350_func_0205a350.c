/* Decompiled C draft; module arm9; ROM address 0205a350. No matching claim. */
#include "types.h"
#include "deps/0205a350_func_0205a350.h"

void func_0205a350(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = DAT_0205a4ac;
  uVar9 = 0;
  do {
    iVar4 = func_0205a50c(uVar9);
    if (iVar4 != 0) {
      uVar8 = uVar9 * 0x88 +
              (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x16c;
      puVar5 = (ushort *)func_0205a4e8(uVar9,uVar9);
      switch(*(undefined2 *)(uVar8 + 0xc)) {
      case 0:
        if (((uint)*puVar5 << 0x12) >> 0x1e == 2) {
          func_0205a71c(uVar9);
          func_0205a4b0(uVar8,((uint)*puVar5 << 0x14) >> 0x1b);
        }
        break;
      case 1:
        break;
      case 2:
        uVar1 = uVar8 + 8 & 3;
        uVar7 = *(uint *)(uVar8 + 8 & 0xfffffffc);
        uVar6 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x728;
        uVar2 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) -
                (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
        if (*(ushort *)(uVar8 + 0xe) < 100) {
          func_0205a7dc(uVar9,uVar6 & 0xffff,
                        *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20,2);
          *(short *)(uVar8 + 0xe) = *(short *)(uVar8 + 0xe) + 1;
        }
        else if ((int)uVar6 < 0x15) {
          func_0205a7ac(uVar9);
          if ((int)uVar6 < 1) {
            *(undefined2 *)(uVar8 + 0xc) = 3;
          }
        }
        else {
          func_0205a7dc(uVar9,uVar6 & 0xffff,
                        *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20,2);
        }
        break;
      case 3:
        func_0205a534(uVar8);
        break;
      case 4:
        if (((uint)*puVar5 << 0x12) >> 0x1e != 2) {
          *(undefined2 *)(uVar8 + 0xc) = 0;
        }
      }
    }
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 4);
  return;
}

