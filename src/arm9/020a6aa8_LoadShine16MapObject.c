/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_02166698 SDK_data_021678cc
#define data_021666a8 SDK_data_021678dc
#define data_0217b0c4 SDK_data_0217b224
#define LoadBasabasaMapObject LoadShine16MapObject
// PURPOSE: Loads the Basabasa map object and its animation.
// Arguments: a0 is probably the map-object setup context.
// Behaviour: creates the model from the Basabasa model and animation assets,
// then saves it and assigns polygon ID 0x3f.

extern int data_02166698;
extern int data_021666a8;
extern void *data_0217b0c4;
extern void *CreateMapObjectFromModelAndAnimation_from_thumb(void *a0, void *a1, void *a2);
extern void StructMapObject_MaybeSetPolygonId(void *obj, int id);

void LoadBasabasaMapObject(void *a0) {
    void *obj = CreateMapObjectFromModelAndAnimation_from_thumb(a0, &data_02166698, &data_021666a8);
    data_0217b0c4 = obj;
    StructMapObject_MaybeSetPolygonId(obj, 0x3f);
}
