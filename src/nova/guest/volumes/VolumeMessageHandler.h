#ifndef __NOVA_GUEST_VOLUMES_VOLUMEMESSAGEHANDLER_H
#define __NOVA_GUEST_VOLUMES_VOLUMEMESSAGEHANDLER_H


#include "nova/guest/guest.h"
#include <nova/json.h>


namespace nova { namespace guest { namespace volumes {


class VolumeMessageHandler : public MessageHandler {
    public:

        VolumeMessageHandler(const double resize_fs_time_out);

        virtual nova::JsonDataPtr handle_message(const GuestInput & input);

    private:
        const double resize_fs_time_out;
};


} } }  // end namespace

#endif //__NOVA_GUEST_VOLUMES_VOLUMEMESSAGEHANDLER_H
