#include "Main/Sound/character_seq_pair.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"

const u32 gCharacterSeqPairNoTable[13] = {4, 0, 1, 2, 5, 6, 7, 3, 0xa, 8, 9, 0xb, 0xc};

#pragma thumb on
u32 GetCharacterSeqPairNo(u32 characterIndex) {
    return gCharacterSeqPairNoTable[characterIndex];
}
#pragma thumb off
