/*
 * BarcodeAdapter - Abstraction layer for M5Stack Unit QRCode
 */

#ifndef BARCODE_ADAPTER_H
#define BARCODE_ADAPTER_H

#include <Arduino.h>
#include "M5UnitQRCode.h"
#include "configuration.h"

class BarcodeAdapter {
public:
    BarcodeAdapter();

    // Initialize the barcode scanner
    bool begin();

    // Check if scanner is ready
    bool isReady() const;

    // Check if a code has been scanned
    bool hasScannedData();

    // Get the scanned data
    String getScannedData();

    // Get the length of last scanned data
    uint16_t getDataLength();

    // Start a scan (manual mode)
    void startScan();

    // Stop scanning
    void stopScan();

private:
    M5UnitQRCodeI2C qrcode;
    bool ready;
    bool scanning;
};

#endif // BARCODE_ADAPTER_H
