#include "z64.h"
#include "get_items.h"
#include "scene.h"
#include "actor.h"
#include "models.h"
#include "item_table.h"
#include "util.h"
#include "save.h"

extern uint8_t SHUFFLE_RICHARD;

bool Is_Richard(uint16_t dog_params) {
    // 0x0F00 is the dog ID, and Richard has ID of 1.

    uint16_t id = (dog_params & 0xF00) >> 8;
    return id == 1;
}

void Dog_Set_Scale(z64_actor_t* actor, float scale) {
    actor->scale.z = scale;
    actor->scale.y = scale;
    actor->scale.x = scale;

    bool is_richard = Is_Richard(actor->variable);

    // If dog shuffle is on, we haven't found Richard, and this actor is Richard, delete him.
    if (SHUFFLE_RICHARD && !extended_savectx.has_richard && is_richard) {
        z64_ActorKill(actor);
    }
}

uint16_t Get_Dog_Lady_Text(bool original_cond) {
    // If shuffling Richard and he is missing, use the lost dog text.
    if (SHUFFLE_RICHARD && !extended_savectx.has_richard) {
        return 0x709D;
    }

    // Use original text otherwise.
    return original_cond ? 0x709B : 0x709C;
}
