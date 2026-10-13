/* Decompiled C draft; module arm9; ROM address 020e52bc. No matching claim. */
#include "types.h"
#include "deps/020e52bc_func_020e52bc.h"

void func_020e52bc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FormatFindMapObjFileBuffer_0_from_thumb(uRam020e532c);
  func_020ea588(piRam020e5330,uVar1,0);
  Model_Render(*piRam020e5330,0x3f);
  StructML_SomeFn_8(*piRam020e5330,0);
  iVar2 = *piRam020e5330;
  iVar3 = *(int *)(iVar2 + 4);
  iVar3 = iVar3 + *(int *)(iVar3 + 8);
  *piRam020e5334 = iVar3 + *(int *)(iVar3 + (uint)*(ushort *)(iVar3 + 10) + 8);
  iVar2 = *(int *)(iVar2 + 4);
  iVar2 = iVar2 + *(int *)(iVar2 + 0xc);
  *piRam020e5338 = iVar2 + *(int *)(iVar2 + (uint)*(ushort *)(iVar2 + 6) + 4);
  if (*(int *)(*piRam020e533c + 0xc) != 6) {
    uVar1 = find_buf_fn_from_thumb(uRam020e5340);
    func_020ea55c((undefined4 *)(uintptr_t)(uRam020e5344),uVar1,0x3f);
  }
  return;
}

