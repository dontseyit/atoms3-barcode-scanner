/*
 * BarcodeAdapter - Implementation
 */

#include "BarcodeAdapter.h"

BarcodeAdapter::BarcodeAdapter() : ready(false), scanning(false) {
}

bool BarcodeAdapter::begin() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_FREQUENCY);

    ready = qrcode.begin(&Wire, QRCODE_I2C_ADDR, I2C_SDA_PIN, I2C_SCL_PIN, I2C_FREQUENCY);

    if (ready) {
        // Set to manual scan mode (button-triggered)
        qrcode.setTriggerMode(MANUAL_SCAN_MODE);
    }

    return ready;
}

bool BarcodeAdapter::isReady() const {
    return ready;
}

bool BarcodeAdapter::hasScannedData() {
    if (!ready) return false;
    return qrcode.getDecodeReadyStatus() == 1;
}

String BarcodeAdapter::getScannedData() {
    if (!ready) return "";

    uint8_t buffer[SCAN_BUFFER_SIZE] = {0};
    uint16_t length = qrcode.getDecodeLength();

    if (length > 0 && length < SCAN_BUFFER_SIZE) {
        qrcode.getDecodeData(buffer, length);

        // Stop scanning after successful decode
        stopScan();

        // Convert buffer to String
        String result = "";
        for (int i = 0; i < length; i++) {
            result += (char)buffer[i];
        }
        return result;
    }

    return "";
}

uint16_t BarcodeAdapter::getDataLength() {
    if (!ready) return 0;
    return qrcode.getDecodeLength();
}

void BarcodeAdapter::startScan() {
    if (!ready) return;
    qrcode.setDecodeTrigger(1);
    scanning = true;
}

void BarcodeAdapter::stopScan() {
    if (!ready) return;
    qrcode.setDecodeTrigger(0);
    scanning = false;
}
