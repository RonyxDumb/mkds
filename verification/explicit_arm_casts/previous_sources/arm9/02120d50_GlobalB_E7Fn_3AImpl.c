/* Decompiled C draft; module arm9; ROM address 02120d50. No matching claim. */
#include "types.h"
#include "deps/02120d50_GlobalB_E7Fn_3AImpl.h"

void GlobalB_E7Fn_3AImpl(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  func_02120610();
  Mem_CpuFill8((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
               *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x21c,0,
               0x910);
  StructTK_SomeFn_from_thumb
            ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
             *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x228);
  puVar10 = DAT_021210b8;
  iVar5 = DAT_021210b4;
  uVar8 = DAT_021210b0;
  uVar3 = *(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20;
  iVar7 = 6;
  *(uint *)(uVar3 + 0x18ec) = *(byte *)(uVar3 + 0x450) & 0xf;
  uVar3 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
  *(int *)(uVar3 + 0x1934) = (int)*(short *)(uVar3 + 0x43e);
  puVar6 = (undefined1 *)
           ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar5);
  do {
    puVar9 = puVar10 + 1;
    uVar2 = *puVar10;
    puVar10 = puVar10 + 2;
    uVar1 = *puVar9;
    iVar7 = iVar7 + -1;
    puVar9 = puVar6 + 1;
    *puVar6 = uVar2;
    puVar6 = puVar6 + 2;
    *puVar9 = uVar1;
  } while (iVar7 != 0);
  uVar8 = *(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20;
  uVar2 = func_0x021a2ad0(*(undefined1 *)(uVar8 + 0x1930),uVar8 + DAT_021210b4,DAT_021210bc);
  puVar10 = DAT_021210c4;
  iVar5 = DAT_021210c0;
  uVar3 = DAT_021210b0;
  *(undefined1 *)
   ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
    *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x1930) = uVar2;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar7 = 5;
  puVar6 = (undefined1 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar5);
  do {
    puVar9 = puVar10 + 1;
    uVar2 = *puVar10;
    puVar10 = puVar10 + 2;
    uVar1 = *puVar9;
    iVar7 = iVar7 + -1;
    puVar9 = puVar6 + 1;
    *puVar6 = uVar2;
    puVar6 = puVar6 + 2;
    *puVar9 = uVar1;
  } while (iVar7 != 0);
  uVar8 = *(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20;
  uVar2 = func_0x021a2b9c(*(undefined1 *)(uVar8 + 0x1918),uVar8 + DAT_021210c0,uVar8 + DAT_021210c8)
  ;
  puVar10 = DAT_021210d0;
  iVar5 = DAT_021210cc;
  uVar3 = DAT_021210b0;
  *(undefined1 *)
   ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
    *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x1918) = uVar2;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar7 = 4;
  puVar6 = (undefined1 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar5);
  do {
    puVar9 = puVar10 + 1;
    uVar2 = *puVar10;
    puVar10 = puVar10 + 2;
    uVar1 = *puVar9;
    iVar7 = iVar7 + -1;
    puVar9 = puVar6 + 1;
    *puVar6 = uVar2;
    puVar6 = puVar6 + 2;
    *puVar9 = uVar1;
    iVar5 = DAT_021210cc;
    uVar8 = DAT_021210b0;
  } while (iVar7 != 0);
  *puVar6 = *puVar10;
  uVar3 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
  uVar2 = func_0x021a2b9c(*(undefined1 *)(uVar8 + 0x1948),uVar8 + iVar5,uVar8 + DAT_021210d4);
  puVar10 = DAT_021210dc;
  iVar5 = DAT_021210d8;
  uVar3 = DAT_021210b0;
  *(undefined1 *)
   ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
    *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x1948) = uVar2;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar7 = 6;
  puVar6 = (undefined1 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar5);
  do {
    puVar9 = puVar10 + 1;
    uVar2 = *puVar10;
    puVar10 = puVar10 + 2;
    uVar1 = *puVar9;
    iVar7 = iVar7 + -1;
    puVar9 = puVar6 + 1;
    *puVar6 = uVar2;
    puVar6 = puVar6 + 2;
    *puVar9 = uVar1;
  } while (iVar7 != 0);
  uVar8 = *(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20;
  uVar2 = func_0x021a2b9c(*(undefined1 *)(uVar8 + 0x1900),uVar8 + DAT_021210d8,uVar8 + DAT_021210e0)
  ;
  uVar3 = DAT_021210b0;
  *(undefined1 *)
   ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
    *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x1900) = uVar2;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar5 = (int)*(short *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0x43e);
  iVar7 = iVar5 + -1000;
  iVar5 = iVar5 + 1000;
  if (iVar7 < 1) {
    iVar7 = 0;
  }
  if (DAT_021210e4 < iVar5) {
    iVar5 = DAT_021210e4;
  }
  Mem_CpuFill8(DAT_021210e8,0,100);
  uVar8 = (*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x1904;
  uVar3 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if ((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) == 1) {
    SomeSnprintf(DAT_021210e8,DAT_021210f4,DAT_021210f8,DAT_021210fc,DAT_021210ec,iVar7,DAT_021210f0
                 ,iVar5);
  }
  else {
    SomeSnprintf(DAT_021210e8,DAT_02121100,DAT_02121104,DAT_02121108);
  }
  uVar3 = *(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
          *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20;
  uVar8 = uVar3 + 0x1904 & 3;
  uVar4 = *(uint *)(uVar3 + 0x1904 & 0xfffffffc);
  switch(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) {
  case 0:
    func_0x0219bc78(0,0,*(undefined1 *)(uVar3 + 0x194c),1,DAT_02121110,0,0,0);
    break;
  case 1:
    func_0x0219bd90(*(undefined1 *)(uVar3 + 0x194c),DAT_021210e8,DAT_02121110,0,DAT_02121118,0);
    break;
  case 2:
    break;
  case 3:
    func_0x0219bd90(*(undefined1 *)(uVar3 + 0x194c),DAT_021210e8,DAT_02121110,0,DAT_0212110c,0);
    break;
  case 4:
    func_0x0219bd90(*(undefined1 *)(uVar3 + 0x194c),DAT_021210e8,DAT_02121110,0,DAT_02121114,0);
  }
  *(undefined4 *)
   ((*(uint *)(DAT_021210b0 & 0xfffffffc) >> (DAT_021210b0 & 3) * 8 |
    *(uint *)(DAT_021210b0 & 0xfffffffc) << (DAT_021210b0 & 3) * -8 + 0x20) + 0x18e8) = 1;
  return;
}

