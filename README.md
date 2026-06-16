# 🤖 AI-Based Robotic Arm Using Google Teachable Machine

![Project Banner](Images/robotic_arm.jpg)

## 📌 Project Overview

This project presents an **AI-powered Robotic Arm** controlled through **hand gesture recognition** using **Google Teachable Machine**, **Arduino Leonardo**, and **4 Servo Motors**.

The system uses a webcam to capture hand gestures, which are classified by a machine learning model trained on Google Teachable Machine. The recognized gesture is sent to the Arduino Leonardo, which controls the servo motors to perform corresponding robotic arm movements such as picking, placing, rotating, and gripping objects.

---

## 🎯 Objectives

- Develop an intelligent robotic arm using low-cost components.
- Implement real-time hand gesture recognition.
- Control robotic arm movements using machine learning predictions.
- Demonstrate automation and human-machine interaction.

---

## 🛠 Hardware Components

| Component | Quantity |
|------------|----------|
| Arduino Leonardo | 1 |
| Servo Motors (SG90/MG90S) | 4 |
| Robotic Arm Chassis | 1 |
| USB Webcam | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| External Power Supply | 1 |

---

## 💻 Software Used

- Arduino IDE
- Python 3.x
- Google Teachable Machine
- TensorFlow
- OpenCV
- PySerial

---

## 🧠 Machine Learning Model

### Model Type
Image Classification Model

### Platform
Google Teachable Machine

### Gesture Classes

- Open Hand
- Closed Fist
- Left
- Right
- Pick Object

### Dataset

Custom image dataset captured using a webcam.

| Class | Images |
|---------|---------|
| Open Hand | 100+ |
| Closed Fist | 100+ |
| Left | 100+ |
| Right | 100+ |
| Pick | 100+ |

---

## ⚙️ System Architecture

```text
Hand Gesture
      ↓
Webcam
      ↓
Google Teachable Machine
      ↓
Python Program
      ↓
Serial Communication
      ↓
Arduino Leonardo
      ↓
4 Servo Motors
      ↓
Robotic Arm Movement
