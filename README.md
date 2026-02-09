# 16-Byte Serial Packet Communication Between Arduino and Qt with CRC16 Validation

## Overview

This project implements a **robust serial communication system** between an **Arduino Uno** and a **Qt-based desktop application** using a **custom 16-byte packet protocol** with **CRC16 checksum validation**.

The Qt application receives fixed-length packets from Arduino, validates the data by matching a predefined header and verifying the CRC16 checksum, then:

- Parses the payload data  
- Displays values on LCD widgets  
- Logs data into a CSV file  
- Plots real-time graphs using Qt Charts  

The project demonstrates reliable packet-based communication suitable for embedded systems, avionics, and health monitoring applications.

---

## Features

- Fixed-length 16-byte packet protocol  
- Header-based packet synchronization  
- CRC16 checksum implementation on **both Arduino and Qt sides**  
- Real-time serial data reception  
- Payload parsing and validation  
- Live display on multiple LCD widgets  
- Real-time plotting using **QChart**  
- Automatic CSV data logging  
- Error detection for corrupted or invalid packets  

---

## Packet Structure

### 16-Byte Packet Format

| Byte Index | Description                     | Example Value        |
|-----------:|---------------------------------|----------------------|
| 0–2        | Header (`$DC`)                  | `0x24 0x44 0x43`     |
| 3–13       | Data Payload (11 bytes)         | User-defined data    |
| 14–15     | CRC16 Checksum (bytes 0–13)     | Calculated value     |

- CRC16 is calculated over **bytes 0–13**
- Packet is accepted **only if both header and CRC match**

---

## System Architecture

Arduino Uno
│
│ UART (16-byte packets)
▼
Qt Serial Receiver
│
├─ Header Validation
├─ CRC16 Verification
├─ Payload Parsing
├─ LCD Display Update
├─ CSV Logging
└─ Real-Time Plotting (QChart)

---

## Tools & Technologies

- Arduino Uno  
- Qt 6 (Qt Creator, C++)  
- Qt Serial Port  
- Qt Charts  
- CRC16 Algorithm  
- CSV File Logging  
- Windows / Linux  

---

## Setup Instructions

### 1. Arduino Side

1. Open the Arduino sketch  
2. Ensure packet structure matches the defined format  
3. Implement CRC16 calculation for bytes `0–13`  
4. Upload the code to Arduino Uno  

---

### 2. Qt Application

Clone the repository:

```bash
git clone https://github.com/Nimra01/Data_Integrity_CRC_16.git
cd DataIntegrity
```
Open the project in Qt Creator and ensure the following modules are enabled:

Qt::SerialPort

Qt::Charts

Build and run the application.

3. Serial Configuration

Ensure both Arduino and Qt use identical serial settings:

Baud Rate: 115200 (or configured value)

Data Bits: 8

Parity: None

Stop Bits: 1

Data Handling Workflow

Read serial stream byte-by-byte

Detect packet header ($DC)

Accumulate 16 bytes

Compute CRC16 (bytes 0–13)

Compare with received CRC

Accept or reject packet

Parse payload data

Update LCD widgets

Append data to CSV file

Plot data in real time

<img width="600" height="369" alt="image" src="https://github.com/user-attachments/assets/be3879a6-e695-406a-a3c2-8387e1271474" />

## Output Example

LCD Displays: Show live values of all 11 payload bytes

CSV File: Timestamped data logging for offline analysis

QChart Plot: Real-time visualization of payload trends

## Applications

Embedded system communication

Avionics and UAV health monitoring

Sensor data acquisition systems

Protocol validation and testing

Real-time telemetry visualization

## Notes

Fixed packet length simplifies synchronization

CRC16 ensures data integrity

Invalid packets are discarded safely

Design is scalable for additional payload fields
