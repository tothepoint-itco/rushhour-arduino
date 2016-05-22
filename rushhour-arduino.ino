#include "Wire.h"

const int CHIP_1_ID = 0x20;
const int CHIP_2_ID = 0x24;
const int CHIP_3_ID = 0x26;

const int PORT_A = 0x13;
const int PORT_B = 0x12;

const int ROW_1_ID = CHIP_1_ID;
const int ROW_1_PORT = PORT_A;
const int ROW_2_ID = CHIP_1_ID;
const int ROW_2_PORT = PORT_B;
const int ROW_3_ID = CHIP_2_ID;
const int ROW_3_PORT = PORT_A;
const int ROW_4_ID = CHIP_2_ID;
const int ROW_4_PORT = PORT_B;
const int ROW_5_ID = CHIP_3_ID;
const int ROW_5_PORT = PORT_A;
const int ROW_6_ID = CHIP_3_ID;
const int ROW_6_PORT = PORT_B;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.print("Reading row 1: ");
  Serial.println(String(readRow(1), BIN));

  Serial.print("Reading row 2: ");
  Serial.println(String(readRow(2), BIN));

  Serial.print("Reading row 3: ");
  Serial.println(String(readRow(3), BIN));

  Serial.print("Reading row 4: ");
  Serial.println(String(readRow(4), BIN));

  Serial.print("Reading row 5: ");
  Serial.println(String(readRow(5), BIN));

  Serial.print("Reading row 6: ");
  Serial.println(String(readRow(6), BIN));
  
  delay(3000);
}



byte readRow(int row) {
  int CHIP_ID;
  int CHIP_PORT;
  int shiftBitsRight;

  const int SHIFT_LEFT = 0x01;
  const int SHIFT_RIGHT = 0x02;

  if (row < 1 || row > 6) {
    return 0;
  }

  switch(row) {
    case 1:
      CHIP_ID = ROW_1_ID;
      CHIP_PORT = ROW_1_PORT;
      shiftBitsRight = 0;
      break;
    case 2:
      CHIP_ID = ROW_2_ID;
      CHIP_PORT = ROW_2_PORT;
      shiftBitsRight = 2;
      break;
    case 3:
      CHIP_ID = ROW_3_ID;
      CHIP_PORT = ROW_3_PORT;
      shiftBitsRight = 0;
      break;
    case 4:
      CHIP_ID = ROW_4_ID;
      CHIP_PORT = ROW_4_PORT;
      shiftBitsRight = 2;
      break;
    case 5:
      CHIP_ID = ROW_5_ID;
      CHIP_PORT = ROW_5_PORT;
      shiftBitsRight = 0;
      break;
    case 6:
      CHIP_ID = ROW_6_ID;
      CHIP_PORT = ROW_6_PORT;
      shiftBitsRight = 2;
      break;
  }

  Wire.beginTransmission(CHIP_ID);
  Wire.write(CHIP_PORT);
  Wire.endTransmission();
  Wire.requestFrom(CHIP_ID, 2);
  return Wire.read() >> shiftBitsRight;
}


