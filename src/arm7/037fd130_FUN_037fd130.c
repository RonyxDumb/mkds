/* Decompiled C draft; module arm7; ROM address 037fd130. No matching claim. */
#include "types.h"
#include "deps/037fd130_FUN_037fd130.h"

void FUN_037fd130(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = DAT_037fd318;
  iVar5 = 0;
  do {
    iVar6 = iVar5 * 0x54 + iVar4;
    uVar1 = ((uint)*(byte *)(iVar6 + 3) << 0x18) >> 0x1b;
    if (uVar1 != 0) {
      if ((uVar1 & 2) != 0) {
        FUN_037fbd0c(iVar5,0);
      }
      uVar1 = ((uint)*(byte *)(iVar6 + 3) << 0x18) >> 0x1b;
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 4) != 0) {
          FUN_037fbc70(iVar5,*(undefined2 *)(iVar6 + 0x26));
        }
        if ((((uint)*(byte *)(iVar6 + 3) << 0x18) >> 0x1b & 8) != 0) {
          FUN_037fbc88(iVar5,*(ushort *)(iVar6 + 0x24) & 0xff);
        }
        if ((((uint)*(byte *)(iVar6 + 3) << 0x18) >> 0x1b & 0x10) != 0) {
          FUN_037fbbf4(iVar5,*(undefined1 *)(iVar6 + 0x23));
        }
      }
      else {
        cVar2 = *(char *)(iVar6 + 1);
        if (cVar2 == '\0') {
          uVar1 = iVar6 + 0x44U & 3;
          uVar3 = *(uint *)(iVar6 + 0x44U & 0xfffffffc);
          FUN_037fbea0(iVar5,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
        }
        else if (cVar2 == '\x01') {
          uVar1 = iVar6 + 0x44U & 3;
          uVar3 = *(uint *)(iVar6 + 0x44U & 0xfffffffc);
          FUN_037fbde8(iVar5,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                       *(ushort *)(iVar6 + 0x24) & 0xff,(int)(uint)*(ushort *)(iVar6 + 0x24) >> 8,
                       *(undefined2 *)(iVar6 + 0x26),*(undefined1 *)(iVar6 + 0x23));
        }
        else if (cVar2 == '\x02') {
          FUN_037fbd38(iVar5,*(ushort *)(iVar6 + 0x24) & 0xff,
                       (int)(uint)*(ushort *)(iVar6 + 0x24) >> 8,*(undefined2 *)(iVar6 + 0x26),
                       *(undefined1 *)(iVar6 + 0x23));
        }
      }
    }
    iVar6 = DAT_037fd318;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  iVar4 = 0;
  do {
    iVar5 = iVar4 * 0x54 + iVar6;
    uVar1 = ((uint)*(byte *)(iVar5 + 3) << 0x18) >> 0x1b;
    if (uVar1 != 0) {
      if ((uVar1 & 1) != 0) {
        *(byte *)(iVar4 * 0x10 + 0x4000403) = *(byte *)(iVar4 * 0x10 + 0x4000403) | 0x80;
      }
      *(byte *)(iVar5 + 3) = *(byte *)(iVar5 + 3) & 7;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  return;
}

