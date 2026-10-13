/* Decompiled C draft; module arm7; ROM address 037f802c. No matching claim. */
#include "types.h"
#include "deps/037f802c_FUN_037f802c.h"

uint FUN_037f802c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  iVar2 = FUN_037f81e8();
  if (iVar2 == 0) {
    iVar2 = FUN_037f81c4();
    uVar1 = DAT_037f81b4;
    if (iVar2 != 0) {
      return 3;
    }
    uVar6 = 0;
    do {
      uVar3 = thunk_FUN_038011f0(uVar1,param_1 + uVar6 * 0x100,0x70);
      iVar2 = param_1 + uVar6 * 0x100;
      if ((uVar3 == *(ushort *)(iVar2 + 0x72)) && (*(ushort *)(iVar2 + 0x70) < 0x80)) {
        uVar5 = uVar5 | 1 << (uVar6 & 0xff);
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 2);
  }
  else {
    uVar3 = FUN_037f81c4();
    uVar6 = 0;
    do {
      iVar2 = param_1 + uVar6 * 0x100;
      uVar4 = thunk_FUN_038011f0(DAT_037f81b4,iVar2,0x70);
      if (((uVar4 == *(ushort *)(iVar2 + 0x72)) && (*(ushort *)(iVar2 + 0x70) < 0x80)) &&
         (uVar4 = thunk_FUN_038011f0(DAT_037f81b4,iVar2 + 0x74,0x8a),
         uVar4 == *(ushort *)(iVar2 + 0xfe))) {
        if ((1 << (ushort)*(byte *)(iVar2 + 0x75) & (uint)*(ushort *)(iVar2 + 0x76)) != 0) {
          if ((uVar3 & *(ushort *)(iVar2 + 0x76)) != 0) {
            *(ushort *)(iVar2 + 100) =
                 *(ushort *)(iVar2 + 100) & 0xfff8 | *(byte *)(iVar2 + 0x75) & 7;
          }
          uVar5 = uVar5 | 1 << (uVar6 & 0xff);
        }
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 2);
  }
  if ((uVar5 != 1) && (uVar5 != 2)) {
    if (uVar5 == 3) {
      if ((*(short *)(param_1 + 0x70) + 1U & 0x7f) == *(ushort *)(param_1 + 0x170)) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}

