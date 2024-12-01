# ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock

感謝原作者：[AlmostInteractive 的專案](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock)

原本僅是打算解決官方韌體上中文顯示亂碼的問題。

此設定將語音助理整合到 S3 Box 3 的感應器底座中，實現對設備上所有可操作和可調整功能的完整 Home Assistant 整合。左上方實體按鈕用於開啟/關閉螢幕（設備仍保持完全運行）。左下方實體按鈕用於重置設備。紅色圓形觸控按鈕用於切換語音助理的靜音狀態。頂部的 MUTE 按鈕會導致語音助理出現無法修復的錯誤，必須重置設備才能修復，因此請勿按下該按鈕。

功能：
  - 語音助理，支援裝置端和 Home Assistant 伺服器的喚醒詞
  - 三種語音助理回應模式：語音、提示音和靜音（可透過設定頁面及紅色圓形按鈕切換）
  - 觸控螢幕
  - 紅外線學習功能
  - 紅外線發射功能
  - 溫度感測器
  - 電池感測器
  - 雷達存在檢測
  - 繁體中文顯示（回應內文與自動斷行、Emoji）
  - 頁面增加時間

注意：此設定及類似設定有時會出現觸控螢幕無法初始化的問題（寫入失敗）。為了解決此問題，我加入了失敗檢測和失敗狀態，設備將在 10 秒後自動重啟，直到觸控螢幕正確初始化為止。在倒數期間按下左上方實體按鈕可取消重啟。

## Status Page
![status](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock/assets/3893631/946a43e4-8dcf-4b96-9e07-71952494b283)

Shows the status of wifi and HA connections, battery charge (if inserted), LED power, and temperature. Shows cute little pictures to depict the VA status.  Nothing interactable.


## IR Learning Page
![irlearn](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock/assets/3893631/3b4bad68-b882-4eff-b00d-6aa9473ba5f8)

Touch and IR slot button to begin recording to that slot.  Following the on-screen prompts, press the button on your control two times to learn the IR code.  You can record over an existing IR slot.


## IR Blast Page
![irblast](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock/assets/3893631/a58ba5b2-22e0-438e-8a34-bb098f252465)

Touch an IR slot button to emit the learned IR code.  Note that in my testing the LED emitter was weak.  The device had to be within 1.3m before it would register.


## Voice Assistant Page
![va](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock/assets/3893631/8a45eaff-bedb-4afe-9b55-1085c55a8ab7)

Shows the complete status of the Voice Assistant, including last STT phrase it heard and TTS reply.  Nothing interactable.


## Settings Page
![settings](https://github.com/AlmostInteractive/ESP32-S3-Box-3-Voice-Assistant-Sensor-Dock/assets/3893631/026f7ec7-4828-437c-8de9-61765ce20ebd)

Allows toggling the VA speaker mute (NB: does not prevent the VA from listening).  Adjust speaker volume and sleep / screen saver delay.


### Resources

https://github.com/BigBobbas/ESP32-S3-Box3-Custom-ESPHome

https://github.com/esphome/firmware/tree/main/wake-word-voice-assistant

https://github.com/AlmostInteractive/ESP32-S3-Box3-IR-Blaster-Learning-Example/
