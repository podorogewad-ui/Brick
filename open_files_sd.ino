#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <ST7735_t3.h>
#include <Bounce2.h>
#include <Encoder.h>

// ==========================================
// 1. ВКЛАДКИ СО ЗВУКАМИ
#include "AudioSampleHihat01.h"
#include "AudioSampleHihat02.h"
#include "AudioSampleHihat03.h"
#include "AudioSampleHihat04.h"
#include "AudioSampleHihat05.h"
#include "AudioSampleHihat06.h"
#include "AudioSampleHihat15.h"
#include "AudioSampleHihat16.h"
#include "AudioSampleHihat17.h"
#include "AudioSampleHihat18.h"
#include "AudioSampleHihat19.h"
#include "AudioSampleHihat20.h"
#include "AudioSampleHihat21.h"
#include "AudioSampleHihat22.h"
#include "AudioSampleHihat23.h"
#include "AudioSampleHihat24.h"
#include "AudioSampleHihat25.h"
#include "AudioSampleHihat26.h"
#include "AudioSampleHihat27.h"
#include "AudioSampleHihat28.h"
#include "AudioSampleHihat29.h"
#include "AudioSampleHihat30.h"
#include "AudioSampleHihat31.h"
#include "AudioSampleHihat32.h"

#include "AudioSampleKick01.h"
#include "AudioSampleKick02.h"
#include "AudioSampleKick03.h"
#include "AudioSampleKick04.h"
#include "AudioSampleKick05.h"
#include "AudioSampleKick06.h"
#include "AudioSampleKick07.h"
#include "AudioSampleKick08.h"
#include "AudioSampleKick09.h"
#include "AudioSampleKick10.h"
#include "AudioSampleKick11.h"
#include "AudioSampleKick12.h"
#include "AudioSampleKick13.h"
#include "AudioSampleKick14.h"
#include "AudioSampleKick15.h"

#include "AudioSamplePerc01.h"
#include "AudioSamplePerc02.h"
#include "AudioSamplePerc03.h"
#include "AudioSamplePerc04.h"
#include "AudioSamplePerc05.h"
#include "AudioSamplePerc06.h"
#include "AudioSamplePerc07.h"
#include "AudioSamplePerc08.h"
#include "AudioSamplePerc09.h"
#include "AudioSamplePerc10.h"
#include "AudioSamplePerc11.h"
#include "AudioSamplePerc12.h"
#include "AudioSamplePerc13.h"
#include "AudioSamplePerc14.h"
#include "AudioSamplePerc15.h"

#include "AudioSampleSnare01.h"
#include "AudioSampleSnare02.h"
#include "AudioSampleSnare03.h"
#include "AudioSampleSnare04.h"
#include "AudioSampleSnare05.h"
#include "AudioSampleSnare06.h"
#include "AudioSampleSnare07.h"
#include "AudioSampleSnare08.h"
#include "AudioSampleSnare09.h"
#include "AudioSampleSnare10.h"
#include "AudioSampleSnare11.h"
#include "AudioSampleSnare12.h"
#include "AudioSampleSnare13.h"
#include "AudioSampleSnare14.h"
#include "AudioSampleSnare15.h"

#include "AudioSampleTom01.h"
#include "AudioSampleTom02.h"
#include "AudioSampleTom03.h"
#include "AudioSampleTom04.h"
#include "AudioSampleTom05.h"
#include "AudioSampleTom06.h"
#include "AudioSampleTom07.h"
#include "AudioSampleTom08.h"
#include "AudioSampleTom09.h"
#include "AudioSampleTom10.h"
#include "AudioSampleTom11.h"
#include "AudioSampleTom12.h"
#include "AudioSampleTom13.h"
#include "AudioSampleTom14.h"
#include "AudioSampleTom15.h"
#include "AudioSampleTom16.h"

// ==========================================
// #include "AudioSampleKick01.h"

// ==========================================
// 2. БАНКИ ЗВУКОВ (Заполни своими!)
// ==========================================

