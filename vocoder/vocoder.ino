/****************************************************************
 * 19-Channel Vocoder                                           *
 ****************************************************************
 * Left input is voice input                                    *
 * Right input is instrument/synth input                        *
 * Input is both in I2S and USB, with programmable gain         *
 * Output is both in I2S and USB                                *
 ****************************************************************
 * My 37-channel Vocoder does not work, all I heard was noise.  *
 * I didn't have an Audio Shield, I used UDA1345TS 24bit Codec  *
 * for I2S testing. Note, the code is a bit long (768 lines),   *
 * but it is commented for you to understand its functions.     *
 ****************************************************************
 * Testing Parameters                                           *
 *  • Hardware: Teensy 3.6                                      *
 *  • Teensyduino Version: 1.35                                 *
 *  • USB Type: Serial + MIDI + Audio                           *
 *  • CPU Speed: 240 MHz (overclock)                            *
 *  • Optimize: Faster                                          *
 *  • Audio Input: USB (routed to MP3 player)                   *
 *  • Audio Output: USB (routed to headphone out)               *
 *  • Processor Usage Max = 69.84                               *
 *  • Memory Usage Max = 31                                     *
 * Using lower CPU speeds is possible, down to 168 MHz but you  *
 * need to adjust attack parameter (line 295).                  *
 * Memory usage isn't affected by CPU speed.                    *
 ****************************************************************
 * Coded by Revalogics                                          *
 ****************************************************************/

