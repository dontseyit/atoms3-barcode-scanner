# AtomS3 QR Code Scanner

An implementation demonstrating M5Stack AtomS3 with Unit QRCode over I2C. Provides a working baseline for barcode and QR code scanning applications. Written in PlatformIO using Arduino.

## Overview

A plug-and-play barcode scanner implementation that integrates the M5Stack AtomS3 microcontroller with the M5Stack Unit QRCode scanner module via Atomic ToUnit Base I2C. The combination intentionally chosen for no cables setup and compact mount.

The implementation provides a starting point for a barcode scanner built minimally with only M5Stack products. The code includes basic hardware abstraction, display management, and scanning with displayed feedback.

The Unit QRCode supports 
- Standard 1D barcodes (EAN, UPC, Code128, Code39)
- 2D codes (QR, Data Matrix, PDF417).

### Operation Mode

**Manual Scan**: Scanner activates on button press by design. LED indicator actives during scan cycle, automatically deactivates after successful decode. Decoded data displayed and persists on display until subsequent scan initiated.

## Project Layout

```
├── include/
│   ├── BarcodeAdapter.h    - Scanner abstraction interface
│   ├── DisplayAdapter.h    - Display abstraction interface
│   └── configuration.h     - Hardware and timing constants
├── src/
│   ├── BarcodeAdapter.cpp  - Scanner implementation
│   ├── DisplayAdapter.cpp  - Display implementation
│   └── main.cpp            - Application entry point
└── platformio.ini          - PlatformIO build configuration
```

## Hardware Overview

| Component | Specification |
|-----------|---------------|
| **Controller** | M5Stack AtomS3 (ESP32-S3) |
| **Scanner Module** | M5Stack Unit QRCode |
| **Base Adapter** | Atomic ToUnit Base |

### Connection

Direct plug-in connection, no cables required:

```
AtomS3 + Atomic ToUnit Base ──► Unit QRCode (HY2.0-4P)
```

### I2C Configuration

| Parameter | Value |
|-----------|-------|
| I2C Address | `0x21` |
| SDA Pin | GPIO7 |
| SCL Pin | GPIO8 |
| Frequency | 100kHz |

## Build Settings

```ini
Platform:      espressif32
Framework:     Arduino
Board:         esp32-s3-devkitc-1
Monitor Speed: 115200
```

### Library Dependencies

```ini
M5Unified        = https://github.com/m5stack/M5Unified
M5GFX            = https://github.com/m5stack/M5GFX
M5UnitQRCode     = https://github.com/m5stack/M5Unit-QRCode
```
