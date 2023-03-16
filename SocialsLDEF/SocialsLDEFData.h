#include <Files.h>

#if PRAGMA_ALIGN_SUPPORTED
#pragma options align=mac68k
#endif

struct SocialsEntry {
	PixMapHandle avatar; // may be NULL, then just draws a black box.
	Handle avatarPixelData; // may be NULL, then avatar.baseAddr is assumed to already be set up.
	Str255 userName;
	char message[1]; // Dynamic length.
};

#if PRAGMA_ALIGN_SUPPORTED
#pragma options align=reset
#endif
