/* Decompiled C draft; module arm9; ROM address 0211fb44. No matching claim. */
#include "types.h"
#include "deps/0211fb44_GlobalB_E7Fn_1AImpl.h"

void GlobalB_E7Fn_1AImpl(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
               *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
               iRam0211fd00),0,0x10);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
               *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
               iRam0211fd04),0,0x350);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
               *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
               iRam0211fd08),0,uRam0211fd0c);
  iVar2 = func_02061290();
  if (iVar2 == 0) {
    func_02152690((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
                  *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
                  iRam0211fd04,uRam0211fd14);
  }
  else {
    uVar5 = *(uint *)(uRam0211fd10 & 0xfffffffc) >> (uRam0211fd10 & 3) * 8 |
            *(uint *)(uRam0211fd10 & 0xfffffffc) << (uRam0211fd10 & 3) * -8 + 0x20;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x4c),
                 (uint *)(uintptr_t)((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
                 *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
                 iRam0211fd04),0x40);
  }
  GlobalZ_CopyNKFLOther1
            ((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
             *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) + iRam0211fd18)
  ;
  func_0x021a39c4((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
                  *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
                  iRam0211fd00);
  func_0x021a397c(2);
  func_0x021a3910();
  uVar5 = 0;
  iVar3 = func_0x0219d9b0((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
                          *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) +
                          iRam0211fd18,0x3c);
  iVar2 = iRam0211fd18;
  uVar6 = uRam0211fcfc;
  if (0 < iVar3) {
    do {
      uVar1 = uVar6 & 3;
      uVar4 = *(uint *)(uVar6 & 0xfffffffc);
      uVar5 = uVar5 + 1 & 0xff;
      iVar3 = func_0x0219d9b0((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + iVar2,0x3c);
    } while ((int)uVar5 < iVar3);
  }
  uVar6 = *(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
          *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20;
  func_0x0219c1e4(uVar6 + iRam0211fd08,uVar6 + iRam0211fd04,uRam0211fd20,uRam0211fd24,uRam0211fd1c,0
                  ,0,uVar6 + iRam0211fd18,0x3c);
  uVar6 = uRam0211fcfc;
  *(undefined4 *)
   ((*(uint *)(uRam0211fcfc & 0xfffffffc) >> (uRam0211fcfc & 3) * 8 |
    *(uint *)(uRam0211fcfc & 0xfffffffc) << (uRam0211fcfc & 3) * -8 + 0x20) + 0x1f44) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1f48) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1f2c) = 1;
  return;
}