#include <Audio.h>                                              // no libraries were harmed (modified)
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=171,527
AudioInputUSB            usb1;           //xy=171,559
AudioMixer4              mixer1;         //xy=315,510
AudioMixer4              mixer2;         //xy=315,572
AudioFilterStateVariable filter39;       //xy=481,645
AudioFilterStateVariable filter41;       //xy=481,691
AudioFilterStateVariable filter43;       //xy=481,736
AudioFilterStateVariable filter45;       //xy=481,782
AudioFilterStateVariable filter47;       //xy=481,828
AudioFilterStateVariable filter49;       //xy=481,874
AudioFilterStateVariable filter51;       //xy=481,920
AudioFilterStateVariable filter1;        //xy=488,112
AudioFilterStateVariable filter3;        //xy=488,158
AudioFilterStateVariable filter5;        //xy=488,203
AudioFilterStateVariable filter7;        //xy=488,249
AudioFilterStateVariable filter9;        //xy=488,295
AudioFilterStateVariable filter11;       //xy=488,341
AudioFilterStateVariable filter13;       //xy=488,387
AudioAnalyzePeak         peak20;         //xy=546,513
AudioAnalyzePeak         peak21;         //xy=546,552
AudioFilterStateVariable filter40;       //xy=620,644
AudioFilterStateVariable filter42;       //xy=620,690
AudioFilterStateVariable filter44;       //xy=620,735
AudioFilterStateVariable filter46;       //xy=620,781
AudioFilterStateVariable filter48;       //xy=620,827
AudioFilterStateVariable filter50;       //xy=620,873
AudioFilterStateVariable filter52;       //xy=620,919
AudioFilterStateVariable filter2;        //xy=627,111
AudioFilterStateVariable filter4;        //xy=627,157
AudioFilterStateVariable filter6;        //xy=627,202
AudioFilterStateVariable filter8;        //xy=627,248
AudioFilterStateVariable filter10;       //xy=627,294
AudioFilterStateVariable filter12;       //xy=627,340
AudioFilterStateVariable filter14;       //xy=627,386
AudioAnalyzePeak         peak7;          //xy=770,386
AudioAnalyzePeak         peak3;          //xy=771,202
AudioAnalyzePeak         peak4;          //xy=771,248
AudioAnalyzePeak         peak5;          //xy=771,295
AudioAnalyzePeak         peak6;          //xy=771,340
AudioAnalyzePeak         peak1;          //xy=772,110
AudioAnalyzePeak         peak2;          //xy=772,157
AudioMixer4              mixer3;         //xy=853,1023
AudioMixer4              mixer4;         //xy=854,1085
AudioFilterStateVariable filter53;       //xy=913,643
AudioFilterStateVariable filter55;       //xy=913,689
AudioFilterStateVariable filter57;       //xy=913,734
AudioFilterStateVariable filter59;       //xy=913,780
AudioFilterStateVariable filter61;       //xy=913,826
AudioFilterStateVariable filter63;       //xy=913,872
AudioFilterStateVariable filter65;       //xy=913,918
AudioFilterStateVariable filter15;       //xy=920,110
AudioFilterStateVariable filter17;       //xy=920,156
AudioFilterStateVariable filter19;       //xy=920,201
AudioFilterStateVariable filter21;       //xy=920,247
AudioFilterStateVariable filter23;       //xy=920,293
AudioFilterStateVariable filter25;       //xy=920,339
AudioFilterStateVariable filter27;       //xy=920,385
AudioFilterStateVariable filter54;       //xy=1052,642
AudioFilterStateVariable filter56;       //xy=1052,688
AudioFilterStateVariable filter58;       //xy=1052,733
AudioFilterStateVariable filter60;       //xy=1052,779
AudioFilterStateVariable filter62;       //xy=1052,825
AudioFilterStateVariable filter64;       //xy=1052,871
AudioFilterStateVariable filter66;       //xy=1052,917
AudioFilterStateVariable filter16;       //xy=1059,109
AudioFilterStateVariable filter18;       //xy=1059,155
AudioFilterStateVariable filter20;       //xy=1059,200
AudioFilterStateVariable filter22;       //xy=1059,246
AudioFilterStateVariable filter24;       //xy=1059,292
AudioFilterStateVariable filter26;       //xy=1059,338
AudioFilterStateVariable filter28;       //xy=1059,384
AudioSynthNoiseWhite     noise1;         //xy=1189,526
AudioAnalyzePeak         peak14;         //xy=1202,384
AudioAnalyzePeak         peak10;         //xy=1203,200
AudioAnalyzePeak         peak11;         //xy=1203,246
AudioAnalyzePeak         peak12;         //xy=1203,293
AudioAnalyzePeak         peak13;         //xy=1203,338
AudioAnalyzePeak         peak8;          //xy=1204,109
AudioAnalyzePeak         peak9;          //xy=1204,155
AudioMixer4              mixer5;         //xy=1317,1025
AudioMixer4              mixer6;         //xy=1318,1087
AudioFilterStateVariable filter67;       //xy=1350,641
AudioFilterStateVariable filter69;       //xy=1350,687
AudioFilterStateVariable filter71;       //xy=1350,732
AudioFilterStateVariable filter73;       //xy=1350,778
AudioFilterStateVariable filter75;       //xy=1350,824
AudioFilterStateVariable filter77;       //xy=1350,870
AudioFilterStateVariable filter29;       //xy=1356,107
AudioFilterStateVariable filter31;       //xy=1356,153
AudioFilterStateVariable filter33;       //xy=1356,198
AudioFilterStateVariable filter35;       //xy=1356,244
AudioFilterStateVariable filter37;       //xy=1356,290
AudioFilterStateVariable filter68;       //xy=1489,640
AudioFilterStateVariable filter70;       //xy=1489,686
AudioFilterStateVariable filter72;       //xy=1489,731
AudioFilterStateVariable filter74;       //xy=1489,777
AudioFilterStateVariable filter76;       //xy=1489,823
AudioFilterStateVariable filter78;       //xy=1489,869
AudioFilterStateVariable filter30;       //xy=1495,106
AudioFilterStateVariable filter32;       //xy=1495,152
AudioFilterStateVariable filter34;       //xy=1495,197
AudioFilterStateVariable filter36;       //xy=1495,243
AudioFilterStateVariable filter38;       //xy=1495,289
AudioAnalyzePeak         peak17;         //xy=1639,197
AudioAnalyzePeak         peak18;         //xy=1639,243
AudioAnalyzePeak         peak19;         //xy=1639,290
AudioAnalyzePeak         peak15;         //xy=1640,106
AudioAnalyzePeak         peak16;         //xy=1640,152
AudioMixer4              mixer9;         //xy=1639,1023
AudioMixer4              mixer10;        //xy=1641,1085
AudioMixer4              mixer7;         //xy=1694,728
AudioMixer4              mixer8;         //xy=1695,791
AudioMixer4              mixer11;        //xy=1803,1050
AudioAnalyzePeak         peak22;         //xy=1961,991
AudioOutputI2S           i2s2;           //xy=1965,1033
AudioOutputUSB           usb2;           //xy=1965,1064
AudioConnection          patchCord1(i2s1, 0, mixer1, 0);
AudioConnection          patchCord2(i2s1, 1, mixer2, 0);
AudioConnection          patchCord3(usb1, 0, mixer1, 1);
AudioConnection          patchCord4(usb1, 1, mixer2, 1);
AudioConnection          patchCord5(mixer1, 0, filter1, 0);
AudioConnection          patchCord6(mixer1, 0, filter3, 0);
AudioConnection          patchCord7(mixer1, 0, filter5, 0);
AudioConnection          patchCord8(mixer1, 0, filter7, 0);
AudioConnection          patchCord9(mixer1, 0, filter9, 0);
AudioConnection          patchCord10(mixer1, 0, filter11, 0);
AudioConnection          patchCord11(mixer1, 0, filter13, 0);
AudioConnection          patchCord12(mixer1, 0, filter15, 0);
AudioConnection          patchCord13(mixer1, 0, filter17, 0);
AudioConnection          patchCord14(mixer1, 0, filter19, 0);
AudioConnection          patchCord15(mixer1, 0, filter21, 0);
AudioConnection          patchCord16(mixer1, 0, filter23, 0);
AudioConnection          patchCord17(mixer1, 0, filter25, 0);
AudioConnection          patchCord18(mixer1, 0, filter27, 0);
AudioConnection          patchCord19(mixer1, 0, filter29, 0);
AudioConnection          patchCord20(mixer1, 0, filter31, 0);
AudioConnection          patchCord21(mixer1, 0, filter33, 0);
AudioConnection          patchCord22(mixer1, 0, filter35, 0);
AudioConnection          patchCord23(mixer1, 0, filter37, 0);
AudioConnection          patchCord24(mixer1, peak20);
AudioConnection          patchCord25(mixer2, 0, filter39, 0);
AudioConnection          patchCord26(mixer2, 0, filter41, 0);
AudioConnection          patchCord27(mixer2, 0, filter43, 0);
AudioConnection          patchCord28(mixer2, 0, filter45, 0);
AudioConnection          patchCord29(mixer2, 0, filter47, 0);
AudioConnection          patchCord30(mixer2, 0, filter49, 0);
AudioConnection          patchCord31(mixer2, 0, filter51, 0);
AudioConnection          patchCord32(mixer2, 0, filter53, 0);
AudioConnection          patchCord33(mixer2, 0, filter55, 0);
AudioConnection          patchCord34(mixer2, 0, filter57, 0);
AudioConnection          patchCord35(mixer2, 0, filter59, 0);
AudioConnection          patchCord36(mixer2, 0, filter61, 0);
AudioConnection          patchCord37(mixer2, 0, filter63, 0);
AudioConnection          patchCord38(mixer2, 0, filter65, 0);
AudioConnection          patchCord39(mixer2, 0, filter67, 0);
AudioConnection          patchCord40(mixer2, 0, filter69, 0);
AudioConnection          patchCord41(mixer2, 0, filter71, 0);
AudioConnection          patchCord42(mixer2, 0, filter73, 0);
AudioConnection          patchCord43(mixer2, 0, filter75, 0);
AudioConnection          patchCord44(mixer2, 0, mixer11, 2);
AudioConnection          patchCord45(mixer2, peak21);
AudioConnection          patchCord46(filter39, 0, filter40, 0);
AudioConnection          patchCord47(filter41, 1, filter42, 0);
AudioConnection          patchCord48(filter43, 1, filter44, 0);
AudioConnection          patchCord49(filter45, 1, filter46, 0);
AudioConnection          patchCord50(filter47, 1, filter48, 0);
AudioConnection          patchCord51(filter49, 1, filter50, 0);
AudioConnection          patchCord52(filter51, 1, filter52, 0);
AudioConnection          patchCord53(filter1, 0, filter2, 0);
AudioConnection          patchCord54(filter3, 1, filter4, 0);
AudioConnection          patchCord55(filter5, 1, filter6, 0);
AudioConnection          patchCord56(filter7, 1, filter8, 0);
AudioConnection          patchCord57(filter9, 1, filter10, 0);
AudioConnection          patchCord58(filter11, 1, filter12, 0);
AudioConnection          patchCord59(filter13, 1, filter14, 0);
AudioConnection          patchCord60(filter40, 0, mixer3, 0);
AudioConnection          patchCord61(filter42, 1, mixer3, 1);
AudioConnection          patchCord62(filter44, 1, mixer3, 2);
AudioConnection          patchCord63(filter46, 1, mixer3, 3);
AudioConnection          patchCord64(filter48, 1, mixer4, 0);
AudioConnection          patchCord65(filter50, 1, mixer4, 1);
AudioConnection          patchCord66(filter52, 1, mixer4, 2);
AudioConnection          patchCord67(filter2, 0, peak1, 0);
AudioConnection          patchCord68(filter4, 1, peak2, 0);
AudioConnection          patchCord69(filter6, 1, peak3, 0);
AudioConnection          patchCord70(filter8, 1, peak4, 0);
AudioConnection          patchCord71(filter10, 1, peak5, 0);
AudioConnection          patchCord72(filter12, 1, peak6, 0);
AudioConnection          patchCord73(filter14, 1, peak7, 0);
AudioConnection          patchCord74(mixer3, 0, mixer9, 0);
AudioConnection          patchCord75(mixer4, 0, mixer9, 1);
AudioConnection          patchCord76(filter53, 1, filter54, 0);
AudioConnection          patchCord77(filter55, 1, filter56, 0);
AudioConnection          patchCord78(filter57, 1, filter58, 0);
AudioConnection          patchCord79(filter59, 1, filter60, 0);
AudioConnection          patchCord80(filter61, 1, filter62, 0);
AudioConnection          patchCord81(filter63, 1, filter64, 0);
AudioConnection          patchCord82(filter65, 1, filter66, 0);
AudioConnection          patchCord83(filter15, 1, filter16, 0);
AudioConnection          patchCord84(filter17, 1, filter18, 0);
AudioConnection          patchCord85(filter19, 1, filter20, 0);
AudioConnection          patchCord86(filter21, 1, filter22, 0);
AudioConnection          patchCord87(filter23, 1, filter24, 0);
AudioConnection          patchCord88(filter25, 1, filter26, 0);
AudioConnection          patchCord89(filter27, 1, filter28, 0);
AudioConnection          patchCord90(filter54, 1, mixer5, 0);
AudioConnection          patchCord91(filter56, 1, mixer5, 1);
AudioConnection          patchCord92(filter58, 1, mixer5, 2);
AudioConnection          patchCord93(filter60, 1, mixer5, 3);
AudioConnection          patchCord94(filter62, 1, mixer6, 0);
AudioConnection          patchCord95(filter64, 1, mixer6, 1);
AudioConnection          patchCord96(filter66, 1, mixer6, 2);
AudioConnection          patchCord97(filter16, 1, peak8, 0);
AudioConnection          patchCord98(filter18, 1, peak9, 0);
AudioConnection          patchCord99(filter20, 1, peak10, 0);
AudioConnection          patchCord100(filter22, 1, peak11, 0);
AudioConnection          patchCord101(filter24, 1, peak12, 0);
AudioConnection          patchCord102(filter26, 1, peak13, 0);
AudioConnection          patchCord103(filter28, 1, peak14, 0);
AudioConnection          patchCord104(noise1, 0, filter77, 0);
AudioConnection          patchCord105(mixer5, 0, mixer9, 2);
AudioConnection          patchCord106(mixer6, 0, mixer9, 3);
AudioConnection          patchCord107(filter67, 1, filter68, 0);
AudioConnection          patchCord108(filter69, 1, filter70, 0);
AudioConnection          patchCord109(filter71, 1, filter72, 0);
AudioConnection          patchCord110(filter73, 1, filter74, 0);
AudioConnection          patchCord111(filter75, 2, filter76, 0);
AudioConnection          patchCord112(filter77, 2, filter78, 0);
AudioConnection          patchCord113(filter29, 1, filter30, 0);
AudioConnection          patchCord114(filter31, 1, filter32, 0);
AudioConnection          patchCord115(filter33, 1, filter34, 0);
AudioConnection          patchCord116(filter35, 1, filter36, 0);
AudioConnection          patchCord117(filter37, 2, filter38, 0);
AudioConnection          patchCord118(filter68, 1, mixer7, 0);
AudioConnection          patchCord119(filter70, 1, mixer7, 1);
AudioConnection          patchCord120(filter72, 1, mixer7, 2);
AudioConnection          patchCord121(filter74, 1, mixer7, 3);
AudioConnection          patchCord122(filter76, 1, mixer8, 0);
AudioConnection          patchCord123(filter78, 1, mixer8, 1);
AudioConnection          patchCord124(filter30, 1, peak15, 0);
AudioConnection          patchCord125(filter32, 1, peak16, 0);
AudioConnection          patchCord126(filter34, 1, peak17, 0);
AudioConnection          patchCord127(filter36, 1, peak18, 0);
AudioConnection          patchCord128(filter38, 2, peak19, 0);
AudioConnection          patchCord129(mixer9, 0, mixer11, 0);
AudioConnection          patchCord130(mixer10, 0, mixer11, 1);
AudioConnection          patchCord131(mixer7, 0, mixer10, 0);
AudioConnection          patchCord132(mixer8, 0, mixer10, 1);
AudioConnection          patchCord133(mixer11, 0, i2s2, 0);
AudioConnection          patchCord134(mixer11, 0, i2s2, 1);
AudioConnection          patchCord135(mixer11, 0, usb2, 0);
AudioConnection          patchCord136(mixer11, 0, usb2, 1);
AudioConnection          patchCord137(mixer11, peak22);
// GUItool: end automatically generated code

