#ifndef __INTERFACE__
#define __INTERFACE__

#include <string>
#include <net/if.h>

namespace swss {

inline bool isInterfaceNameLenOk(const std::string &ifaceName)
{
    if (ifaceName.length() >= IFNAMSIZ)
    {
        SWSS_LOG_ERROR("Invalid interface name %s length, it must not exceed %d characters", ifaceName.c_str(), IFNAMSIZ);
        return false;
    }
    return true;
}

}

#endif
