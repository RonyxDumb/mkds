/* Decompiled C draft; module arm9; ROM address 020527c0. No matching claim. */
#include "types.h"
#include "deps/020527c0_func_020527c0.h"

void func_020527c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar7;
  
  uVar2 = uRam020529b0;
  puVar9 = (undefined4 *)
           (*(uint *)(uRam020529b0 & 0xfffffffc) >> (uRam020529b0 & 3) * 8 |
           *(uint *)(uRam020529b0 & 0xfffffffc) << (uRam020529b0 & 3) * -8 + 0x20);
  uVar7 = (uint)*(byte *)((int)puVar9 + 0x439);
  uVar6 = (ushort)*(byte *)((int)puVar9 + 0x439);
  uVar4 = (uint)(puVar9 + 7) & 3;
  uVar8 = *(uint *)((uint)(puVar9 + 7) & 0xfffffffc);
  uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  *puVar9 = 2;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xc) = 7;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar2 = func_02143280();
  uVar4 = uRam020529b0;
  if (uVar2 == 0) {
    *(undefined4 *)
     ((*(uint *)(uRam020529b0 & 0xfffffffc) >> (uRam020529b0 & 3) * 8 |
      *(uint *)(uRam020529b0 & 0xfffffffc) << (uRam020529b0 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8) = 3;
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if (uVar2 != 0x8000) {
    if (*(char *)(puVar9 + 0x10e) == '\0') {
      while ((1 << (uVar7 - 1 & 0xff) & uVar2) == 0) {
        uVar7 = uVar7 + 1 & 0xffff;
        if (0xe < uVar7) {
          uVar7 = 1;
        }
        uVar6 = (ushort)uVar7;
      }
      *(ushort *)(uVar8 + 4) = uVar6;
      *(char *)((int)puVar9 + 0x439) = (char)uVar6;
      iVar5 = 0;
      do {
        iVar3 = uVar8 + iVar5;
        iVar5 = iVar5 + 1;
        *(undefined1 *)(iVar3 + 8) = 0xff;
      } while (iVar5 < 6);
    }
    else {
      *(undefined1 *)(uVar8 + 8) = *(undefined1 *)(puVar9 + 0x10b);
      *(undefined1 *)(uVar8 + 9) = *(undefined1 *)((int)puVar9 + 0x42d);
      *(undefined1 *)(uVar8 + 10) = *(undefined1 *)((int)puVar9 + 0x42e);
      *(undefined1 *)(uVar8 + 0xb) = *(undefined1 *)((int)puVar9 + 0x42f);
      *(undefined1 *)(uVar8 + 0xc) = *(undefined1 *)(puVar9 + 0x10c);
      *(undefined1 *)(uVar8 + 0xd) = *(undefined1 *)((int)puVar9 + 0x431);
      *(char *)(puVar9 + 0x10e) = *(char *)(puVar9 + 0x10e) + -1;
    }
    uVar1 = func_02143090();
    *(undefined2 *)(uVar8 + 6) = uVar1;
    iVar5 = func_02143a78(uRam020529b4,uVar8);
    uVar7 = uRam020529b0;
    if (iVar5 == 2) {
      uVar4 = *(uint *)(uRam020529b0 & 0xfffffffc) >> (uRam020529b0 & 3) * 8 |
              *(uint *)(uRam020529b0 & 0xfffffffc) << (uRam020529b0 & 3) * -8 + 0x20;
      *(ushort *)(uVar4 + 0x436) = *(ushort *)(uVar4 + 0x436) | 1;
      *(undefined4 *)
       ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
        *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x440) = param_2;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      *(undefined4 *)(uVar7 + 0x444) = param_3;
      if (param_1 != 0) {
        uVar7 = 1;
      }
      if (param_1 != 0) {
        *(char *)((int)puVar9 + 0x43b) = (char)uVar7;
      }
      else {
        *(undefined1 *)((int)puVar9 + 0x43b) = 0;
      }
      return;
    }
    uVar7 = *(uint *)(uRam020529b0 & 0xfffffffc) >> (uRam020529b0 & 3) * 8 |
            *(uint *)(uRam020529b0 & 0xfffffffc) << (uRam020529b0 & 3) * -8 + 0x20;
    *(ushort *)(uVar7 + 0x436) = *(ushort *)(uVar7 + 0x436) & 0xfffe;
    func_020533a0();
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020529b0 & 0xfffffffc) >> (uRam020529b0 & 3) * 8 |
    *(uint *)(uRam020529b0 & 0xfffffffc) << (uRam020529b0 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8) = 8;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 0;
  return;
}

