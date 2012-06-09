#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "vmulticlient.h"
#include "dll.h"

BYTE VMultiGetKeyCode( BYTE virtualKey ){
    BYTE map[256];
    memset( map, 0, 256 * sizeof( BYTE ) );
    map['A'] = 0x04; map['B'] = 0x05; map['C'] = 0x06; map['D'] = 0x07; map['E'] = 0x08;
    map['F'] = 0x09; map['G'] = 0x0A; map['H'] = 0x0B; map['I'] = 0x0C; map['J'] = 0x0D;
    map['K'] = 0x0E; map['L'] = 0x0F; map['M'] = 0x10; map['N'] = 0x11; map['O'] = 0x12;
    map['P'] = 0x13; map['Q'] = 0x14; map['R'] = 0x15; map['S'] = 0x16; map['T'] = 0x17;
    map['U'] = 0x18; map['V'] = 0x19; map['W'] = 0x1A; map['X'] = 0x1B; map['Y'] = 0x1C;
    map['Z'] = 0x1D;
    return map[virtualKey];
}

void *VMultiCreateKeyboardClient(){
    pvmulti_client client = vmulti_alloc();
    if( client == NULL ){
        return NULL;
    }

    if( !vmulti_connect( client ) ){
        vmulti_free( client );
        return NULL;
    }
    
    return client;
}

void VMultiRelease( void *client ){
    vmulti_disconnect( client );
    vmulti_free( client );
}

void VMultiSetKey( void *client, BYTE virtualKey ){
    BYTE shiftKeys = 0;
    BYTE keyCodes[KBD_KEY_CODES] = { 0, 0, 0, 0, 0, 0 };
    keyCodes[0] = VMultiGetKeyCode( virtualKey );
    vmulti_update_keyboard( client, shiftKeys, keyCodes );
}

void VMultiClearKey( void *client ){
    BYTE shiftKeys = 0;
    BYTE keyCodes[KBD_KEY_CODES] = { 0, 0, 0, 0, 0, 0 };
    vmulti_update_keyboard( client, shiftKeys, keyCodes );
}