elapsedMillis serialtimer;
const float res = 5;                                            // this is used as resonance value of all state variable filters
const float attack = 0.99588;                                   // controls attack and decay, must not exceed or equal 1,
                                                                // going near 1 decreases attack, must be set at a right value to minimize distortion,
                                                                // while still responsive to voice, this parameter is CPU speed dependent
const float threshold = 0.1;                                    // threshold value used to limit sound levels going to mixer used as amplitude
                                                                // modulators
const float freq[37] = {                                        // filter frequency table, tuned to specified musical notes
  110.0000000,  // A2   freq[0]
  123.4708253,  // B2   freq[1]
  138.5913155,  // C#3  freq[2]
  155.5634919,  // D#3  freq[3]
  174.6141157,  // F3   freq[4]
  195.9977180,  // G3   freq[5]
  220.0000000,  // A3   freq[6]
  246.9416506,  // B3   freq[7]
  277.1826310,  // C#4  freq[8]
  311.1269837,  // D#4  freq[9]
  349.2282314,  // F4   freq[10]
  391.9954360,  // G4   freq[11]
  440.0000000,  // A4   freq[12]
  493.8833013,  // B4   freq[13]
  554.3652620,  // C#5  freq[14]
  622.2539674,  // D#5  freq[15]
  698.4564629,  // F5   freq[16]
  783.9908720,  // G5   freq[17]
  880.0000000,  // A5   freq[18]
  987.7666025,  // B5   freq[19]
  1108.730524,  // C#6  freq[20]
  1244.507935,  // D#6  freq[21]
  1396.912926,  // F6   freq[22]
  1567.981744,  // G6   freq[23]
  1760.000000,  // A6   freq[24]
  1975.533205,  // B6   freq[25]
  2217.461048,  // C#7  freq[26]
  2489.015870,  // D#7  freq[27]
  2793.825851,  // F7   freq[28]
  3135.963488,  // G7   freq[29]
  3520.000000,  // A7   freq[30]
  3951.066410,  // B7   freq[31]
  4434.922096,  // C#8  freq[32]
  4978.031740,  // D#8  freq[33]
  5587.651703,  // F8   freq[34]
  6271.926976,  // G8   freq[35]
  7040.000000   // A8   freq[36]
};
float peak1raw, peak2raw, peak3raw, peak4raw, peak5raw, peak6raw,
  peak7raw, peak8raw, peak9raw, peak10raw, peak11raw, peak12raw,
  peak13raw, peak14raw, peak15raw, peak16raw, peak17raw, peak18raw,
  peak19raw;
