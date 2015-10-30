# Introduction #

Library for loading PNG files

# Download #

Drive JNI-APP/Libs/lpng152\_ndk.zip


# Instructions #

copy content to $(ANDROID\_NDK)/sources

mv $(ANDROID\_NDK)/sources/libpng/scripts/pnglibconf.h.prebuilt to $(ANDROID\_NDK)/sources/libpng/pnglibconf.h

# Eclipse #

Add libpng folder (${env\_var:ANDROID\_NDK}/sources/libpng) to your
project paths in the Project | Properties | Path and Symbols | Includes tab.