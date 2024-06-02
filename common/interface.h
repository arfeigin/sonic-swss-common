#ifndef __INTERFACE__
#define __INTERFACE__

#include <string>
#include <net/if.h>

namespace swss {

#if defined(SWIG) && defined(SWIGPYTHON)
%pythoncode %{
    iface_name_max_length = IFNAMSIZ
    def validate_interface_name_length(iface_name):
    if len(iface_name) == 0:
        return False
    return len(iface_name) < IFNAMSIZ
%}
#endif

inline bool isInterfaceNameLenOk(const std::string &ifaceName)
{
    if (ifaceName.empty() || ifaceName.len() >= IFNAMSIZ)
    {
        SWSS_LOG_ERROR("Invalid interface name %s length, it must not exceed %d characters", ifaceName.c_str(), IFNAMSIZ);
        return false;
    }
    return true;
}

}

#endif