float peak1val, peak2val, peak3val, peak4val, peak5val, peak6val,
  peak7val, peak8val, peak9val, peak10val, peak11val, peak12val,
  peak13val, peak14val, peak15val, peak16val, peak17val, peak18val,
  peak19val;

void setup() {
  AudioMemory(64);                                              // allocate some memory for audio library
  Serial.begin(115200);                                         // initialize serial communication
  noise1.amplitude(0.7);                                        // controls sibilance (hiss syllables)
  mixer1.gain(0, 0);                                            // I2S left input level
  mixer1.gain(1, 1);                                            // USB left input level
  mixer2.gain(0, 0);                                            // I2S right input level
  mixer2.gain(1, 1);                                            // USB right input level
  mixer11.gain(0, 1);                                           // vocoder output 1 level (low-mid freq)
  mixer11.gain(1, 1);                                           // vocoder output 2 level (high freq)
  mixer11.gain(2, 0);                                           // instrument to output mix level
  
  filter1.resonance(res);                                       // set the resonance of the filters
  filter2.resonance(res);
  filter3.resonance(res);
  filter4.resonance(res);
  filter5.resonance(res);
  filter6.resonance(res);
  filter7.resonance(res);
  filter8.resonance(res);
  filter9.resonance(res);
  filter10.resonance(res);
  filter11.resonance(res);
  filter12.resonance(res);
  filter13.resonance(res);
  filter14.resonance(res);
  filter15.resonance(res);
  filter16.resonance(res);
  filter17.resonance(res);
  filter18.resonance(res);
  filter19.resonance(res);
  filter20.resonance(res);
  filter21.resonance(res);
  filter22.resonance(res);
  filter23.resonance(res);
  filter24.resonance(res);
  filter25.resonance(res);
  filter26.resonance(res);
  filter27.resonance(res);
  filter28.resonance(res);
  filter29.resonance(res);
  filter30.resonance(res);
  filter31.resonance(res);
  filter32.resonance(res);
  filter33.resonance(res);
  filter34.resonance(res);
  filter35.resonance(res);
  filter36.resonance(res);
  filter37.resonance(res);
  filter38.resonance(res);
  filter39.resonance(res);
  filter40.resonance(res);
  filter41.resonance(res);
  filter42.resonance(res);
  filter43.resonance(res);
  filter44.resonance(res);
  filter45.resonance(res);
  filter46.resonance(res);
  filter47.resonance(res);
  filter48.resonance(res);
  filter49.resonance(res);
  filter50.resonance(res);
  filter51.resonance(res);
  filter52.resonance(res);
  filter53.resonance(res);
  filter54.resonance(res);
  filter55.resonance(res);
  filter56.resonance(res);
  filter57.resonance(res);
  filter58.resonance(res);
  filter59.resonance(res);
  filter60.resonance(res);
  filter61.resonance(res);
  filter62.resonance(res);
  filter63.resonance(res);
  filter64.resonance(res);
  filter65.resonance(res);
  filter66.resonance(res);
  filter67.resonance(res);
  filter68.resonance(res);
  filter69.resonance(res);
  filter70.resonance(res);
  filter71.resonance(res);
  filter72.resonance(res);
  filter73.resonance(res);
  filter74.resonance(res);
  filter75.resonance(res);
  filter76.resonance(res);
  filter77.resonance(res);
  filter78.resonance(res);
  
  filter1.frequency(freq[0]);                                   // set the frequencies of the filters
  filter2.frequency(freq[0]);                                   // frequencies are assigned to a pair of filters because they are cascaded
  filter3.frequency(freq[2]);                                   // two sets of filters are used: for voice signal analysis and instrument/synth filter
  filter4.frequency(freq[2]);
  filter5.frequency(freq[4]);
  filter6.frequency(freq[4]);
  filter7.frequency(freq[6]);
  filter8.frequency(freq[6]);
  filter9.frequency(freq[8]);
  filter10.frequency(freq[8]);
  filter11.frequency(freq[10]);
  filter12.frequency(freq[10]);
  filter13.frequency(freq[12]);
  filter14.frequency(freq[12]);
  filter15.frequency(freq[14]);
  filter16.frequency(freq[14]);
  filter17.frequency(freq[16]);
  filter18.frequency(freq[16]);
  filter19.frequency(freq[18]);
  filter20.frequency(freq[18]);
  filter21.frequency(freq[20]);
  filter22.frequency(freq[20]);
  filter23.frequency(freq[22]);
  filter24.frequency(freq[22]);
  filter25.frequency(freq[24]);
  filter26.frequency(freq[24]);
  filter27.frequency(freq[26]);
  filter28.frequency(freq[26]);
  filter29.frequency(freq[28]);
  filter30.frequency(freq[28]);
  filter31.frequency(freq[30]);
  filter32.frequency(freq[30]);
  filter33.frequency(freq[32]);
  filter34.frequency(freq[32]);
  filter35.frequency(freq[34]);
  filter36.frequency(freq[34]);
  filter37.frequency(freq[36]);
  filter38.frequency(freq[36]);
  filter39.frequency(freq[0]);
  filter40.frequency(freq[0]);
  filter41.frequency(freq[2]);
  filter42.frequency(freq[2]);
  filter43.frequency(freq[4]);
  filter44.frequency(freq[4]);
  filter45.frequency(freq[6]);
  filter46.frequency(freq[6]);
  filter47.frequency(freq[8]);
  filter48.frequency(freq[8]);
  filter49.frequency(freq[10]);
  filter50.frequency(freq[10]);
  filter51.frequency(freq[12]);
  filter52.frequency(freq[12]);
  filter53.frequency(freq[14]);
  filter54.frequency(freq[14]);
  filter55.frequency(freq[16]);
  filter56.frequency(freq[16]);
  filter57.frequency(freq[18]);
  filter58.frequency(freq[18]);
  filter59.frequency(freq[20]);
  filter60.frequency(freq[20]);
  filter61.frequency(freq[22]);
  filter62.frequency(freq[22]);
  filter63.frequency(freq[24]);
  filter64.frequency(freq[24]);
  filter65.frequency(freq[26]);
  filter66.frequency(freq[26]);
  filter67.frequency(freq[28]);
  filter68.frequency(freq[28]);
  filter69.frequency(freq[30]);
  filter70.frequency(freq[30]);
  filter71.frequency(freq[32]);
  filter72.frequency(freq[32]);
  filter73.frequency(freq[34]);
  filter74.frequency(freq[34]);
  filter75.frequency(freq[36]);
  filter76.frequency(freq[36]);
  filter77.frequency(freq[36]);                                 // last pair of filters are used for sibilance
  filter78.frequency(freq[36]);                                 // input is a white noise, instead of instrument/synth
  
  peak1val = 1;                                                 // initialize peak values
  peak2val = 1;
  peak3val = 1;
  peak4val = 1;
  peak5val = 1;
  peak6val = 1;
  peak7val = 1;
  peak8val = 1;
  peak9val = 1;
  peak10val = 1;
  peak11val = 1;
  peak12val = 1;
  peak13val = 1;
  peak14val = 1;
  peak15val = 1;
  peak16val = 1;
  peak17val = 1;
  peak18val = 1;
  peak19val = 1;
  
  AudioProcessorUsageMaxReset();                                // and reset these things
  AudioMemoryUsageMaxReset();
}

