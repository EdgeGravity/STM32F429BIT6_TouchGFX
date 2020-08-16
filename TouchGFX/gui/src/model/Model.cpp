#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "EG_Include.h"

extern osMessageQueueId_t GUI_MsgQHandle;

Model::Model() : modelListener(0)
{
    if (KEY_Scan(KEY_S3) == KEY_ON) {

    }
}

void Model::tick()
{
    osStatus_t status;
    uint8_t retKey;

    status = osMessageQueueGet(GUI_MsgQHandle, &retKey, NULL, 0);
    if (status == osOK) {
        modelListener->EG_ChangeScreen(retKey);
    }
}
