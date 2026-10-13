/* Decompiled C draft; module arm9; ROM address 0211f864. No matching claim. */
#include "types.h"
#include "deps/0211f864_func_0211f864.h"

void func_0211f864(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    iVar2 = PlayerProfileInfo_NeedsSaving_from_thumb
                      ((*(uint *)(uRam0211f910 & 0xfffffffc) >> (uRam0211f910 & 3) * 8 |
                       *(uint *)(uRam0211f910 & 0xfffffffc) << (uRam0211f910 & 3) * -8 + 0x20) +
                       iRam0211f914);
    if (iVar2 != 0) {
      PlayerProfileInfo_PrepareForSave_from_thumb
                ((*(uint *)(uRam0211f910 & 0xfffffffc) >> (uRam0211f910 & 3) * 8 |
                 *(uint *)(uRam0211f910 & 0xfffffffc) << (uRam0211f910 & 3) * -8 + 0x20) +
                 iRam0211f914);
      uVar3 = *(uint *)(uRam0211f918 & 0xfffffffc) >> (uRam0211f918 & 3) * 8 |
              *(uint *)(uRam0211f918 & 0xfffffffc) << (uRam0211f918 & 3) * -8 + 0x20;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      Mem_CpuCopy8((ushort *)(uintptr_t)((*(uint *)(uRam0211f910 & 0xfffffffc) >> (uRam0211f910 & 3) * 8 |
                   *(uint *)(uRam0211f910 & 0xfffffffc) << (uRam0211f910 & 3) * -8 + 0x20) +
                   iRam0211f914),(uint *)(uintptr_t)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x4c),0x40);
      WriteSaveDataSectionHeaderToSaveData_from_thumb();
    }
    *(undefined4 *)
     ((*(uint *)(uRam0211f910 & 0xfffffffc) >> (uRam0211f910 & 3) * 8 |
      *(uint *)(uRam0211f910 & 0xfffffffc) << (uRam0211f910 & 3) * -8 + 0x20) + 0x1f2c) = 3;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam0211f910 & 0xfffffffc) >> (uRam0211f910 & 3) * 8 |
    *(uint *)(uRam0211f910 & 0xfffffffc) << (uRam0211f910 & 3) * -8 + 0x20) + 0x1f2c) = 6;
  return;
}

