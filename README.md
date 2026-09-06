# VegaThan — GlowGrid IoT Project

[![Project Status](https://img.shields.io/badge/status-prototype-orange.svg)](https://github.com/devamitra-b/VEGA)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)

GlowGrid is the web dashboard component of the VegaThan IoT project: a modular system for electrical energy monitoring, wireless telemetry (Bluetooth / LoRa), and cloud visualization. This repository contains firmware prototypes, documentation, diagrams, and a Progressive Web App (PWA) prototype for the GlowGrid dashboard.

Key goals
- Capture real-time electrical parameters (voltage, current, power, energy, frequency, power factor).
- Transmit sensor data using Bluetooth or LoRa.
- Aggregate and forward data to the cloud for storage and analytics.
- Provide role-based views for Patrol and Electrician users via a PWA dashboard.

Quick links
- Docs: `docs/` — design notes, hardware reference, and communication guides.
- Firmware prototypes: `firmware/` — ETS IoT and Vega board projects.
- Web dashboard: `web-dashboard/glowgrid-pwa/index.html` (PWA prototype)
- Diagrams: `diagrams/`

Quick start (local)
1. Clone the repo

```bash
git clone https://github.com/devamitra-b/VEGA.git
cd VEGA
```

2. Serve the web dashboard locally (recommended for PWA features)

```bash
# Python 3
python -m http.server 8000
# Then open: http://localhost:8000/web-dashboard/glowgrid-pwa/index.html
```

Notes
- The PWA uses CDN-hosted Leaflet and Google Fonts. An internet connection is required for those assets.
- Google Maps features in the PWA require a Google Maps JavaScript API key — search `GOOGLE_MAPS_API_KEY` in the PWA file for details.

Repository structure (high-level)
```
VegaThan/
├── README.md
├── LICENSE
├── docs/
├── firmware/
├── web-dashboard/glowgrid-pwa/
├── diagrams/
└── images/
```

Contributing
See `CONTRIBUTING.md` for guidelines on PRs, issue templates, and code of conduct.

License
This project is available under the MIT License — see `LICENSE`.
