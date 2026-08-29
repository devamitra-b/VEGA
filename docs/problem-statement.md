# Problem statement

Electric meters and energy-consuming equipment in many deployments lack continuous, low-cost telemetry for monitoring and predictive maintenance. Manual inspection is slow and reactive; energy inefficiencies and faults are often detected late.

The VegaThan / GlowGrid project aims to provide a low-cost, modular telemetry system that:
- Continuously captures voltage, current, power, energy, frequency, and power factor.
- Transmits data over low-power networks (Bluetooth, LoRa) to a central aggregator.
- Forwards aggregated data to the cloud for storage, analysis, and visualization.
- Supplies role-specific dashboards for rapid decision-making (Patrol vs Electrician).

Constraints and non-goals
- This repository focuses on the prototype and documentation; it does not lock the project to a specific cloud provider or final hardware revision.
- Do not assume production-grade security or regulatory approvals until hardware revisions and audits are completed.

Success criteria
- Reliable periodic measurements from PZEM-004T nodes.
- Stable wireless delivery using Bluetooth and/or LoRa in test deployments.
- Clear visualization and role separation in the GlowGrid dashboard.

TODO
- Add real-world test results and sample datasets collected from field trials.
