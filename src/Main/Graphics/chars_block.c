#include "Main/Graphics/chars_block.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_02181f98.h"
#include "code_0214cfe4.h"
#include "code_02022aa8.h"

void InitFontIfLoaded(void *font, void *fontData) {
    if (fontData != NULL) {
        NNS_G2dFontInitAuto(font, fontData);
    }
}

void CopyCharsBlock(void *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight, void *destination,
                    s32 destinationTileX, s32 destinationTileY) {
    s32 columnIndex;
    s32 rowIndex;

    for (columnIndex = 0; columnIndex < tileWidth; columnIndex++) {
        for (rowIndex = 0; rowIndex < tileHeight; rowIndex++) {
            MIi_CpuCopy16((u8 *) source + (sourceTileX + columnIndex) * 32 + (sourceTileY + rowIndex) * 1024,
                          (u8 *) destination + (destinationTileX + columnIndex) * 32 +
                              (destinationTileY + rowIndex) * 1024,
                          0x20);
        }
    }
}

void CopyCharsBlockFlippedVertically(u16 *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight,
                                     u16 *destination, s32 destinationTileX, s32 destinationTileY) {
    s32 columnIndex;
    s32 rowIndex;
    s32 pixelRow;
    s32 byteIndex;

    for (columnIndex = 0; columnIndex < tileWidth; columnIndex++) {
        for (rowIndex = 0; rowIndex < tileHeight; rowIndex++) {
            for (pixelRow = 0; pixelRow < 8; pixelRow++) {
                for (byteIndex = 0; byteIndex < 2; byteIndex++) {
                    (destination + (destinationTileX + columnIndex) * 16 +
                     (destinationTileY + (tileHeight - rowIndex - 1)) * 512)[(7 - pixelRow) * 2 + byteIndex] =
                        (source + (sourceTileX + columnIndex) * 16 +
                         (sourceTileY + rowIndex) * 512)[pixelRow * 2 + byteIndex];
                }
            }
        }
    }
}

void CopyScreenMapBlock(u16 *source, s32 sourceColumn, s32 sourceRow, s32 columnCount, s32 rowCount, u16 *destination,
                        s32 destinationColumn, s32 destinationRow) {
    u16 *destinationMap;
    s32 columnIndex;
    s32 rowIndex;

    destinationMap = destination;
    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        for (columnIndex = 0; columnIndex < columnCount; columnIndex++) {
            destinationMap[(destinationColumn + columnIndex) + (destinationRow + rowIndex) * 32] =
                source[(sourceColumn + columnIndex) + (sourceRow + rowIndex) * 32];
        }
    }
}

void SetScreenMapBlockTopBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, u16 topBits) {
    s32 rowIndex;
    s32 columnIndex;

    for (rowIndex = row; rowIndex < row + rowCount; rowIndex++) {
        for (columnIndex = column; columnIndex < column + columnCount; columnIndex++) {
            screenMap[rowIndex * 32 + columnIndex] =
                (topBits << 12) | (u16) (screenMap[rowIndex * 32 + columnIndex] & 0xfff);
        }
    }
}

void SetScreenMapBlockLowBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, s32 lowBits) {
    s32 rowIndex;
    s32 columnIndex;

    for (rowIndex = row; rowIndex < row + rowCount; rowIndex++) {
        for (columnIndex = column; columnIndex < column + columnCount; columnIndex++) {
            screenMap[rowIndex * 32 + columnIndex] = lowBits | (u16) (screenMap[rowIndex * 32 + columnIndex] & 0xfc00);
        }
    }
}

static inline u16 *GetCharsBlockTile(u16 *chars, s32 firstTile, s32 tileIndex) {
    return chars + (firstTile + tileIndex % 4) * 16 + tileIndex / 4 * 512;
}

void CopyPlayerCharacterPaletteAndChars(u16 *paletteDestination, s32 paletteRow, u16 *charsDestination, s32 column,
                                        s32 row) {
    RaceSetup *raceSetup = gRaceSetup;
    Nclr *palette;
    Ncgr *chars;
    u16 *charsRightColumn;
    u16 *charsBlock;
    u16 *paletteColors;
    s32 characterIndex;
    s32 paletteCharacterIndex;
    s32 rightTileIndex;
    s32 tileIndex;
    s32 colorIndex;
    u16 entryIndex;
    u16 *charsBottomRow;
    s32 bottomTileIndex;

    entryIndex = raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
    characterIndex = raceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
    if (characterIndex == 12) {
        palette = GetPlayerCharacterShyguyNclr(1);
    } else {
        palette = GetPlayerCharacterNclr(1);
    }
    chars = GetPlayerCharacterNcgr(1);
    paletteColors = palette->mData;
    if (characterIndex == 12) {
        paletteCharacterIndex = gMenuShared->mShuffledIndices[(
            u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex : gRaceSetup->mEntryIndex)];
    } else {
        paletteCharacterIndex = characterIndex;
    }
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        paletteDestination[paletteRow * 16 + colorIndex] = paletteColors[paletteCharacterIndex * 16 + colorIndex];
    }
    charsBlock = chars->mData;
    for (tileIndex = 0; tileIndex < 16; tileIndex++) {
        MIi_CpuCopy16(charsBlock + (characterIndex * 25 + tileIndex) * 16,
                      GetCharsBlockTile(charsDestination, column + row * 32, tileIndex), 0x20);
    }
    charsRightColumn = chars->mData;
    for (rightTileIndex = 0; rightTileIndex < 4; rightTileIndex++) {
        MIi_CpuCopy16(charsRightColumn + (characterIndex * 25 + 16 + rightTileIndex) * 16,
                      charsDestination + (column + 4 + row * 32) * 16 + rightTileIndex * 512, 0x20);
    }
    charsBottomRow = chars->mData;
    for (bottomTileIndex = 0; bottomTileIndex < 4; bottomTileIndex++) {
        MIi_CpuCopy16(charsBottomRow + (characterIndex * 25 + 20 + bottomTileIndex) * 16,
                      GetCharsBlockTile(charsDestination, column + (row + 4) * 32, bottomTileIndex), 0x20);
    }
    MIi_CpuCopy16(chars->mData + (characterIndex * 25 + 24) * 16, charsDestination + (column + 4 + (row + 4) * 32) * 16,
                  0x20);
}
