# Introduction #

How to deploy apps into a device in Ubuntu.


# Details #

-Enable USB-debugging on the device.
-Connect
-From console:

-Display device info:
$lsusb
Bus 001 Device 009: ID XXXX:YYYY Google Inc.

-Get XXXX and YYYY:

-Create adb daemon conf (r+x perms):
$sudo vi /etc/udev/rules.d/51-android.rules
SUBSYSTEM=="usb", ATTR{idVendor}=="XXXX", ATTR{idProduct}=="YYYY", MODE="0666", GROUP="plugdev"

-Configure eclipse target

More info: http://developer.android.com/tools/device.html