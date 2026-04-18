// 宣告腳位變數
int led_Pin = 13;      // LED 燈接在腳位 13
int button_Pin = 2;    // 按鈕開關接在腳位 2
int button_state = 0;  // 用來儲存按鈕的目前狀態（HIGH 或 LOW）

void setup() {
  // 設定執行一次的初始化程式

  pinMode(led_Pin, OUTPUT);        // 將 LED 腳位設定為「輸出模式」
  pinMode(button_Pin, INPUT_PULLUP); // 將按鈕腳位設定為「輸入模式」，並啟用內部上拉電阻
  // 上拉電阻的作用是：當按鈕未按下時，腳位會維持在 HIGH 狀態；
  // 當按鈕按下時，腳位會被拉到 LOW 狀態。
}

void loop() {
  // 主程式循環執行（不斷重複執行）

  button_state = digitalRead(button_Pin); // 讀取按鈕目前的狀態（HIGH 或 LOW）

  if (button_state == LOW) {
    // 如果按鈕被按下（LOW）
    digitalWrite(led_Pin, HIGH); // 點亮 LED 燈
  }
  else {
    // 如果按鈕未被按下（HIGH）
    digitalWrite(led_Pin, LOW);  // 關閉 LED 燈
  }
}
