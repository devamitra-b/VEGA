# System architecture

This document describes the conceptual architecture and recommended node responsibilities.

## High-level components
- Sensor Node (ETS IoT + PZEM)
- Vega / Receiver Node
- Central Node / Gateway
- Cloud Backend (API / DB / Analytics)
- GlowGrid Web Dashboard

## Conceptual flow (Mermaid)

```mermaid
flowchart TD
  A[Electrical Load] --> B[PZEM-004T Energy Meter]
  B --> C[ETS IoT Sensor Node]
  C --> D{Communication Method}
  D -->|Bluetooth| E[Vega Board]
  D -->|Bluetooth| F[ETS IoT Node 2]
  D -->|LoRa| G[Central LoRa Node]
  E --> G
  F --> G
  G --> H[Gateway / Internet]
  H --> I[Cloud Backend]
  I --> J[Database]
  J --> K[GlowGrid Web Dashboard]
```

## Notes
- The architecture should be flexible: keep Bluetooth, LoRa, and direct Internet options configurable.
- The Central Node performs aggregation, validation, node identification, and forwarding.

TODO
- Add a network topology drawing (PNG / SVG) in diagrams/ once hardware selection final.