const unsigned int* bank_HIHAT[] = {
  AudioSampleHihat01, AudioSampleHihat02, AudioSampleHihat03, AudioSampleHihat04, AudioSampleHihat05, AudioSampleHihat06,
  AudioSampleHihat15, AudioSampleHihat16, AudioSampleHihat17, AudioSampleHihat18, AudioSampleHihat19, AudioSampleHihat20,
  AudioSampleHihat21, AudioSampleHihat22, AudioSampleHihat23, AudioSampleHihat24, AudioSampleHihat25, AudioSampleHihat26,
  AudioSampleHihat27, AudioSampleHihat28, AudioSampleHihat29, AudioSampleHihat30, AudioSampleHihat31, AudioSampleHihat32};

const unsigned int* bank_KICK[] = {
  AudioSampleKick01, AudioSampleKick02, AudioSampleKick03, AudioSampleKick04, AudioSampleKick05, AudioSampleKick06,
  AudioSampleKick07, AudioSampleKick08, AudioSampleKick09, AudioSampleKick10, AudioSampleKick11, AudioSampleKick12,
  AudioSampleKick13, AudioSampleKick14, AudioSampleKick15};

const unsigned int* bank_PERC[] = {
  AudioSamplePerc01, AudioSamplePerc02, AudioSamplePerc03, AudioSamplePerc04, AudioSamplePerc05, AudioSamplePerc06,
  AudioSamplePerc07, AudioSamplePerc08, AudioSamplePerc09, AudioSamplePerc10, AudioSamplePerc11, AudioSamplePerc12,
  AudioSamplePerc13, AudioSamplePerc14, AudioSamplePerc15};

const unsigned int* bank_SNARE[] = {
  AudioSampleSnare01, AudioSampleSnare02, AudioSampleSnare03, AudioSampleSnare04, AudioSampleSnare05, AudioSampleSnare06,
  AudioSampleSnare07, AudioSampleSnare08, AudioSampleSnare09, AudioSampleSnare10, AudioSampleSnare11, AudioSampleSnare12,
  AudioSampleSnare13, AudioSampleSnare14, AudioSampleSnare15};

const unsigned int* bank_TOM[] = {
  AudioSampleTom01, AudioSampleTom02, AudioSampleTom03, AudioSampleTom04, AudioSampleTom05, AudioSampleTom06,
  AudioSampleTom07, AudioSampleTom08, AudioSampleTom09, AudioSampleTom10, AudioSampleTom11, AudioSampleTom12,
  AudioSampleTom13, AudioSampleTom14, AudioSampleTom15, AudioSampleTom16};
// ==========================================
// 3. ОБЪЕКТЫ АУДИО (Optimized for Design Tool ++)
// ==========================================
AudioPlaySdRaw           playSd[3];       
AudioPlayMemory          playMem[5];      
AudioSynthWaveform       synths[3];       
AudioEffectEnvelope      env[8]; // Оставили только для коротких звуков и синтов        
AudioMixer4              mixers[4];       
AudioFilterStateVariable filter;    
AudioEffectBitcrusher    bitcrusher; 
AudioOutputI2S           i2s;
AudioControlSGTL5000     sgtl;

// --- МАРШРУТИЗАЦИЯ ---
// Длинные SD файлы идут НАПРЯМУЮ в микшеры (без огибающих), чтобы играть до конца!
AudioConnection c0(playSd[0], 0, mixers[0], 0);  // TR: ATMO
AudioConnection c3(playSd[1], 0, mixers[0], 3);  // TR: LOOP
AudioConnection c7(playSd[2], 0, mixers[1], 3);  // TR: VOI

// Короткие семплы и синты идут через огибающие (Envelopes)
AudioConnection c1(playMem[0], env[0]); AudioConnection c2(playMem[1], env[1]);
AudioConnection c4(playMem[2], env[2]); AudioConnection c5(playMem[3], env[3]);
AudioConnection c6(playMem[4], env[4]); AudioConnection c8(synths[0], env[5]); 
AudioConnection c9(synths[1], env[6]);  AudioConnection c10(synths[2], env[7]);

AudioConnection m1(env[0], 0, mixers[0], 1); AudioConnection m2(env[1], 0, mixers[0], 2);
AudioConnection m4(env[2], 0, mixers[1], 0); AudioConnection m5(env[3], 0, mixers[1], 1);
AudioConnection m6(env[4], 0, mixers[1], 2); 
AudioConnection m8(env[5], 0, mixers[2], 0); AudioConnection m9(env[6], 0, mixers[2], 1);
AudioConnection m10(env[7], 0, mixers[2], 2);

