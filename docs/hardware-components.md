# Hardware components

This page lists the main hardware components used in VegaThan and recommended notes for wiring and procurement.

## Core hardware (prototype)
- PZEM-004T v3.0 — energy meter module (voltage, current, power, energy, frequency, power factor)
- ETS IoT board — ESP32-based or equivalent microcontroller used as the sensor node (UART, BLE, LoRa interfaces)
- Vega board — receiver/aggregator board (Bluetooth receiver, data forwarding)
- LoRa transceivers — SX1276-family, or Ebyte modules (E220) depending on availability
- LoRa Gateway — concentrator or dedicated gateway device

## Accessories
- Power supply (5V or as required by boards and PZEM)
- Level shifting (if needed between 5V sensor and 3.3V MCU)
- Antennas for LoRa and BLE
- Wiring harness and terminal blocks

Placeholders
- Exact ETS IoT board part number and pinout should be added here once available.

TODO
- Add images of each component in `images/hardware/` and wiring diagrams.
