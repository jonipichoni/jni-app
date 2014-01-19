#More info: http://www.kandroid.org/ndk/docs/APPLICATION-MK.html

# APP_ABI := armeabi x86
APP_PLATFORM := android-9


# This optional variable can be defined to either 'release' or 'debug'. 
# This is used to alter the optimization level when
# building your application's modules.
APP_OPTIM := debug

# APP_CFLAGS			# A set of C compiler flags passed when compiling any C or C++ source code of any of the module
#-DDEBUG  				# Internal Debug macro
#-fexceptions   		# -fexceptions: Boost can throw exceptions(http://www.boost.org/doc/libs/1_36_0/libs/utility/throw_exception.html)
#-Wall 					# turn on warnings
#-Wextra        		# turn on extra warnings
#-Werror        		# treat warnings as errors
#-Wno-unused-parameter 	# unused-parameter not as warning
#-Wno-unused-function 	# unused-function not as warning 				
APP_CFLAGS := 	-DDEBUG \
				-fexceptions \
				-Wall \
				-Wextra \
				-Werror \
				-Wno-unused-parameter \
				-Wno-unused-function  

APP_STL := gnustl_static
