#include "Main/Graphics/nibble_tiles.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

u16 *gKbdmapHiragana;
u16 *gKbdmapKatakana;
u16 *gKbdmapAsciiShift;
u16 *gKbdmapKatakanaDakuten;
u16 *gKbdmapHiraganaDakuten;
u16 *gKbdmapHiraganaHandaku;
u16 *gKbdmapHiraganaSmall;
u16 *gKbdmapAscii;
u16 *gKbdmapAsciiCaps;
u16 *gKbdmapKatakanaHandaku;
u16 *gKbdmapKatakanaSmall;
u16 *gKbdmapOther1;
u16 *gKbdmapOther2;
u16 *gKbdmapOther3;
KeyboardTextEntry *gKeyboardTextEntry;

#pragma thumb on

// Splits each byte of a square image into two 4-bit entries and writes them in blocks of 8 x 8 entries.
void SplitBytesIntoNibbleTiles(void *bytes, u8 *tiles, s32 side) {
    s32 pixelY;
    s32 rowBytes;
    s32 rowStart;
    s32 tilesPerRow;
    s32 byteColumn;
    s32 lowX;
    s32 highX;
    s32 byteIndex;

    rowBytes = side / 2;
    pixelY = 0;
    if (side > 0) {
        rowStart = pixelY;
        tilesPerRow = side / 8;
        do {
            byteColumn = 0;
            if (rowBytes > 0) {
                lowX = byteColumn;
                highX = 1;
                do {
                    byteIndex = byteColumn + rowStart;
                    tiles[(pixelY & 7) * 8 + ((lowX & 7) + lowX / 8 * 64) + tilesPerRow * (pixelY / 8 * 64)] =
                        ((u8 *) bytes)[byteIndex] & 0xf;
                    tiles[(pixelY & 7) * 8 + ((highX & 7) + highX / 8 * 64) + tilesPerRow * (pixelY / 8 * 64)] =
                        (((u8 *) bytes)[byteIndex] >> 4) & 0xf;
                    lowX += 2;
                    highX += 2;
                    byteColumn++;
                } while (byteColumn < rowBytes);
            }
            rowStart += rowBytes;
            pixelY++;
        } while (pixelY < side);
    }
}

// The reverse of SplitBytesIntoNibbleTiles: joins pairs of entries from the 8 x 8 blocks into bytes.
void JoinNibbleTilesIntoBytes(void *tiles, u8 *bytes, s32 side) {
    s32 pixelY;
    s32 rowBytes;
    s32 rowStart;
    s32 tilesPerRow;
    s32 byteColumn;
    s32 highX;
    s32 lowX;

    rowBytes = side / 2;
    pixelY = 0;
    if (side > 0) {
        rowStart = pixelY;
        tilesPerRow = side / 8;
        do {
            byteColumn = 0;
            if (rowBytes > 0) {
                highX = 1;
                lowX = byteColumn;
                do {
                    bytes[byteColumn + rowStart] =
                        ((u8 *)
                             tiles)[(pixelY & 7) * 8 + ((lowX & 7) + lowX / 8 * 64) + tilesPerRow * (pixelY / 8 * 64)] |
                        ((u8 *)
                             tiles)[(pixelY & 7) * 8 + ((highX & 7) + highX / 8 * 64) + tilesPerRow * (pixelY / 8 * 64)]
                            << 4;
                    highX += 2;
                    lowX += 2;
                    byteColumn++;
                } while (byteColumn < rowBytes);
            }
            rowStart += rowBytes;
            pixelY++;
        } while (pixelY < side);
    }
}

// Copies the bytes of a square image into the same 8 x 8 block order, two entries per byte.
void CopyBytesIntoTiles(void *bytes, u8 *tiles, s32 side) {
    s32 pixelY;
    s32 tilesPerRow;
    s32 rowBytes;
    s32 byteColumn;
    s32 entryX;
    s32 rowStart;

    rowBytes = side / 2;
    pixelY = 0;
    if (side > 0) {
        rowStart = pixelY;
        tilesPerRow = side / 8;
        do {
            byteColumn = 0;
            if (rowBytes > 0) {
                entryX = byteColumn;
                do {
                    tiles[((pixelY & 7) * 8 + ((entryX & 7) + entryX / 8 * 64) + tilesPerRow * (pixelY / 8 * 64)) / 2] =
                        ((u8 *) bytes)[byteColumn + rowStart];
                    entryX += 2;
                    byteColumn++;
                } while (byteColumn < rowBytes);
            }
            rowStart += rowBytes;
            pixelY++;
        } while (pixelY < side);
    }
}

#pragma thumb off
