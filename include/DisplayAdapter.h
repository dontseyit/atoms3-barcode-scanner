/*
 * DisplayAdapter - Abstraction layer for M5Stack Display
 */

#ifndef DISPLAY_ADAPTER_H
#define DISPLAY_ADAPTER_H

#include <M5Unified.h>
#include "configuration.h"

class DisplayAdapter {
public:
    DisplayAdapter();

    // Initialize the display
    void begin();

    // Screen state methods
    void showReadyScreen();
    void showErrorScreen();
    void showScanningScreen();
    void showScannedData(const String& data);
};

#endif // DISPLAY_ADAPTER_H
