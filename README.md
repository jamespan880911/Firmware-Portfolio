# Embedded System & C Programming Practice

這是一個專注於 **嵌入式系統底層開發**、**即時作業系統 (RTOS)** 機制模擬、以及 **C 語言資料結構** 實作的技術倉庫。

本專案記錄了我從底層邏輯（Bitwise, Pointers）到系統架構（ISR, Concurrency）的學習與實作過程。

---

## 🚀 Key Highlights 

### 1. FreeRTOS Wi-Fi Driver/Firmware Simulation
> **⚠️ 註：完整專案代碼位於獨立 Repository，請點擊下方連結前往檢視。**
> 👉 **[前往專案：FreeRTOS-WiFi-Sim](https://github.com/jamespan880911/FreeRTOS-WiFi-Sim)**

模擬 Wi-Fi 晶片驅動程式 (Driver) 與韌體 (Firmware) 之間的非同步通訊模型。
* **核心技術：** FreeRTOS Tasks, Mutex, Counting Semaphores, Software Interrupts.
* **實作細節：**
    * **DMA Ring Buffer**：實作生產者-消費者模型，處理 Driver 與 Firmware 間的高速資料流。
    * **Interrupt Handling**：模擬 Top-half (ISR) 與 Bottom-half (Task) 的中斷處理分工機制。
    * **Concurrency Control**：利用 Mutex 保護 Shared Memory，解決 Race Condition 問題。
    * **Power Management**：實作 Firmware 在 Idle 狀態下的省電模式 (Power Save Mode) 邏輯。

### 2. Smart Aquarium Temperature Controller
> **位置：** `projects/smart_aquarium/`
基於 Arduino 的冷水機溫控系統，專注於硬體保護邏輯與感測器整合。
* **核心技術：** Hysteresis Control, Non-blocking Delay.
* **實作細節：**
    * **遲滯溫控演算法 (Hysteresis)**：設計雙閾值 (High/Low Threshold) 開關邏輯，防止繼電器在臨界溫度頻繁切換 (Chattering)，延長硬體壽命。
    * **延遲散熱保護 (Cool-down Logic)**：實作Non-blocking Delay，在製冷結束後持續運作風扇 120 秒以排除餘熱，且不卡住主迴圈 (Main Loop)。
    * **Sensor Integration**：整合 OneWire 通訊協定讀取 DS18B20 溫度數值。

---

## 📂 Repository Structure (目錄結構)

```text
.
├── algorithms/          # 基礎演算法 (Sorting, Binary Search, Math)
├── data_structures/     # 手刻資料結構 (Linked List, Queue, Stack, Tree)
├── projects/            # 完整的小型系統專案
│   ├── freertos_sim/    # FreeRTOS 驅動模擬
│   └── smart_aquarium/  # 溫控系統實作
├── system_programming/  # 系統程式練習 (Bitwise Ops, Memory, String Utils)
├── leetcode/            # LeetCode 刷題紀錄 (Blind 75)
└── playground/          # 實驗性質程式碼 (Prototypes)
