# Project overview

VegaThan is an embedded + web project that monitors electrical energy parameters and forwards observations to a cloud backend for visualization and analysis. The frontend dashboard is named GlowGrid and provides role-aware views (Patrol, Electrician).

This repository is organized so hardware/firmware and software artifacts can evolve independently while documentation provides clear guidance for tests and integration.

What this repo contains (short)
- docs/: design spec, component guides, and troubleshooting notes
- firmware/: ETS IoT and Vega board firmware prototypes
- web-dashboard/: GlowGrid PWA prototype and assets
- diagrams/: architecture and data-flow diagrams
- images/: wiring photos, screenshots, and hardware pictures

Intended users
- Students and developers exploring IoT telemetry
- Hackathon or SIH participants and judges
- Field technicians and electricians testing nodes
- Future contributors and maintainers

Status
- Prototype: the PWA exists as a single-file prototype (index.html). Firmware directories hold placeholders for sensor reading and communication examples.

TODO
- Add example firmware code and step-by-step wiring photos for each board.
- Add backend examples for receiving and storing data (MQTT / REST).
