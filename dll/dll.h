#include <windows.h>
#include <winuser.h>

void *VMultiCreateKeyboardClient();

void VMultiRelease( void *client );

void VMultiSetKey( void *client, BYTE virtualKey );

void VMultiClearKey( void *client );

BYTE VMultiGetKeyCode( BYTE virtualKey );
