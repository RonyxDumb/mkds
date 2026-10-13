/* Decompiled C draft; module arm9; ROM address 0205c898. No matching claim. */
#include "types.h"
#include "deps/0205c898_E7FnList4_Fn4.h"

void E7FnList4_Fn4(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longlong lVar11;
  
  uVar3 = func_0x0219bb50();
  iVar10 = 0;
  *(char *)((*(uint *)(uRam0205c984 & 0xfffffffc) >> (uRam0205c984 & 3) * 8 |
            *(uint *)(uRam0205c984 & 0xfffffffc) << (uRam0205c984 & 3) * -8 + 0x20) + 0xfa) =
       (char)(1 << (uVar3 & 0xff));
  iVar9 = 0;
  iVar8 = 0;
  *(undefined2 *)
   ((*(uint *)(uRam0205c984 & 0xfffffffc) >> (uRam0205c984 & 3) * 8 |
    *(uint *)(uRam0205c984 & 0xfffffffc) << (uRam0205c984 & 3) * -8 + 0x20) + 0x736) = 0x7f;
  *(undefined2 *)
   ((*(uint *)(uRam0205c984 & 0xfffffffc) >> (uRam0205c984 & 3) * 8 |
    *(uint *)(uRam0205c984 & 0xfffffffc) << (uRam0205c984 & 3) * -8 + 0x20) + 0xf8) = 0;
  do {
    uVar7 = *(uint *)(uRam0205c984 & 0xfffffffc) >> (uRam0205c984 & 3) * 8 |
            *(uint *)(uRam0205c984 & 0xfffffffc) << (uRam0205c984 & 3) * -8 + 0x20;
    iVar5 = uVar7 + iVar9;
    uVar3 = iVar5 + 0x3cU & 3;
    uVar4 = *(uint *)(iVar5 + 0x3cU & 0xfffffffc);
    uVar1 = iVar5 + 0x40U & 3;
    uVar6 = *(uint *)(iVar5 + 0x40U & 0xfffffffc);
    if (*(char *)(iVar5 + 0x48) == '\0') {
      *(undefined2 *)(uVar7 + iVar8 + 0x188) = 0;
    }
    else {
      lVar11 = _ll_udiv(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                        uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,*(char *)(iVar5 + 0x48),0);
      lVar11 = _ll_udiv((int)(lVar11 << 6),(int)((ulonglong)(lVar11 << 6) >> 0x20),uRam0205c988,0);
      uVar2 = _ll_udiv((int)(lVar11 + 0x20),(int)((ulonglong)(lVar11 + 0x20) >> 0x20),0x21,0);
      *(undefined2 *)(uVar7 + iVar8 + 0x188) = uVar2;
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x38;
    iVar8 = iVar8 + 0x88;
  } while (iVar10 < 4);
  return;
}

