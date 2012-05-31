#include "nova/guest/volumes/VolumeDevice.h"

#include <boost/assign/list_of.hpp>
#include <boost/assign/std/list.hpp>
#include "nova/Log.h"
#include <boost/optional.hpp>
#include "nova/process.h"
#include <string>


using namespace boost::assign;
using nova::Process;


namespace nova { namespace guest { namespace volumes {


VolumeDevice::VolumeDevice(const char * device_path)
: device_path(device_path) {
}

void VolumeDevice::resize_fs(double time_out) {
    NOVA_LOG_INFO2("Resizing file system for device %s...",
                   device_path.c_str());
    Process::CommandList cmds = list_of("/usr/bin/sudo")("resize2fs")
                                       (device_path.c_str());
    Process::execute(cmds, time_out);
}


} } } // end namespace nova::guest::volumes
