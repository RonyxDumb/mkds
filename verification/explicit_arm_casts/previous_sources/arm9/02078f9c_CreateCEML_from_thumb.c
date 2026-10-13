/* Decompiled C draft; module arm9; ROM address 02078f9c. No matching claim. */
#include "types.h"
#include "deps/02078f9c_CreateCEML_from_thumb.h"

void CreateCEML_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 local_c;
  
  ReadKartModelMenuFile_from_thumb(param_1,uRam02078ff8,&local_10);
  ReadKartModelMenuFile_from_thumb(param_1,uRam02078ffc,&local_c);
  uVar3 = Mem_AllocateHeap(param_1,0x6c);
  iVar2 = iRam02079004;
  piVar1 = piRam02079000;
  *(undefined4 *)(*piRam02079000 + iRam02079004) = uVar3;
  Model_CreateFromNsbmdNsbtx(*(undefined4 *)(*piVar1 + iVar2),local_10,local_c);
  Model_Render(*(undefined4 *)(*piRam02079000 + iRam02079004),2);
  ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent
            (*(undefined4 *)(*(int *)(*piRam02079000 + iRam02079004) + 4),1);
  return;
}

