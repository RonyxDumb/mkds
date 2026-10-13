/* Decompiled C draft; module arm9; ROM address 020beb9c. No matching claim. */
#include "types.h"
#include "deps/020beb9c_func_020beb9c.h"

void func_020beb9c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined2 *)Mem_AllocateHeap(uVar3,0x25c);
  puVar1 = puRam020bfb3c;
  *puRam020bfb3c = puVar4;
  *puVar4 = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 8) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xc) = 0;
  iVar5 = AnotherAlloc_1();
  uVar8 = uRam020bfb44;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020ca3e4();
  uVar8 = uRam020bfb54;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cf310();
  uVar8 = uRam020bfb58;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7464();
  uVar8 = uRam020bfb5c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7690();
  uVar8 = uRam020bfb60;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c77a0();
  uVar8 = uRam020bfb64;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c79d4();
  uVar8 = uRam020bfb68;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_2();
  uVar8 = uRam020bfb6c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7b0c();
  uVar8 = uRam020bfb70;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7c1c();
  uVar8 = uRam020bfb74;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7d54();
  uVar8 = uRam020bfb78;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c7f84();
  uVar8 = uRam020bfb7c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020c8254();
  uVar8 = uRam020bfb80;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = AnotherAlloc_0();
  uVar8 = uRam020bfb84;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_3();
  uVar8 = uRam020bfb88;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_4();
  uVar8 = uRam020bfb8c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020ccf6c();
  uVar8 = uRam020bfb90;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cd2f0();
  uVar8 = uRam020bfb94;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_9();
  uVar8 = uRam020bfb98;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cdc90();
  uVar8 = uRam020bfb9c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cdb54();
  uVar8 = uRam020bfba0;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cd844();
  uVar8 = uRam020bfba4;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cd598();
  uVar8 = uRam020bfba8;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_5();
  uVar8 = uRam020bfbac;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_10();
  uVar8 = uRam020bfbb0;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_7();
  uVar8 = uRam020bfbb4;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cd9dc();
  uVar8 = uRam020bfbb8;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_8();
  uVar8 = uRam020bfbbc;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cdf18();
  uVar8 = uRam020c0678;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020d0e3c();
  uVar8 = uRam020c067c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_6();
  uVar8 = uRam020c0680;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cd6f4();
  uVar8 = uRam020c0684;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020ce548();
  uVar8 = uRam020c0688;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020cee0c();
  uVar8 = uRam020c068c;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = func_020d0280();
  uVar8 = uRam020c0690;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  iVar5 = Maybe_get_0c0c2c_11();
  uVar8 = uRam020c0694;
  iVar2 = iRam020bfb40;
  if (iVar5 != 0) {
    uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
            *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
    uVar6 = uVar9 + 0xc;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    *(uint *)(uVar9 + 0xc) = uVar6 + 1;
    puVar1 = puRam020bfb3c;
    for (iVar5 = 0;
        (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
        (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
        iVar5 = iVar5 + 1) {
    }
    if (iVar5 < 0x31) {
      uVar8 = iRam020bfb48 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20
                ) + uVar6 * 4 + 0x10) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb4c + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar8 = iRam020bfb50 + iVar5 * 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar6 * 4
               + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
  }
  uVar8 = (*(uint *)(uRam020c0698 & 0xfffffffc) >> (uRam020c0698 & 3) * 8 |
          *(uint *)(uRam020c0698 & 0xfffffffc) << (uRam020c0698 & 3) * -8 + 0x20) + 8;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if ((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) == 4) {
    iVar5 = func_0x02181510();
    uVar8 = uRam020c069c;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189584();
    uVar8 = uRam020c06a0;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x021896e0();
    uVar8 = uRam020c06a4;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189848();
    uVar8 = uRam020c06a8;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189290();
    uVar8 = uRam020c06ac;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189bd8();
    uVar8 = uRam020c06b0;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x021899b0();
    uVar8 = uRam020c06b4;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189d88();
    uVar8 = uRam020c06b8;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189410();
    uVar8 = uRam020c06bc;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
    }
    iVar5 = func_0x02189128();
    uVar8 = uRam020c06c0;
    iVar2 = iRam020bfb40;
    if (iVar5 != 0) {
      uVar9 = *(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
              *(uint *)((uint)puRam020bfb3c & 0xfffffffc) << ((uint)puRam020bfb3c & 3) * -8 + 0x20;
      uVar6 = uVar9 + 0xc;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      *(uint *)(uVar9 + 0xc) = uVar6 + 1;
      puVar1 = puRam020bfb3c;
      for (iVar5 = 0;
          (uVar7 = iVar2 + iVar5 * 0x10, uVar9 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
          (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) != uVar8 && (iVar5 < 0x31));
          iVar5 = iVar5 + 1) {
      }
      if (iVar5 < 0x31) {
        uVar8 = iRam020bfb48 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puRam020bfb3c & 0xfffffffc) >> ((uint)puRam020bfb3c & 3) * 8 |
                  *(uint *)((uint)puRam020bfb3c & 0xfffffffc) <<
                  ((uint)puRam020bfb3c & 3) * -8 + 0x20) + uVar6 * 4 + 0x10) =
             uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb4c + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0xd4) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar8 = iRam020bfb50 + iVar5 * 0x10;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        *(uint *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
                  uVar6 * 4 + 0x198) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        return;
      }
      return;
    }
    return;
  }
  return;
}

