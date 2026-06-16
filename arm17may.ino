/*
  ╔══════════════════════════════════════════════════════════╗
  ║   Robotic Arm – Arduino Leonardo                         ║
  ║   Works with BOTH audio & image Teachable Machine HTML   ║
  ╠══════════════════════════════════════════════════════════╣
  ║  Servo Wiring:                                           ║
  ║    Claw     → Pin  9  (PWM ~)                            ║
  ║    Elbow    → Pin 10  (PWM ~)                            ║
  ║    Shoulder → Pin 11  (PWM ~)                            ║
  ║    Base     → Pin 12  (PWM ~)                            ║
  ╠══════════════════════════════════════════════════════════╣
  ║  Serial Commands (9600 baud):                            ║
  ║    O → Claw OPEN          C → Claw CLOSE                ║
  ║    U → Shoulder UP        D → Shoulder DOWN              ║
  ║    F → Elbow FORWARD      B → Elbow BACKWARD             ║
  ║    L → Base LEFT          R → Base RIGHT                 ║
  ║    H → HOME all servos (90°)                             ║
  ║                                                          ║
  ║  Arduino replies after every move:                       ║
  ║    POS:claw,elbow,shoulder,base                          ║
  ╚══════════════════════════════════════════════════════════╝
*/

#include <Servo.h>

Servo clawServo;
Servo elbowServo;
Servo shoulderServo;
Servo baseServo;

int clawAngle     = 90;
int elbowAngle    = 90;
int shoulderAngle = 90;
int baseAngle     = 90;

const int STEP = 15;

int clamp(int v) { return max(0, min(180, v)); }

void moveServo(Servo &s, int &angle, int newAngle) {
  angle = clamp(newAngle);
  s.write(angle);
  delay(20);
}

void reportPositions() {
  Serial.print("POS:");
  Serial.print(clawAngle);      Serial.print(",");
  Serial.print(elbowAngle);     Serial.print(",");
  Serial.print(shoulderAngle);  Serial.print(",");
  Serial.println(baseAngle);
}

void homeAll() {
  moveServo(clawServo,     clawAngle,     90);
  moveServo(elbowServo,    elbowAngle,    90);
  moveServo(shoulderServo, shoulderAngle, 90);
  moveServo(baseServo,     baseAngle,     90);
}

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  clawServo.attach(9);
  elbowServo.attach(10);
  shoulderServo.attach(11);
  baseServo.attach(12);
  homeAll();
  Serial.println("READY");
  reportPositions();
}

void loop() {
  if (!Serial.available()) return;
  char cmd = Serial.read();
  switch (cmd) {
    case 'O': moveServo(clawServo,     clawAngle,     0);                    break;
    case 'C': moveServo(clawServo,     clawAngle,     180);                  break;
    case 'U': moveServo(shoulderServo, shoulderAngle, shoulderAngle + STEP); break;
    case 'D': moveServo(shoulderServo, shoulderAngle, shoulderAngle - STEP); break;
    case 'F': moveServo(elbowServo,    elbowAngle,    elbowAngle    + STEP); break;
    case 'B': moveServo(elbowServo,    elbowAngle,    elbowAngle    - STEP); break;
    case 'L': moveServo(baseServo,     baseAngle,     baseAngle     - STEP); break;
    case 'R': moveServo(baseServo,     baseAngle,     baseAngle     + STEP); break;
    case 'H': homeAll();                                                      break;
    default:  return;
  }
  reportPositions();
}
