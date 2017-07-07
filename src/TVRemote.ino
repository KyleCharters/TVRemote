#include <IRTransmitter.h>

//Set pin that infrared led is connected to
#define IR_PIN D0
//Set pin that led is connected to
#define LED_PIN D7

//All options
unsigned int tv_on[31] = {564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_off[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_hdmi_1[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_hdmi_2[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_hdmi_3[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564};
unsigned int tv_channel_up[31] = {564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_channel_down[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_volume_up[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_volume_down[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_mute_on[31] = {564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_mute_off[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692};
unsigned int tv_num_0[31] = {564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_1[31] = {1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_2[31] = {564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_3[31] = {1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_4[31] = {564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564,1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_5[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_6[31] = {564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_7[31] = {1692, 564, 1692, 564, 1692, 564, 564, 564, 1692,564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_8[31] = {564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_num_9[31] = {1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692};
unsigned int tv_ok[31] = {564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_up[31] = {1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_down[31] = {564, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_left[31] = {1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_right[31] = {564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_exit[31] = {1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692};
unsigned int tv_enter[31] = {1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564};

//Skeleton for every signal
unsigned int signalData[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564,
  1692, 564, 1692, 564, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 564, 39756};

//Initialize ir library
IRTransmitter transmitter(IR_PIN, LED_PIN);

void transmit(unsigned int * data){
  //Replace middle section of skeleton with specified option
  for (int i = 35; i < 66; i++)
    signalData[i] = data[i - 35];

  //Send signal through ir led
  transmitter.Transmit(signalData, 68);
}

int postPower(String command){
  switch (command[0]) {
    case '0':
      transmit(tv_off);
      break;
    case '1':
      transmit(tv_on);
      break;
    default:
      return -1;
  }
  return 0;
}

int postNumber(String command){
  for (int i = 0; i < strlen(command); i++){
    switch (command[i]) {
      case '0':
        transmit(tv_num_0);
        break;
      case '1':
        transmit(tv_num_1);
        break;
      case '2':
        transmit(tv_num_2);
        break;
      case '3':
        transmit(tv_num_3);
        break;
      case '4':
        transmit(tv_num_4);
        break;
      case '5':
        transmit(tv_num_5);
        break;
      case '6':
        transmit(tv_num_6);
        break;
      case '7':
        transmit(tv_num_7);
        break;
      case '8':
        transmit(tv_num_8);
        break;
      case '9':
        transmit(tv_num_9);
        break;
      default:
        return -1;
    }
  }
  return 0;
}

int postSource(String command){
  switch (command[0]) {
    case '1':
      transmit(tv_hdmi_1);
      break;
    case '2':
      transmit(tv_hdmi_2);
      break;
    case '3':
      transmit(tv_hdmi_3);
      break;
    default:
      return -1;
  }
  return 0;
}

int postChannel(String command){
  switch (command[0]) {
    case 'u':
      transmit(tv_channel_up);
      break;
    case 'd':
      transmit(tv_channel_down);
      break;
    default:
      return -1;
  }
  return 0;
}

int postVolume(String command){
  switch (command[0]) {
    case 'u':
      transmit(tv_volume_up);
      break;
    case 'd':
      transmit(tv_volume_down);
      break;
    default:
      return -1;
  }
  return 0;
}

int postMute(String command){
  switch (command[0]) {
    case '0':
      transmit(tv_mute_off);
      break;
    case '1':
      transmit(tv_mute_on);
      break;
    default:
      return -1;
  }
  return 0;
}

int postDir(String command){
  switch (command[0]) {
    case 'u':
      transmit(tv_up);
      break;
    case 'd':
      transmit(tv_down);
      break;
    case 'l':
      transmit(tv_left);
      break;
    case 'r':
      transmit(tv_right);
      break;
    default:
      return -1;
  }
  return 0;
}

int postMisc(String command){
  switch (command[0]) {
    case '0':
      transmit(tv_ok);
      break;
    case '1':
      transmit(tv_exit);
      break;
    case '2':
      transmit(tv_enter);
      break;
    default:
      return -1;
  }
  return 0;
}

void setup() {
  Particle.function("postPower", postPower);
  Particle.function("postNumber", postNumber);
  Particle.function("postSource", postSource);
  Particle.function("postChannel", postChannel);
  Particle.function("postVolume", postVolume);
  Particle.function("postMute", postMute);
  Particle.function("postDir", postDir);
  Particle.function("postMisc", postMisc);
}
