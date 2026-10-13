/* Decompiled C draft; module arm9; ROM address 0206390c. No matching claim. */
#include "types.h"
#include "deps/0206390c_StructMLFnPtr.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void StructMLFnPtr(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_c4 [24];
  uint uStack_ac;
  int iStack_a8;
  int iStack_a4;
  undefined1 auStack_a0 [36];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [52];
  
  uVar2 = func_0207a31c();
  uVar7 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar6 = Dict_SomeFn_0((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x40,uRam02063a64);
  uVar7 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x10) == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = (uint)*(byte *)(param_1 + 0xae);
  }
  if (uVar6 == uVar7) {
    uVar3 = func_0206182c();
    func_02012f58(auStack_a0,auStack_c4);
    func_0214755c(uVar3,auStack_58);
    MTX_Concat43(auStack_a0,auStack_58,auStack_a0);
    MTX_Concat33(auStack_c4,auStack_58,auStack_c4);
    uStack_70 = uStack_7c;
    uStack_6c = uStack_78;
    uStack_68 = uStack_74;
    uStack_64 = uStack_ac;
    uStack_60 = iStack_a8;
    uStack_5c = iStack_a4;
    iVar4 = GetDriverEntry(uVar2);
    uVar7 = iVar4 + 0x4c8U & 3;
    uVar6 = *(uint *)(iVar4 + 0x4c8U & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    lVar1 = (ulonglong)uVar7 * 0xffff3000;
    uVar6 = (uint)lVar1;
    iVar4 = (int)(uVar6 + 0x800 >> 0xc |
                 (((int)((ulonglong)lVar1 >> 0x20) - uVar7) + (uint)(0xfffff7ff < uVar6)) * 0x100000
                 ) >> 4;
    uStack_64 = (uint)((longlong)(int)uStack_64 * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_64 * (longlong)iVar4) >> 0x20) << 0x14;
    uStack_60 = (uint)((longlong)(int)uStack_60 * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_60 * (longlong)iVar4) >> 0x20) << 0x14;
    uStack_5c = (uint)((longlong)(int)uStack_5c * (longlong)iVar4) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_5c * (longlong)iVar4) >> 0x20) << 0x14;
    VecFx32_Add(&uStack_70,&uStack_64,&uStack_70);
    func_02081618(uVar2,&uStack_70);
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x92) = 0;
    return;
  }
  return;
}

