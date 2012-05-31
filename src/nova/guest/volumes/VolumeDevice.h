#ifndef __NOVA_GUEST_VOLUMES_VOLUMEDEVICE_H
#define __NOVA_GUEST_VOLUMES_VOLUMEDEVICE_H

#include <string>


namespace nova { namespace guest { namespace volumes {


class VolumeDevice {

public:
    VolumeDevice(const char * device_path);

    void resize_fs(double time_out);

private:
    std::string device_path;
};


} } } // end nova::guest::volumes

#endif // __NOVA_GUEST_VOLUMES_VOLUMEDEVICE_H