void loop() {
  if(peak1.available()) {                                       // store peak values at each read
    peak1raw = peak1.read();
  }
  if(peak2.available()) {
    peak2raw = peak2.read();
  }
  if(peak3.available()) {
    peak3raw = peak3.read();
  }
  if(peak4.available()) {
    peak4raw = peak4.read();
  }
  if(peak5.available()) {
    peak5raw = peak5.read();
  }
  if(peak6.available()) {
    peak6raw = peak6.read();
  }
  if(peak7.available()) {
    peak7raw = peak7.read();
  }
  if(peak8.available()) {
    peak8raw = peak8.read();
  }
  if(peak9.available()) {
    peak9raw = peak9.read();
  }
  if(peak10.available()) {
    peak10raw = peak10.read();
  }
  if(peak11.available()) {
    peak11raw = peak11.read();
  }
  if(peak12.available()) {
    peak12raw = peak12.read();
  }
  if(peak13.available()) {
    peak13raw = peak13.read();
  }
  if(peak14.available()) {
    peak14raw = peak14.read();
  }
  if(peak15.available()) {
    peak15raw = peak15.read();
  }
  if(peak16.available()) {
    peak16raw = peak16.read();
  }
  if(peak17.available()) {
    peak17raw = peak17.read();
  }
  if(peak18.available()) {
    peak18raw = peak18.read();
  }
  if(peak19.available()) {
    peak19raw = peak19.read();
  }
  
  if((peak1raw * threshold) > peak1val) {                       // simulate envelope follower: it gets the envelope of the filtered signal through
    peak1val = peak1val / attack;                               // the peak values and is used to determine the direction (increase or decrease) of
    mixer3.gain(0, peak1val);                                   // the mixer gain
  }                                                             // filters won't work here because it is implemented as a sample-and-hold code
  if((peak1raw * threshold) < peak1val) {                       // peak values used to set mixer gain are divided to increase or multiplied to decrease
    peak1val = peak1val * attack;                               // the values must not change fast to avoid distortion
    mixer3.gain(0, peak1val);
  }
  if((peak2raw * threshold) > peak2val) {
    peak2val = peak2val / attack;
    mixer3.gain(1, peak2val);
  }
  if((peak2raw * threshold) < peak2val) {
    peak2val = peak2val * attack;
    mixer3.gain(1, peak2val);
  }
  if((peak3raw * threshold) > peak3val) {
    peak3val = peak3val / attack;
    mixer3.gain(2, peak3val);
  }
  if((peak3raw * threshold) < peak3val) {
    peak3val = peak3val * attack;
    mixer3.gain(2, peak3val);
  }
  if((peak4raw * threshold) > peak4val) {
    peak4val = peak4val / attack;
    mixer3.gain(3, peak4val);
  }
  if((peak4raw * threshold) < peak4val) {
    peak4val = peak4val * attack;
    mixer3.gain(3, peak4val);
  }
  if((peak5raw * threshold) > peak5val) {
    peak5val = peak5val / attack;
    mixer4.gain(0, peak5val);
  }
  if((peak5raw * threshold) < peak5val) {
    peak5val = peak5val * attack;
    mixer4.gain(0, peak5val);
  }
  if((peak6raw * threshold) > peak6val) {
    peak6val = peak6val / attack;
    mixer4.gain(1, peak6val);
  }
  if((peak6raw * threshold) < peak6val) {
    peak6val = peak6val * attack;
    mixer4.gain(1, peak6val);
  }
  if((peak7raw * threshold) > peak7val) {
    peak7val = peak7val / attack;
    mixer4.gain(2, peak7val);
  }
  if((peak7raw * threshold) < peak7val) {
    peak7val = peak7val * attack;
    mixer4.gain(2, peak7val);
  }
  if((peak8raw * threshold) > peak8val) {
    peak8val = peak8val / attack;
    mixer5.gain(0, peak8val);
  }
  if((peak8raw * threshold) < peak8val) {
    peak8val = peak8val * attack;
    mixer5.gain(0, peak8val);
  }
  if((peak9raw * threshold) > peak9val) {
    peak9val = peak9val / attack;
    mixer5.gain(1, peak9val);
  }
  if((peak9raw * threshold) < peak9val) {
    peak9val = peak9val * attack;
    mixer5.gain(1, peak9val);
  }
  if((peak10raw * threshold) > peak10val) {
    peak10val = peak10val / attack;
    mixer5.gain(2, peak10val);
  }
  if((peak10raw * threshold) < peak10val) {
    peak10val = peak10val * attack;
    mixer5.gain(2, peak10val);
  }
  if((peak11raw * threshold) > peak11val) {
    peak11val = peak11val / attack;
    mixer5.gain(3, peak11val);
  }
  if((peak11raw * threshold) < peak11val) {
    peak11val = peak11val * attack;
    mixer5.gain(3, peak11val);
  }
  if((peak12raw * threshold) > peak12val) {
    peak12val = peak12val / attack;
    mixer6.gain(0, peak12val);
  }
  if((peak12raw * threshold) < peak12val) {
    peak12val = peak12val * attack;
    mixer6.gain(0, peak12val);
  }
  if((peak13raw * threshold) > peak13val) {
    peak13val = peak13val / attack;
    mixer6.gain(1, peak13val);
  }
  if((peak13raw * threshold) < peak13val) {
    peak13val = peak13val * attack;
    mixer6.gain(1, peak13val);
  }
  if((peak14raw * threshold) > peak14val) {
    peak14val = peak14val / attack;
    mixer6.gain(2, peak14val);
  }
  if((peak14raw * threshold) < peak14val) {
    peak14val = peak14val * attack;
    mixer6.gain(2, peak14val);
  }
  if((peak15raw * threshold) > peak15val) {
    peak15val = peak15val / attack;
    mixer7.gain(0, peak15val);
  }
  if((peak15raw * threshold) < peak15val) {
    peak15val = peak15val * attack;
    mixer7.gain(0, peak15val);
  }
  if((peak16raw * threshold) > peak16val) {
    peak16val = peak16val / attack;
    mixer7.gain(1, peak16val);
  }
  if((peak16raw * threshold) < peak16val) {
    peak16val = peak16val * attack;
    mixer7.gain(1, peak16val);
  }
  if((peak17raw * threshold) > peak17val) {
    peak17val = peak17val / attack;
    mixer7.gain(2, peak17val);
  }
  if((peak17raw * threshold) < peak17val) {
    peak17val = peak17val * attack;
    mixer7.gain(2, peak17val);
  }
  if((peak18raw * threshold) > peak18val) {
    peak18val = peak18val / attack;
    mixer7.gain(3, peak18val);
  }
  if((peak18raw * threshold) < peak18val) {
    peak18val = peak18val * attack;
    mixer7.gain(3, peak18val);
  }
  if((peak19raw * threshold) > peak19val) {
    peak19val = peak19val / attack;
    mixer8.gain(0, peak19val);
    mixer8.gain(1, peak19val);
  }
  if((peak19raw * threshold) < peak19val) {
    peak19val = peak19val * attack;
    mixer8.gain(0, peak19val);
    mixer8.gain(1, peak19val);
  }
  
  if(serialtimer >= 100) {                                      // and report MCU usage 10x per second
    serialtimer = 0;
    Serial.print("Processor Usage: ");
    Serial.print(AudioProcessorUsage());
    Serial.print("\nProcessor Usage Max: ");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("\nMemory Usage: ");
    Serial.print(AudioMemoryUsage());
    Serial.print("\nMemory Usage Max: ");
    Serial.print(AudioMemoryUsageMax());
    Serial.print("\n\n\n\n\n\n\n\n\n\n");
  }
}
