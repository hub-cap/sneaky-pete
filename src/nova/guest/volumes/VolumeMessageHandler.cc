#include "nova/guest/volumes/VolumeMessageHandler.h"
#include "nova/guest/volumes/VolumeDevice.h"


using nova::JsonData;
using nova::JsonDataPtr;
using nova::guest::volumes::VolumeDevice;


namespace nova { namespace guest { namespace volumes {


VolumeMessageHandler::VolumeMessageHandler(const double resize_fs_time_out)
: resize_fs_time_out(resize_fs_time_out) {
}

JsonDataPtr VolumeMessageHandler::handle_message(const GuestInput & input) {
    if (input.method_name == "resize_fs") {
        VolumeDevice dev(input.args->get_string("device_path"));
        dev.resize_fs(resize_fs_time_out);
        return JsonData::from_null();
    } else {
        return JsonDataPtr();
    }
}

} } } // end namespace nova::guest::volumes