// Сведение микшеров в Мастер (mixers[3])
AudioConnection mFinal1(mixers[0], 0, mixers[3], 0);
AudioConnection mFinal2(mixers[1], 0, mixers[3], 1);
AudioConnection mFinal3(mixers[2], 0, mixers[3], 2);

// Мастер шина эффектов: Микшер -> Фильтр -> Биткрашер -> Выход
AudioConnection eff1(mixers[3], 0, filter, 0); 
AudioConnection eff2(filter, 0, bitcrusher, 0);
AudioConnection outL(bitcrusher, 0, i2s, 0);
AudioConnection outR(bitcrusher, 0, i2s, 1);

// Массивы для управления микшерами (чтобы пот 1 знал, где крутить громкость)
AudioMixer4* trackMixers[11] = {&mixers[0], &mixers[0], &mixers[0], &mixers[0], &mixers[1], &mixers[1], &mixers[1], &mixers[1], &mixers[2], &mixers[2], &mixers[2]};
int trackChannels[11] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
int trackEnv[11] = {-1, 0, 1, -1, 2, 3, 4, -1, 5, 6, 7}; // -1 для прямых SD треков

// ==========================================
// 4. ЖЕЛЕЗО И ДАННЫЕ
// ==========================================
ST7735_t3 tft = ST7735_t3(32, 17, 9);

Encoder encSamples(0, 1); // Выбор семпла
Encoder encBPM(2, 3);     // Выбор BPM (Новые пины)

Bounce selBtn = Bounce();   // Funk / Выбор трека (пин 5)
Bounce muteBtn = Bounce();  // MUTE (пин 26)
Bounce clearBtn = Bounce(); // Clear (пин 27)
Bounce pageBtn = Bounce();  // Page (пин 25)

// Кнопки шагов (заменили 38 на 4, 39 ушла на funk, так что используем 28-31 и 4,37,36,35)
const int btnPins[] = {28, 29, 30, 31, 4, 37, 36, 35}; 
Bounce buttons[8];

int bpm = 120; 
int currentStep = 0; 
int currentTrack = 2;
bool stepPage = 0; 
int8_t sequence[11][16]; 
uint32_t stepMillis = 0;

// Данные о треках
int selectedSample[11] = {0};
float trackVolumes[11] = {0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7};
bool trackMutes[11] = {false};
int bankSizes[11] = {10, 24, 15, 10, 15, 15, 16, 10, 1, 1, 1};

int lastPot1 = 0, lastPot2 = 0, lastPot3 = 0; // Для сглаживания крутилок

enum TrackType { T_SD, T_MEM, T_SYN };
struct TrackInfo { TrackType type; const char* name; int subIdx; };
TrackInfo tracks[11] = {
  {T_SD,  "ATMO",  0}, {T_MEM, "HIHAT", 0}, {T_MEM, "KICK",  1},
  {T_SD,  "LOOP",  1}, {T_MEM, "PERC",  2}, {T_MEM, "SNARE", 3},
  {T_MEM, "TOM",   4}, {T_SD,  "VOI",   2}, {T_SYN, "PIANO", 0},
  {T_SYN, "PLUCK", 1}, {T_SYN, "SYNTH", 2}
};

// ==========================================
// 5. ФУНКЦИИ
// ==========================================
void applyVolume(int t) {
  if (trackMutes[t]) trackMixers[t]->gain(trackChannels[t], 0.0);
  else trackMixers[t]->gain(trackChannels[t], trackVolumes[t]);
}

const unsigned int* getSample(int t, int s) {
  if (s < 0) s = 0;
  if (t == 1) return bank_HIHAT[s];
  if (t == 2) return bank_KICK[s];
  if (t == 4) return bank_PERC[s];
  if (t == 5) return bank_SNARE[s];
  if (t == 6) return bank_TOM[s];
  return NULL;
}

