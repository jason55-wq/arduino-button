// 設定腳位變數
int led_pin = 13;               // LED 接在腳位 13（可直接用板上內建 LED）
int button_pin = 2;             // 按鈕接在腳位 2
int button_state = HIGH;        // 目前按鈕狀態（使用 INPUT_PULLUP 時預設為 HIGH）
int last_button_state = HIGH;   // 上一次讀到的按鈕狀態，用來偵測狀態變化
bool led_state = false;         // 記錄 LED 是否亮著，預設為關

void setup() {
  pinMode(led_pin, OUTPUT);     // 設定 LED 腳位為輸出
  pinMode(button_pin, INPUT_PULLUP); // 使用內建上拉電阻（未按下時為 HIGH，按下時為 LOW）
}

void loop() {
  // 讀取目前按鈕的狀態（HIGH 或 LOW）
  button_state = digitalRead(button_pin);

  // 偵測按鈕從 HIGH → LOW 的瞬間（表示剛被按下）
  if (button_state == LOW && last_button_state == HIGH) {
    led_state = !led_state;     // 反轉 LED 狀態：如果原本是關就開，原本是開就關

    // 根據 led_state 決定是否點亮 LED
    // 如果 led_state 為 true → HIGH（亮燈）
    // 如果 led_state 為 false → LOW（熄滅）
    digitalWrite(led_pin, led_state ? HIGH : LOW);

    delay(50); // 短暫延遲 50ms，防止按鈕彈跳造成多次觸發（去抖動）
  }

  // 將本次的按鈕狀態存起來，供下次比較用
  last_button_state = button_state;
}

