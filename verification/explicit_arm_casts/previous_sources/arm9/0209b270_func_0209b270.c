/* Decompiled C draft; module arm9; ROM address 0209b270. No matching claim. */
#include "types.h"
#include "deps/0209b270_func_0209b270.h"

undefined1 func_0209b270(undefined4 param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  undefined1 auStack_20 [16];
  uint uVar5;
  uint uVar7;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    if (param_2 == 0) {
      iVar3 = GetDriverEntry((short)*(char *)((*(uint *)(uRam0209b340 & 0xfffffffc) >>
                                               (uRam0209b340 & 3) * 8 |
                                              *(uint *)(uRam0209b340 & 0xfffffffc) <<
                                              (uRam0209b340 & 3) * -8 + 0x20) + 0x62));
      func_0209b388(param_1,iVar3 + 0x80,iVar3 + 0x68,iVar3 + 0xa4);
    }
    else {
      uVar7 = param_2 + 0x60U & 3;
      uVar4 = *(uint *)(param_2 + 0x60U & 0xfffffffc);
      uVar5 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 0x5cU & 3;
      uVar4 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
      uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 100U & 3;
      uVar6 = *(uint *)(param_2 + 100U & 0xfffffffc);
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
      lVar2 = (longlong)(int)uVar7 * (longlong)(int)uVar7 +
              (longlong)(int)uVar4 * (longlong)(int)uVar4 +
              (longlong)(int)uVar5 * (longlong)(int)uVar5;
      if ((int)((ulonglong)lVar2 >> 0x20) < (int)(uint)((uint)lVar2 < 0x10)) {
        func_0209b388(param_1,0,0,0);
      }
      else {
        Vector3_MaybeNormalize(param_2 + 0x5c,auStack_20);
        func_0209b388(param_1,param_2 + 0x50,auStack_20,0);
      }
      func_020f8ddc(param_2);
    }
  }
  return uVar1;
}

