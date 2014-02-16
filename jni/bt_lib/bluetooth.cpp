#include "bluetooth.h"
#include "my_log.h"

namespace bt {
	bool  init()
	{
		LOGI("_BT_ - Bluetooth lib loaded successfully");
		return true;
	}
}