void playSound(int t, int note) {
  if (trackMutes[t]) return; // Не проигрываем, если замьютировано

  int idx = tracks[t].subIdx;
  int sIdx = selectedSample[t];

  if (tracks[t].type == T_SD) {
    char path[32];
    sprintf(path, "%s/%s-%02d.raw", tracks[t].name, tracks[t].name, sIdx + 1);
    if (playSd[idx].isPlaying()) playSd[idx].stop(); // Перезапуск, если файл уже играет
    playSd[idx].play(path);
  } 
  else if (tracks[t].type == T_MEM) {
    const unsigned int* samplePtr = getSample(t, sIdx);
    if (samplePtr != NULL) playMem[idx].play(samplePtr);
  } 
  else if (tracks[t].type == T_SYN) {
    float freq = 130.81 * pow(1.059463, note); 
    synths[idx].frequency(freq);
    synths[idx].amplitude(0.8);
  }
  
  // Открываем звук для коротких (SD длинные играют сами)
  if (trackEnv[t] != -1) env[trackEnv[t]].noteOn(); 
}

void drawGrid() {
  for(int i=0; i<16; i++) {
    int x = 10 + (i % 8) * 18;
    int y = (i < 8) ? 45 : 75;
    bool isActivePage = (stepPage == (i >= 8));
    uint16_t color = isActivePage ? ST7735_WHITE : 0x4208;
    if (sequence[currentTrack][i] != -1) tft.fillRect(x, y, 14, 20, ST7735_GREEN);
    else { tft.fillRect(x, y, 14, 20, ST7735_BLACK); tft.drawRect(x, y, 14, 20, color); }
    
    if (i == currentStep) tft.fillRect(x, y + 22, 14, 3, ST7735_RED);
    else tft.fillRect(x, y + 22, 14, 3, ST7735_BLACK);
  }
}

void updateFullUI() {
  tft.fillScreen(ST7735_BLACK);
  tft.fillRect(0, 0, 160, 20, 0x000F);
  tft.setTextColor(ST7735_CYAN); tft.setCursor(5, 5); 
  tft.printf("TR:%s S:%02d", tracks[currentTrack].name, selectedSample[currentTrack]+1);
  
  tft.setTextColor(ST7735_YELLOW); tft.setCursor(110, 5); tft.printf("B:%d", bpm);
  
  // Строка статуса (Громкость и Мьют)
  tft.setTextColor(ST7735_WHITE); tft.setCursor(5, 25);
  tft.fillRect(0, 25, 160, 15, ST7735_BLACK);
  tft.printf("VOL: %d%% %s", (int)(trackVolumes[currentTrack] * 100), trackMutes[currentTrack] ? "[MUTE]" : "");

  tft.setTextColor(ST7735_MAGENTA); tft.setCursor(5, 110); tft.printf("PAGE: %s", stepPage ? "9-16" : "1-8");
  drawGrid();
}

// ==========================================
// 6. SETUP
// ==========================================
void setup() {
  AudioMemory(600); // 600 блоков = ~1.7 секунды буфера, SD не будет заикаться!
  sgtl.enable();
  sgtl.volume(0.7);

  for(int i=0; i<3; i++) synths[i].begin(0.0, 440.0, WAVEFORM_SQUARE);

  for(int i=0; i<8; i++) {
    env[i].attack(2);
    env[i].hold(50);
    env[i].decay(350); 
    env[i].sustain(0.0);
    env[i].release(50);
  }

  for(int i=0; i<11; i++) applyVolume(i); // Применяем начальную громкость
  
  filter.frequency(15000); 
  bitcrusher.bits(16);
  bitcrusher.sampleRate(44100);

  tft.initR(INITR_BLACKTAB); tft.setRotation(1); tft.fillScreen(ST7735_BLACK);
  SD.begin(BUILTIN_SDCARD);
  
  selBtn.attach(5, INPUT_PULLUP); selBtn.interval(25);   // Funk/Track Select
  muteBtn.attach(26, INPUT_PULLUP); muteBtn.interval(25); // MUTE
  clearBtn.attach(27, INPUT_PULLUP); clearBtn.interval(25); 
  pageBtn.attach(25, INPUT_PULLUP); pageBtn.interval(25);

  for(int i=0; i<8; i++) { 
    buttons[i].attach(btnPins[i], INPUT_PULLUP); 
    buttons[i].interval(25); 
  }
  
  for(int i=0; i<11; i++) for(int s=0; s<16; s++) sequence[i][s] = -1;
  updateFullUI();
}

