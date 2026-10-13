/* Decompiled C draft; module arm7; ROM address 06008b4c. No matching claim. */
#include "types.h"
#include "deps/06008b4c_FUN_06008b4c.h"

void FUN_06008b4c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_28 [8];
  
  uVar1 = DAT_06008c00;
  uVar8 = *(uint *)(DAT_06008c00 & 0xfffffffc) >> (DAT_06008c00 & 3) * 8 |
          *(uint *)(DAT_06008c00 & 0xfffffffc) << (DAT_06008c00 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar8 + 0x10) = 0;
  *(undefined2 *)(uVar8 + 0x14) = 0;
  uVar3 = DAT_06008c08;
  uVar2 = DAT_06008c04;
  do {
    while( true ) {
      uVar6 = uVar1 & 3;
      uVar5 = *(uint *)(uVar1 & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x308;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar7 = thunk_FUN_037f97b4(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,auStack_28,0);
      if (iVar7 != 0) {
        FUN_06008980((uint)(uintptr_t)(auStack_28));
      }
      thunk_FUN_037f8850(uVar2);
      *(undefined2 *)(uVar8 + 0x12) = *(undefined2 *)(uVar8 + 0x10);
      if (*(ushort *)(uVar8 + (uint)*(ushort *)(uVar8 + 0x12) * 2) != uVar3) break;
      *(short *)(uVar8 + 0x10) = *(short *)(uVar8 + 0x10) + 1;
      thunk_FUN_037f888c();
    }
    thunk_FUN_037f888c();
    uVar4 = FUN_06008a04(*(undefined2 *)(uVar8 + 0x12));
    *(undefined2 *)(uVar8 + 0x14) = uVar4;
    uVar6 = uVar8 + (uint)*(ushort *)(uVar8 + 0x14) * 8 + 0xc0;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    (*(code *)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20))();
    *(short *)(uVar8 + 0x14) = (short)uVar3;
  } while( true );
}

