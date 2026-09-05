// esp32_uart_transmitter.ino
// GlowGrid / VegaThan IoT project
// ESP32 firmware to act as a telemetry transmitter for the VEGA ARIES v2.0 board.
//
// Purpose:
// - Establish UART communication between an ESP32 and the VEGA ARIES v2.0 board.
// - Send JSON telemetry for three streetlights every 2000 milliseconds (2 seconds).
// - Use UART1 (HardwareSerial) on the ESP32 to communicate with VEGA ARIES (RX1/TX1).
// - Print sent telemetry and any responses to the Serial Monitor (115200 baud) for debugging.
//
// Hardware connections:
// - ESP32 GPIO18 (TX) -> VEGA ARIES RX1
// - ESP32 GPIO19 (RX) <- VEGA ARIES TX1
// - ESP32 GND          -> VEGA ARIES GND
//
// Note: A common GND connection between the ESP32 and VEGA ARIES is essential for
// reliable UART communication. Without a shared ground reference, voltage levels
// are undefined and the receiver may read noise instead of valid data.

#define ARIES_TX_PIN 18
#define ARIES_RX_PIN 19
#define UART_BAUD 9600

// Use HardwareSerial UART1 on the ESP32
HardwareSerial ariesSerial(1);

// Transmission interval in milliseconds (2 seconds)
const unsigned long TRANSMIT_INTERVAL_MS = 2000UL;
unsigned long lastTransmitMillis = 0UL;

// Function prototypes
void sendDataToAries();

void setup() {
  // Initialize the Serial Monitor for debugging at 115200 baud
  Serial.begin(115200);
  while (!Serial && millis() < 2000) {
    // Give the Serial Monitor a moment to attach (useful in some environments)
    ;
  }

  // Initialize UART1 for communication with VEGA ARIES
  // UART configuration: 9600 baud, 8 data bits, no parity, 1 stop bit (8N1)
  // Pin order for begin: baud, config, rxPin, txPin
  ariesSerial.begin(
    UART_BAUD,
    SERIAL_8N1,
    ARIES_RX_PIN,
    ARIES_TX_PIN
  );

  // Print configuration to the Serial Monitor
  Serial.println("ESP32 -> VEGA ARIES UART Transmitter");
  Serial.print("ARIES TX pin (ESP32 -> ARIES RX1): "); Serial.println(ARIES_TX_PIN);
  Serial.print("ARIES RX pin (ESP32 <- ARIES TX1): "); Serial.println(ARIES_RX_PIN);
  Serial.print("UART baud rate: "); Serial.println(UART_BAUD);
  Serial.println("Using HardwareSerial UART1 (ariesSerial)");
  Serial.println();

  // Initial transmit immediately on startup
  lastTransmitMillis = millis() - TRANSMIT_INTERVAL_MS;
}

void loop() {
  unsigned long now = millis();

  // Non-blocking interval: send data every TRANSMIT_INTERVAL_MS milliseconds
  if (now - lastTransmitMillis >= TRANSMIT_INTERVAL_MS) {
    lastTransmitMillis = now;
    sendDataToAries();
  }

  // Check for optional responses from the VEGA ARIES board
  // The VEGA ARIES may reply with acknowledgements or diagnostics. Print any
  // received data to the Serial Monitor for debugging.
  while (ariesSerial.available() > 0) {
    // Read incoming bytes and forward them to the Serial Monitor
    char c = (char)ariesSerial.read();
    Serial.write(c);
  }
}

// Build JSON telemetry and send it to the VEGA ARIES board via UART
void sendDataToAries() {
  // Construct JSON payload containing telemetry for three streetlights: SL-01, SL-02, SL-03
  // The VEGA ARIES receiver expects newline-terminated JSON messages. We use
  // ariesSerial.println() to ensure a newline character ("\n") is appended.
  // Example structure (compact JSON):
  // {
  //   "SL-01": {"voltage":230.5, "current":1.25, "power":287.5, "status":"NORMAL"},
  //   "SL-02": {"voltage":228.4, "current":0.00, "power":0.0,   "status":"FAULT"},
  //   "SL-03": {"voltage":229.1, "current":0.00, "power":0.0,   "status":"FAULT"}
  // }

  String telemetry = "{";
  telemetry += "\"SL-01\":{";
  telemetry += "\"voltage\":230.5,";
  telemetry += "\"current\":1.25,";
  telemetry += "\"power\":287.5,";
  telemetry += "\"status\":\"NORMAL\"}";

  telemetry += ",\"SL-02\":{";
  telemetry += "\"voltage\":228.4,";
  telemetry += "\"current\":0.00,";
  telemetry += "\"power\":0.0,";
  telemetry += "\"status\":\"FAULT\"}";

  telemetry += ",\"SL-03\":{";
  telemetry += "\"voltage\":229.1,";
  telemetry += "\"current\":0.00,";
  telemetry += "\"power\":0.0,";
  telemetry += "\"status\":\"FAULT\"}";

  telemetry += "}";

  // Send telemetry to VEGA ARIES via UART1. println() adds a newline so the ARIES
  // receiver can detect the end of the message.
  ariesSerial.println(telemetry);

  // Print the transmitted JSON to the Serial Monitor for debugging
  Serial.print("Transmitted to ARIES: ");
  Serial.println(telemetry);

  // Note: The VEGA ARIES v2.0 board receives this telemetry and runs an embedded
  // 10-tree Random Forest machine learning model that uses features such as
  // voltage, current, power, previous power, and operating hours to predict
  // the condition of streetlights. Possible predicted conditions include:
  // - DIM_OR_DEGRADED
  // - FAULTY
  // - NORMAL
  // - REMOVED_OR_OFFLINE
}