// ==========================================
// 7. MAIN LOOP
// ==========================================
void loop() {
  selBtn.update(); muteBtn.update(); clearBtn.update(); pageBtn.update();
  bool isFunk = (digitalRead(5) == LOW);

  if (pageBtn.fell()) { stepPage = !stepPage; updateFullUI(); }
  if (clearBtn.fell()) { for(int s=0; s<16; s++) sequence[currentTrack][s] = -1; updateFullUI(); }
  
  if (muteBtn.fell()) { 
    trackMutes[currentTrack] = !trackMutes[currentTrack]; 
    applyVolume(currentTrack);
    updateFullUI(); 
  }

  uint32_t stepInterval = 60000 / bpm / 4;
  if (millis() - stepMillis >= stepInterval) {
    stepMillis = millis();
    currentStep = (currentStep + 1) % 16;
    for (int t=0; t<11; t++) {
      if (sequence[t][currentStep] != -1) playSound(t, sequence[t][currentStep]);
    }
    drawGrid();
  }

  for (int i=0; i<8; i++) {
    buttons[i].update();
    if (buttons[i].fell()) {
      if (isFunk) { 
        currentTrack = (i < 11) ? i : currentTrack; 
        updateFullUI(); 
      } else {
        int s = stepPage ? i+8 : i;
        if (sequence[currentTrack][s] != -1) sequence[currentTrack][s] = -1;
        else { sequence[currentTrack][s] = s; playSound(currentTrack, s); }
        drawGrid();
      }
    }
  }

  // Энкодер 1
  long newSmpPos = encSamples.read() / 4;
  static long oldSmpPos = 0;
  if (newSmpPos != oldSmpPos) {
    selectedSample[currentTrack] += (newSmpPos > oldSmpPos) ? 1 : -1;
    selectedSample[currentTrack] = constrain(selectedSample[currentTrack], 0, bankSizes[currentTrack]-1);
    oldSmpPos = newSmpPos;
    updateFullUI();
  }

  // Энкодер 2
  long newBpmPos = encBPM.read() / 4;
  static long oldBpmPos = 0;
  if (newBpmPos != oldBpmPos) {
    bpm += (newBpmPos > oldBpmPos) ? 1 : -1;
    bpm = constrain(bpm, 40, 300);
    oldBpmPos = newBpmPos;
    tft.fillRect(110, 0, 50, 20, 0x000F);
    tft.setCursor(110, 5); tft.setTextColor(ST7735_YELLOW);
    tft.printf("B:%d", bpm);
  }

  // --- ПОТЕНЦИОМЕТРЫ (Обработка крутилок 14, 15, 16) ---
  
  // Пот 1: Громкость ТЕКУЩЕГО трека
  int p1 = analogRead(14);
  if (abs(p1 - lastPot1) > 10) { // Защита от дребезга АЦП
    lastPot1 = p1;
    trackVolumes[currentTrack] = (float)p1 / 1023.0; // от 0.0 до 1.0
    applyVolume(currentTrack);
    // Обновляем текст громкости на экране
    tft.fillRect(0, 25, 160, 15, ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE); tft.setCursor(5, 25);
    tft.printf("VOL: %d%% %s", (int)(trackVolumes[currentTrack] * 100), trackMutes[currentTrack] ? "[MUTE]" : "");
  }

  // Пот 2: Фильтр (Low Pass)
  int p2 = analogRead(15);
  if (abs(p2 - lastPot2) > 10) {
    lastPot2 = p2;
    float freq = map(p2, 0, 1023, 100, 15000); // От 100Hz до 15000Hz
    filter.frequency(freq);
  }

  // Пот 3: Биткрашер (Эффект грязи/винила)
  int p3 = analogRead(16);
  if (abs(p3 - lastPot3) > 10) {
    lastPot3 = p3;
    int bits = map(p3, 0, 1023, 4, 16); // От 4 бит (шум) до 16 бит (чисто)
    int sRate = map(p3, 0, 1023, 4000, 44100); 
    bitcrusher.bits(bits);
    bitcrusher.sampleRate(sRate);
  }
}