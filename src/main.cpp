/*
 * AtomS3 QR Code Scanner
 * Example implementation for M5Stack AtomS3 with Unit QRCode
 */

#include <M5Unified.h>
#include "BarcodeAdapter.h"
#include "DisplayAdapter.h"
#include "configuration.h"

BarcodeAdapter scanner;
DisplayAdapter display;

void setup() {
    M5.begin();
    display.begin();

    Serial.begin(SERIAL_BAUD_RATE);
    delay(INIT_DELAY_MS);

    Serial.println("\n=== AtomS3 QR Code Scanner ===");

    // Initialize barcode scanner
    Serial.println("Initializing QRCode unit...");
    if (scanner.begin()) {
        Serial.println("QRCode unit ready!");
        Serial.println("Scan mode: Manual");
        Serial.println("Press button on QRCode unit to scan\n");
        display.showReadyScreen();
    } else {
        Serial.println("Failed to initialize QRCode unit!");
        display.showErrorScreen();
    }
}

void loop() {
    if (!scanner.isReady()) {
        delay(INIT_DELAY_MS);
        return;
    }

    M5.update();

    // Optional: Use AtomS3 button to trigger scan
    if (M5.BtnA.wasPressed()) {
        Serial.println("Starting scan...");
        scanner.startScan();
        display.showScanningScreen();
    }

    // Check if a barcode/QR code has been scanned
    if (scanner.hasScannedData()) {
        String data = scanner.getScannedData();

        if (data.length() > 0) {
            // Log to serial
            Serial.println("\n========== SCANNED ==========");
            Serial.printf("Length: %d bytes\n", data.length());
            Serial.print("Data: ");
            Serial.println(data);
            Serial.println("============================\n");
            Serial.println("Ready for next scan");

            // Display on screen
            display.showScannedData(data);
        }
    }

    delay(LOOP_DELAY_MS);
}
