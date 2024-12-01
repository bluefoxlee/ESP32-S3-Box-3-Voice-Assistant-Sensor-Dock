# ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock

感謝原作者：[AlmostInteractive 的專案](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock)

原本僅是打算解決官方韌體上中文顯示亂碼的問題、轉而使用該專案進行繁體中文版本製作，由於修改的地方較多，因而不使用 PR、而另外製作繁體中文版本。字型於最小字方面採用了[更紗黑體](https://github.com/be5invis/Sarasa-Gothic)混合 Apple Emoji 字型利用 Fontlab 組合以期能同時顯示中文與 Emoji，囿於可能涉及版權問題，因為不做上傳。

此設定將語音助理整合到 S3 Box 3 的感應器底座中，實現對設備上所有可操作和可調整功能的完整 Home Assistant 整合。左上方實體按鈕用於開啟/關閉螢幕（設備仍保持完全運行）。左下方實體按鈕用於重置設備。紅色圓形觸控按鈕用於切換語音助理的靜音狀態。頂部的 MUTE 按鈕會導致語音助理出現無法修復的錯誤，必須重置設備才能修復，因此請勿按下該按鈕。

功能：
  - 語音助理，支援裝置端和 Home Assistant 伺服器的喚醒詞
  - 三種語音助理回應模式：語音、提示音和靜音（可透過設定頁面及紅色圓形按鈕切換）
  - 觸控螢幕
  - 紅外線學習功能
  - 紅外線控制功能
  - 溫度感測器
  - 電池感測器
  - 雷達存在檢測
  - 繁體中文顯示（回應內文與自動斷行、Emoji）
  - 頁面增加時間

注意：此設定及類似設定有時會出現觸控螢幕無法初始化的問題（寫入失敗）。為了解決此問題，我加入了失敗檢測和失敗狀態，設備將在 10 秒後自動重啟，直到觸控螢幕正確初始化為止。在倒數期間按下左上方實體按鈕可取消重啟。

## 狀態頁面
![status](https://github.com/user-attachments/assets/f0ed22d7-45c6-48a1-bc87-98d63579ef2e)


顯示 Wi-Fi 和 Home Assistant 連線狀態、電池電量（若有安裝）、LED 電源狀態和溫度。以可愛的小圖片顯示語音助理的狀態。無可交互操作的功能。


## 紅外線學習頁面
![irlearn](https://github.com/user-attachments/assets/9969706e-e4f9-4138-9e5e-f319589c9bff)


觸碰紅外線插槽按鈕以開始錄製到該插槽。按照螢幕上的提示操作，按下遙控器上的按鈕兩次以學習紅外線代碼。您可以覆蓋現有的紅外線插槽進行重新錄製。


## 紅外線控制頁面
![irblast](https://github.com/user-attachments/assets/4bd6e022-a25d-4441-a511-5852e5a9d5ac)


觸碰紅外線插槽按鈕以發射已學習的紅外線代碼。請注意，根據我的測試，LED 發射器的功率較弱，設備必須在 1.3 米範圍內才能有效接收。


## 語音助理頁面
![va](https://github.com/user-attachments/assets/8fd7fb97-9f39-4ffa-b355-1eb97ff8eb35)


顯示語音助理的完整狀態，包括最後聽到的語音辨識（STT）內容和語音回覆（TTS）。無可交互操作的功能。


## 設定頁面
![settings](https://github.com/user-attachments/assets/6e2cf81b-6b99-45c3-8772-93ed7e3fe57e)


允許切換語音助理揚聲器的靜音狀態（注意：不會阻止語音助理進行聆聽）。可調整揚聲器音量以及待機/螢幕保護延遲時間。


### 資源

https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock

https://github.com/BigBobbas/ESP32-S3-Box3-Custom-ESPHome

https://github.com/esphome/firmware/tree/main/wake-word-voice-assistant

https://github.com/be5invis/Sarasa-Gothic
https://github.com/AlmostInteractive/ESP32-S3-Box3-IR-Blaster-Learning-Example/
