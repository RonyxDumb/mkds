/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */

// PURPOSE: Gets the current frame count of a map object's animation.
// The object probably stores its animation pointer at offset 0x24.
// The returned animation length is converted to the 16-bit frame value.

extern unsigned int Animation_GetCurrentLength(void *animation);

unsigned int func_0209b710(void *object) {
    return (Animation_GetCurrentLength(*(void **)((char *)object + 0x24)) << 4) >> 16;
}
