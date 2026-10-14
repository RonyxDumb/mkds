/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define CreateAllocateMapObject_from_thumb SDK_data_0209bef1
#define LoadSmanBottomMapObject SDK_data_020a7eb4
#define func_020915c0 SDK_data_020a79c4
#define Maybe_get_17b0b4 SDK_data_020a7eb0
#define Maybe_helper_091214 Maybe_helper_0a7358
extern void CreateAllocateMapObject_from_thumb(void *a0, void *a1, void *a2);
extern void LoadSmanBottomMapObject(void);
extern void func_020915c0(void);
extern void Maybe_get_17b0b4(void);

void Maybe_helper_091214(void) {
    CreateAllocateMapObject_from_thumb((void *)LoadSmanBottomMapObject,
                                       (void *)func_020915c0,
                                       (void *)Maybe_get_17b0b4);
}
