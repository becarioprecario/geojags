#include <version.h>

extern "C" {
    
    const char * jags_version()
    {
	const char * version = "4.3.0";
	return version;
    }

}
